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
            Thread::_thread_count--;

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
    }

    //Remove da fila de pronto
    void Thread::dequeue(Thread * thread, Thread::Ready_Queue &queue){
        //remove por meio do link(posição na fila))
		db<Thread>(TRC)<<"Thread::dequeue(Thread * thread, Thread::System_Queue &queue)\n";
		queue.remove(thread->link());
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

    //retorna estate
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
        Thread::yield();
    }

    //destrutor
    Thread::~Thread(){
		db<Thread>(TRC) << "Thread~Thread()\n";
        _ready.remove(this);
		delete _context;
	}

__END_API