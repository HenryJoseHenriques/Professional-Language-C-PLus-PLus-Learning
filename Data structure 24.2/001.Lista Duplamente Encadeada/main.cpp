#include <iostream>
#include "lde.h"
using namespace std;

int main(){
    LDE<int> lista;
    inicializarLDE(lista);
    inserirLDE(lista,12);
    inserirLDE(lista,17);
    inserirLDE(lista,69);
    inserirLDE(lista,20);
    inserirLDE(lista,64);
    inserirLDE(lista,3);
    retirarLDE(lista,69);    
    inserirLDE(lista,4);
    inserirLDE(lista,151);
    inserirLDE(lista,24);
    mostrarLDE(lista,'C');
    return 0;
}