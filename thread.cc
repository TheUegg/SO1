#include "thread.h"
#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include <iostream>

__BEGIN_API

Thread * Thread::_running = nullptr;
unsigned int Thread::_thread_count = 0;

int Thread::switch_context(Thread * prev, Thread * next){        
        if(prev == next) {
            db<Thread>(ERR)<<"Thread::switch_context() - ERRO próximo contexto igual ao contexto atual\n";
            return -1;
        }
        _running = next;

        CPU::switch_context(prev->_context, next->_context);
        return 0;
}

void Thread::thread_exit(int exit_code){
    db<Thread>(TRC)<<"Thread::thread_exit()\n";
    this->_running = NULL;
}


__END_API