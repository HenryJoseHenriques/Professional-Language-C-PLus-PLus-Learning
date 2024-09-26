#include <iostream>
#include "pilha.h"
using namespace std;

int main(){
    PILHA<int> lista;
    inicializarPILHA(lista);
    push(lista,12);
    push(lista,15);
    push(lista,89);
    push(lista,8);
    cout << pop(lista) << "\n";
    mostrarPILHA(lista,'C');
}