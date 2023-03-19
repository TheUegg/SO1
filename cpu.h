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
                getcontext(&this->_context);
                this->_stack = new char [this->STACK_SIZE];
                this->_context.uc_link = 0;
                this->_context.uc_stack.ss_sp = this->_stack;
                this->_context.uc_stack.ss_size = this->STACK_SIZE; 
                this->_context.uc_stack.ss_flags = 0;
                
                makecontext(&_context, (void (*)())func,(int)sizeof...(an),an...); // TAlvez troque o 0 depois
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

