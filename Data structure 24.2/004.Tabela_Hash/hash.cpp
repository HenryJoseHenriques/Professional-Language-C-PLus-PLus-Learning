#include "lde.h"
#include <iostream>
using namespace std;
#define TAM 30

template<typename T>
struct hashing{
    LDE<T> index[TAM];
};

int converterChave(string dado){
    int x = 0;
    for(int i = 0; dado[i] != '\0'; i++){
        x += int(dado[i]);
    }
    return x;
}

int hashIndex(string dado){
    return converterChave(dado) % 8; 
}

template<typename T>
bool hash_table(hashing<T> &table, string dado){
    for(int i = 0; i < TAM; i++)
        inicializarLDE(table.index[i]);
    return inserirFinalLDE(table.index[hashIndex(dado)], dado);
}



