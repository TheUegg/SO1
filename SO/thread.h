#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include "list.h"
#include <ctime> 
#include <chrono>

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;
public:

    typedef Ordered_List<Thread> Ready_Queue;
    typedef Ordered_List<Thread> Suspended_Queue;
    typedef Ordered_List<Thread> Sleep_Queue;

    // Thread State
    enum State {
        RUNNING,
        READY,
        FINISHING,
        SUSPENDED,
        WAITING
    };

    /*
     * Construtor vazio. Necessário para inicialização, mas sem importância para a execução das Threads.
     */ 
    Thread() { }

    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */ 
    template<typename ... Tn>
    Thread(void (* entry)(Tn ...), Tn ... an);

    /*
     * Retorna a Thread que está em execução.
     */ 
    static Thread * running() { return _running; }

    /*
     * Método para trocar o contexto entre duas thread, a anterior (prev)
     * e a próxima (next).
     * Deve encapsular a chamada para a troca de contexto realizada pela class CPU.
     * Valor de retorno é negativo se houve erro, ou zero.
     */ 
    static int switch_context(Thread * prev, Thread * next);

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main. 
     */  
    void thread_exit (int exit_code);

    /*
     * Retorna o ID da thread.
     */ 
    int id(){
        db<Thread>(TRC)<<"Thread::id()\n";
        return Thread::_id;
    }

    /*
     * NOVO MÉTODO DESTE TRABALHO.
     * Daspachante (disptacher) de threads. 
     * Executa enquanto houverem threads do usuário.
     * Chama o escalonador para definir a próxima tarefa a ser executada.
     */
    static void dispatcher(); 

    /*
     * NOVO MÉTODO DESTE TRABALHO.
     * Realiza a inicialização da class Thread.
     * Cria as Threads main e dispatcher.
     */ 
    static void init(void (*main)(void *));


    /*
     * Devolve o processador para a thread dispatcher que irá escolher outra thread pronta
     * para ser executada.
     */
    static void yield(); 

    /*
     * Destrutor de uma thread. Realiza todo os procedimentos para manter a consistência da classe.
     */ 
    ~Thread();

    /*
     * Qualquer outro método que você achar necessário para a solução.
     */ 

    Context * volatile context(){
        return _context;
    }

    /*
     * Espera a thread esperar a próxima.
     */ 
    int join();

    /*
     * Faz a thread voltar a atividade.
     */ 
    void resume();

    /*
     * Faz a thread parar.
     */ 
    void suspend();

    static void enqueue(Thread * thread, Ready_Queue &queue);

    static void dequeue(Thread * thread, Ready_Queue &queue);

    Ready_Queue::Element * link();

    void set_state(State state);

    State state();

    static Thread * next();

    void update_priority();

    static void sleep(Sleep_Queue &_sleeping);

    static void wakeup(Sleep_Queue &_sleeping);

    static void wakeup_all(Sleep_Queue &_sleeping);

    static void reschedule();


private:
    int _id;
    Context * volatile _context;
    static Thread * _running;
    
    static Thread _main; 
    static CPU::Context _main_context;
    static Thread _dispatcher;
    static Ready_Queue _ready;
    Ready_Queue::Element _link;
    volatile State _state;
    static Suspended_Queue _suspend;
    Thread * _joined = 0;
    static unsigned int _thread_count;
    volatile int _exit_code;
    Sleep_Queue * _sleepOrder;

};

template<typename ... Tn>
inline Thread::Thread(void (* entry)(Tn ...), Tn ... an){

    db<Thread>(TRC)<<"Thread::Thread(void (* entry)(Tn ...), Tn ... an)\n";
    _id = _thread_count;
    _thread_count++;
    _context = new Context(entry, an...);

    new (&_link) Ready_Queue::Element(this,(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()));
    enqueue(this, _ready);

    db<Thread>(INF)<<"Thread::Thread(void (* entry)(Tn ...), Tn ... an): Contador de threads: = " << _thread_count << "\n";
    db<Thread>(TRC)<<"Thread::Thread(void (* entry)(Tn ...), Tn ... an): Thread " << _id << " criada\n";
}

__END_API

#endif
