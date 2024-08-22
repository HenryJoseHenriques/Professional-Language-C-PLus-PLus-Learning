#include <iostream>
#include "lue.hpp"
using namespace std;

int main(){
    LUE lista1;
    char dado;

    inicializarLUE(lista1);

    do{
        cin >> dado;
        if( dado != '0') inserirFinalLUE(lista1, dado);
    }while(dado != '0');
    
    mostrar(lista1);
    liberarLUE(lista1);
    return 0;
}