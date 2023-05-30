#include "thread.h"
#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include <iostream>

__BEGIN_API

Thread * Thread::_running = NULL;
unsigned int Thread::_thread_count = 0;
Thread Thread::_main; 
CPU::Context Thread::_main_context; 
Thread Thread::_dispatcher;
Thread::Ready_Queue Thread::_ready;
Thread::Suspended_Queue Thread::_suspend;


    //Retorna posição do eleento na fila
    Thread::Ready_Queue::Element* Thread::link(){
        return &_link;
    }

    /*
    Dispatcher, onde controla as threads, colocando-as em execução, ou na fila pronto, 
    e chamando a troca de contexto, após a execução, ele se seta para estado finishing,
    se retira da fila de pronto, e troca o contexto para a main.
    */
    void Thread::dispatcher(){
        db<Thread>(TRC)<<"Thread::dispatcher()\n";
        while(!_ready.empty() && _ready.head()->object() != &_dispatcher) { //enquanto a fila não está vazia e o objeto no início da fila não é o dispatcher

            Thread *next_thread = next(); //escolha uma próxima thread a ser executada
            Thread *prev_thread = _running; //define a thread atual como a thread anterior

            dequeue(next_thread, _ready); //remove a thread em execução da lista de threads prontas

            enqueue(&_dispatcher, _ready); //coloca o dispatcher no fim da fila
            _dispatcher.set_state(READY);  //define o dispatcher como pronto
            switch_context(prev_thread, next_thread); //troca o contexto para próxima thread
        }
        _dispatcher.set_state(FINISHING); //dispatcher finalizando
        dequeue(&_dispatcher, _ready);
        switch_context(&_dispatcher, &_main); //troca o contexto para main, para a finalização do programa
    }

    
    
    //Adiciona thread na fila de prontos.
    void Thread::enqueue(Thread * thread,Thread::Ready_Queue &queue){
	    db<Thread>(TRC)<<"Thread::enqueue(Thread * thread,Thread::System_Queue &queue)\n";
        //Não retorna sem thread
        if(thread == 0)
            return;

        //Insert no inicio da fila se for dispatcher 
        if(thread == &_dispatcher)
            queue.insert_head(thread->link());
        else{
            //Update no tempo do relogio e tempo atual
            thread->update_priority();
            //insert na fila de pronto
            queue.insert(thread->link());
        }

        //seta o estado da thread para READY
        db<Thread>(TRC)<<"Thread::insert_queue: Thread " << thread->id() << " inserida na fila de pronto ";
        if(&queue == &_ready){
            db<Thread>(TRC)<<" _ready\n";
            thread->set_state(READY);
        }
        else if (&queue == &_suspend){
            db<Thread>(TRC)<<" _suspend\n";
            thread->set_state(SUSPENDED);
        }
        else {
            db<Thread>(TRC)<<" _sleeping\n";
            thread->set_state(WAITING);
        }
    }

    //Remove da fila de pronto
    void Thread::dequeue(Thread * thread, Thread::Ready_Queue &queue){
        //remove por meio do link(posição na fila))
		db<Thread>(TRC)<<"Thread::dequeue(Thread * thread, Thread::System_Queue &queue)\n";
		queue.remove(thread->link());
        db<Thread>(TRC)<<"Thread::remove_queue: Thread " << thread->id() << " removida da fila ";
		if(&queue == &_ready)
			db<Thread>(TRC)<<" _ready\n";
		else if (&queue == &_suspend)
			db<Thread>(TRC)<<" _suspend\n";
        else
            db<Thread>(TRC)<<" _sleeping\n";
    }

    //init(setando dispatcher e main)
    void Thread::init(void (*main)(void *)){
		db<Thread>(TRC) << "Thread::init(void (*main)(void *))\n";
        //inicia o contexto da main
		new (&_main_context) Context();
		db<Thread>(TRC) << "Thread::init: Main context criado\n";
        //inicia a thread main
        new (&_main) Thread(main, (void *) "main"); 
		db<Thread>(TRC) << "Thread::init: Main thread criada\n";
		
		dequeue(&_main, _ready);
		_running = &_main;
        //inicia o dispatcher
        new (&_dispatcher) Thread((void (*) (void *)) &Thread::dispatcher, (void *) NULL);

        db<Thread>(TRC) << "Thread::init: Dispatcher thread foi criada\n";	
        //troca de contexto do main
		CPU::switch_context(&_main_context, _main.context());
	}

    int Thread::switch_context(Thread * prev, Thread * next) {
        db<Thread>(TRC)<<"Thread::switch_context()\n";
        if (prev != next) {
            _running = next;
            next->set_state(RUNNING);

            CPU::switch_context(prev->_context, next->_context);
        }
        return 0;
    }
    
    //seta os estados
    void Thread::set_state(Thread::State state){
        db<Thread>(TRC)<<"Thread::set_state(): Thread " << this->id() << " => ";

        switch(state){
            case 0:
                db<Thread>(TRC)<<"RUNNING\n";
                break;
            case 1:
                db<Thread>(TRC)<<"READY\n";
                break;
             case 2:
                db<Thread>(TRC)<<"FINISHING\n";
                break;
            case 3:
                db<Thread>(TRC)<<"SUSPENDED\n";
                break;
        }
        _state = state;
    }
    
    //atualiza prioridade
    void Thread::update_priority(){
		db<Thread>(TRC)<<"Thread::update_priority()\n";
        //prioridade é o tempo entre o epoch (data de início) do relógio e o momento atual
		int now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		link()->rank(now);
		db<Thread>(TRC)<<"Thread::update_priority: Thread " << id() << " prioridade atualizada para " << now << "\n";
    }

    //cede a thread
    void Thread::yield()
    {
		db<Thread>(TRC)<<"Thread::yield()\n";
		Thread *next_thread = next();
		if(next_thread != 0){
			if(_running->state() == RUNNING && _running != &_main) //se ela não estiver finishing e não for a main
				enqueue(_running,_ready); //insere no ready

			dequeue(next_thread, _ready);
			switch_context(_running, next_thread);
		}
	}

    //retorna estado
    Thread::State Thread::state() 
    {
        return _state;
    }

    //retorna a head
    Thread * Thread::next(){
		if(_ready.size() == 0){
			return 0;
		}
		return _ready.head()->object();
	}

    //seta o stado para FINISHING e chama a troca de thread(yield) 
    void Thread::thread_exit(int exit_code) {
        db<Thread>(TRC)<<"Thread::exit()\n";
        set_state(FINISHING);

        this->_exit_code = exit_code;
        //caso a thread deu join, ela vai para running e seta join para 0
        if(this->_joined != 0) {
            this->_joined->resume();
            this->_joined = 0;
        }

        Thread::yield();
    }

    int Thread::join() 
    {
        db<Thread>(TRC)<<"Thread::join()\n";
        //seta o joined da thread como running
        this->_joined = _running;
        //se o estado é finishing retorna o cod
        if(this->state() != FINISHING) {
            //suspend a thread
            suspend();
            //return (this->_exit_code);
        }
        //retorna o cod
        return (this->_exit_code);
    }

    void Thread::resume() 
    {
        db<Thread>(TRC)<<"Thread::resume()\n";
        //retira a thread da fila de suspensas
        dequeue(this, _suspend);
        //seta o state para ready
        this->set_state(READY);
        //troca o contexto da thread que esta rodando com essa
        switch_context(_running, this);
    }

    void Thread::suspend() 
    {
    /*        
        db<Thread>(TRC)<<"Thread::suspend()\n";
		if(this != _running){
            //seta como suspended
            this->set_state(SUSPENDED);
            //tira da fila de pronto
            dequeue(this, _ready);
            //coloca na fila de suspended
            enqueue(this, _suspend);
        }
        else{
    */
            //seta o joined da thread como running
            this->_joined = _running;
            //seta a thread como suspensa
            _running->set_state(SUSPENDED);
            //coloca a thread na fila de suspensas
            enqueue(_running, _suspend);    
            //chama o yield, para trocar a thread para a proxima
            _running->yield();
    //  }
    }

    void Thread::sleep(Sleep_Queue &_sleeping)
    {
		db<Thread>(TRC)<<"Thread::sleep()\n";

		enqueue(_running, _sleeping);
		_running->_sleepOrder = &_sleeping;
		yield();
	}

	void Thread::wakeup(Sleep_Queue &_sleeping)
    {
		db<Thread>(TRC)<<"Thread::wakeup()\n";
		if(_sleeping.size() != 0){
			Thread * thread = _sleeping.head()->object();
			Thread * prev = _running;

			dequeue(thread, _sleeping);
			enqueue(prev, _ready);
			
			thread->_sleepOrder = 0;

			switch_context(prev,thread);
		}
	}

	void Thread::wakeup_all(Sleep_Queue &_sleeping)
    {
		db<Thread>(TRC) << "Thread::wakeup_all()\n";
		Thread * thread = 0;
		while(_sleeping.size() > 0){
			thread = _sleeping.tail()->object();
			dequeue(thread, _sleeping);
			thread->set_state(READY);
			thread->_sleepOrder = 0;
			_ready.insert_head(thread->link());
		}
		yield();
	}

    // Destrutor de uma thread. 
	Thread::~Thread()
    {
		db<Thread>(TRC) << "Thread~Thread()\n";

        _ready.remove(this);

		if(_sleepOrder != 0){
			dequeue(this, *this->_sleepOrder);
		}
		delete _context;
        Thread::_thread_count--;
	}

__END_API