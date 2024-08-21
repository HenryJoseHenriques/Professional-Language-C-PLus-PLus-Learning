#ifndef LISTA_UNICAMENTE_ENCADEADA 
#define LISTA_UNICAMENTE_ENCADEADA

#include <iostream>
using namespace std;

struct Agenda{
    string nome;
    string endereco;
    string telefone;
    int idade;
};

struct No
{
    char info;
    No * elo;
};


#endif 
