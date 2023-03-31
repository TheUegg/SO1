#ifndef traits_h
#define traits_h

//Não alterar as 3 declarações abaixo

#define __BEGIN_API             namespace SOLUTION {
#define __END_API               }
#define __USING_API            using namespace SOLUTION;

__BEGIN_API

class CPU; //declaração das classes criadas nos trabalhos devem ser colocadas aqui
class Debug;
class Thread;

//declaração da classe Traits
template<typename T>
struct Traits {
};

template<> struct Traits<CPU>
{
    //Tamanho da pilha, valor atribuido usando como base o exemplo na descrição do trabalho  
    static const unsigned int STACK_SIZE = 16384;
    static const bool debugged = true;
};

//Para mensagens de depuração
template<> struct Traits<Thread> : public Traits<void>
{   
    static const bool debugged = true;
};

template<> struct Traits<Debug>: public Traits<void> {
    static const bool error = false;
    static const bool warning = false;
    static const bool info = false;
    static const bool trace = true;
};

__END_API

#endif
