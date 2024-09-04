#include <iostream>
#include <cctype>
#include <string>
#include <random>
#include <time.h>

using namespace std;

string palavraMinusculo(string palavra) {
    for (char &c : palavra) {
        c = tolower(c);
    }
    return palavra;
}

bool validadePalavra(string palavra){
    if(palavra.size() == 5) return true;
    return false;
}

int numRandomico(ListaPalavras lista){
    srand(time(NULL));
    return rand() % tamanhoLista(lista) + 1;
}