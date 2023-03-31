#include "thread.h"
#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include <iostream>

__BEGIN_API

Thread * Thread::_running = nullptr;
unsigned int Thread::_thread_count = 0;

int Thread::switch_context(Thread * prev, Thread * next){        
        //Testa se o contesto é igual ao atual
        if(prev == next) {
            db<Thread>(ERR)<<"Thread::switch_context() - ERRO próximo contexto igual ao contexto atual\n";
            return -1;
        }

        //Troca a thread que está rodando para a proxima, trocando o contexto em seguida 
        _running = next;
        CPU::switch_context(prev->_context, next->_context);
        return 0;
}

void Thread::thread_exit(int exit_code){
    db<Thread>(TRC)<<"Thread::thread_exit()\n";
    //libera a thread e seu contexto
    this->_running = NULL;
    delete _context;
}


__END_API