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
        db<Thread>(TRC)<<"Thread()\n";

        //salva o contexto de main
        *_context_main = new Context();
        *_context_main->save();

        //cria o contexto da thread com a função que foi passada
        this->*_context = new Context(entry, an...);
        this->_id = _thread_count;
        _thread_count++;
        _running = &this;
        int switch_status = CPU::switch_context(&_context_main,&this->_context); //passa o controle para a thread criada
        if(switch_status != 0)
            db<Thread>(ERR)<<"Thread() - ERRO ao passar o controle para a nova thread\n";
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
        db<Thread>(TRC)<<"Thread::switch_context()\n";        
        int switch_status = CPU::switch_context(prev->_context, next->_context);
        if(switch_status != 0){
            db<Thread>(ERR)<<"Thread::switch_context() - ERRO no retorno da troca de contexto\n";
            return -1;
        }
        if(prev == next) {
            db<Thread>(ERR)<<"Thread::switch_context() - ERRO próximo contexto igual ao contexto atual\n";
            return -1;
        }
        _running = next;
        return 0;
    }

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main. 
     */  
    void thread_exit (int exit_code){
        db<Thread>(TRC)<<"Thread::thread_exit()\n";
        int switch_status = CPU::switch_context(&this->_context,&_context_main); //devolve o controle para a main
        _running = NULL;
        if(switch_status != 0)
            db<Thread>(ERR)<<"Thread::thread_exit() - ERRO ao devolver o controle ao main";
    }

    /*
     * Retorna o ID da thread.
     */ 
    int id(){
        db<Thread>(TRC)<<"Thread::id()\n";
        return self->_id;
    }

    Context * volatile context(){
        return self->_context;
    }
    
    /*
     * Qualquer outro método que você achar necessário para a solução.
     */ 

private:
    int _id;    
    Context * volatile _context;
    static Thread * _running;

    /*
     * Qualquer outro atributo que você achar necessário para a solução.
     */ 

    static int _thread_count = 0;
    static Context * _context_main;
};

__END_API

#endif
