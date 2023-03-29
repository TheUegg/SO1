#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;

public:
    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */ 
    template<typename ... Tn>
    Thread(void (* entry)(Tn ...), Tn ... an){
        this->_context = new Context(void (* entry)(Tn ...), Tn ... an);
        pthread_t thread = pthread_create(&_running, NULL, void (* entry)(Tn ...), Tn ... an);
        this->_running = &thread;
        pthread_join(_running, NULL);
    }

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
    static int switch_context(Thread * prev, Thread * next){
        this->_running = next;
        CPU::switch_context(prev->_context, next->_context);
    }

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main. 
     */  
    void thread_exit (int exit_code){
        this->_exit_code = exit_code;
        pthread_exit(NULL);
    }

    /*
     * Retorna o ID da thread.
     */ 
    int id(){
        return (int)gettid();
    }

    /*
     * Qualquer outro método que você achar necessário para a solução.
     */ 

private:
    int _id;
    Context * volatile _context;
    static Thread * _running;
    int _exit_code;

    /*
     * Qualquer outro atributo que você achar necessário para a solução.
     */ 
};

__END_API

#endif