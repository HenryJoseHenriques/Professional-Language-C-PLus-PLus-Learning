#include <iostream>
using namespace std;

void game(){
    string listaTermo = "palavrasTermo.txt";
    colorScreen cor;
    ListaPalavras lista;

    inicializarLista(lista);
    carregarPalavras(lista, listaTermo);

}