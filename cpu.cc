#include "cpu.h"
#include <iostream>

__BEGIN_API

void CPU::Context::save()
{
    //adicionar implementação
    getcontext(&this->_context);
}

void CPU::Context::load()
{
    //adicionar implementação
    setcontext(&this->_context);
}

CPU::Context::~Context()
{
    //adicionar implementação
    //free(this->_stack);
    delete this->_stack;
}

int CPU::switch_context(Context *from, Context *to)
{
    //adicionar implementação
    return swapcontext(&from->_context,&to->_context);
    
}

__END_API
