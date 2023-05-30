#include "semaphore.h"
#include "traits.h"
#include "debug.h"
#include <iostream>

__BEGIN_API

Semaphore::Semaphore(int v)
{
	_v = v;	//salva o valor recebido para inicializar o semáfaro
}

Semaphore::~Semaphore()
{
	wakeup_all(); //ao destruir o semáfaro, libera todas as threads que o semáfaro bloqueava
}

void Semaphore::p(){
	db<Semaphore>(TRC)<<"Semaphore::p()\n";

	if(fdec(_v) < 1){ //se a decrementação atômica resultar em zero ou negativa
		sleep();      //espera até o semáfaro liberar
	}
}

void Semaphore::v(){
    db<Semaphore>(TRC)<<"Semaphore::v()\n";
	if(finc(_v) < 0){ //se a incrementação atômica  for negativa
		wakeup();     //libera a thread
	}	
}

// Atomic operations
//retornar valor anterior
int Semaphore::finc(volatile int & number) {
	db<Semaphore>(INF)<<"Semaphore::finc()\n";
	
	return CPU::xadd(number,1); //incrementação atômica
}

int Semaphore::fdec(volatile int & number) {
	db<Semaphore>(INF)<<"Semaphore::fdec()\n";
	
	return CPU::xadd(number,-1);  //decrementação atômica
}

void Semaphore::sleep()
{
	db<Semaphore>(TRC)<<"Semaphore::sleep()\n";
	Thread::sleep(_sleeping);
}

void Semaphore::wakeup()
{
	db<Semaphore>(TRC)<<"Semaphore::wakeup()\n";
	Thread::wakeup(_sleeping);
}

void Semaphore::wakeup_all()
{
	db<Semaphore>(TRC)<<"Semaphore::wakeup_all()\n";
	Thread::wakeup_all(_sleeping);
}

__END_API