#ifndef LISTA_UNICAMENTE_ENCADEADA 
#define LISTA_UNICAMENTE_ENCADEADA

#include <iostream>
using namespace std;

//Armazenamento

struct No{
    char info;
    No * elo = NULL;
};

struct LUE{
    No * comeco = NULL;
    No * fim = NULL;
};

//Operações

bool inicializarLUE(LUE &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
    return true;
}

bool inserirFinalLUE(LUE &lista, char dado){

}

#endif 