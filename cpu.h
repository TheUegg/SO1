#ifndef cpu_h
#define cpu_h

#include <ucontext.h>
#include <iostream>
#include "traits.h"

__BEGIN_API

class CPU
{
    public:

        class Context
        {
        private:
            static const unsigned int STACK_SIZE = Traits<CPU>::STACK_SIZE;
        public:
            Context() { _stack = 0; }

            template<typename ... Tn>
            Context(void (* func)(Tn ...), Tn ... an){

                //Seta o tamanho do stack
                _stack = new char [this->STACK_SIZE];


                if(_stack != NULL){
                    //Inicializa o contexto
                    getcontext(&this->_context);
                
                    //Linka o contexto a stack
                    _context.uc_link = 0;
                    _context.uc_stack.ss_sp = _stack;
                    _context.uc_stack.ss_size = this->STACK_SIZE; 
                    _context.uc_stack.ss_flags = 0;
                    
                    //Acopla a função ao contexto
                    makecontext(&_context, (void (*)())func,(int)sizeof...(an),an...);
                }
                else{
                    abort();
                }
            }

            ~Context();

            void save();
            void load();

        private:            
            char *_stack;
        public:
            ucontext_t _context;
        };

    public:

        static int switch_context(Context *from, Context *to);

};

__END_API

#endif

