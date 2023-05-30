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

int CPU::xadd(volatile int & number, int add){
	int val = add;
	__asm__ __volatile__("lock xadd %0, %2":"=a"(val):"a"(val),"m"(number) : "memory");
	return val;
}

__END_API
