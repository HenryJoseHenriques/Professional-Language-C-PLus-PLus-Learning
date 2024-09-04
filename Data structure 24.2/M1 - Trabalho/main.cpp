#include <iostream>
#include <locale.h>

#include "LUE.cpp"
#include "files.cpp"
#include "utility.cpp"
#include "console.cpp"
#include "termo.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    // string palavra = "garfo";
    // string listaTermo = "palavrasTermo.txt";
    // int input = 0;
    // ListaPalavras lista;
    // string p[7];
    // inicializarLista(lista);
    // carregarPalavras(lista, listaTermo);
    // preencherPalavrasSecretas(lista,p);
    //jogar(lista);
    // for(int i = 0; i < 7; i++){
    //     cout << p[i] << "\n";
    // }
    // int c = 0;
    // while(palavra[c] != '\0'){
    //     cout <<  palavra[c];
    //     c++;
    // }
    //comoJogar();
    menu();
    //exibirTermo("garfo","termo");
}
