#include "cpu.h"
#include <iostream>

__BEGIN_API

void CPU::Context::save()
{
    //Salva o contexto no ponteiro
    getcontext(&this->_context);
}

void CPU::Context::load()
{
    //Restaura o contexto salvo
    setcontext(&this->_context);
}

CPU::Context::~Context()
{
    //Libera o espaço alocado
    if(_stack != 0 ){
        delete this->_stack;
        _stack = 0;
    }
}

int CPU::switch_context(Context *from, Context *to)
{
    //Troca o contexto usando os parametros como base
    return swapcontext(&from->_context,&to->_context);
    
}

__END_API
