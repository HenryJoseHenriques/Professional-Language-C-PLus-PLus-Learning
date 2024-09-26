#include <iostream>
#include "fila.h"
using namespace std;

int main()
{
    FILA<int> lista;
    inicializarFILA(lista);
    enqueue(lista, 12);
    enqueue(lista, 14);
    enqueue(lista, 9);
    enqueue(lista, 89);
    mostrarFILA(lista,'C');
}