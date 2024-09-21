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

No * NewDate(char dado){
    No * novo = new No;
    novo->info = dado;
    novo->elo = NULL;
    return novo;
}

bool inicializarLUE(LUE &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
    return true;
}

bool inserirFinalLUE(LUE &lista, char dado){
    No * novo = NewDate(dado);
    if(novo != NULL){
        if(lista.comeco == NULL){ // Caso 1 - Lista vazia
                lista.comeco = novo;
                lista.fim = novo;
                return true;
        }else{ //Caso 2 - Inserir no final
                lista.fim->elo = novo;
                lista.fim = novo;
                return true;
        }
    }else{
        return false;
    }
}

bool inserirOrdenadoLUE(LUE &lista, char dado){
    No * novo = NewDate(dado);
    if(novo != NULL){

        if(lista.comeco == NULL){ // Caso 1 - Lista vazia
            lista.comeco = novo;
            lista.fim = novo;
            return true;
        }

        else if(dado < lista.comeco->info){ //Inicio  da Lista
            novo->elo = lista.comeco;
            lista.comeco = novo;
            return true;
        }

        else if(dado > lista.fim->info){ // Final da Lista
            novo->elo = lista.fim;
            lista.fim = novo;
            return true;
        }
        
        else{ // Meio da lista
            No * aux = lista.comeco;
            while(aux != NULL){
                No * prox = aux->elo;
                if(aux->info < dado && dado < prox->info){
                    novo->elo = prox;
                    aux->elo = novo;
                    break; 
                }
                aux = aux->elo;
            }
        }

    }else{
        return false;
    }
}

void mostrar(LUE lista){
    No * aux = lista.comeco;
    while(aux != NULL){
        cout << aux->info << " ";
        aux = aux->elo;
    }
}

//Retorna true se não for encontrado ou false se não estiver na lista
bool pesquisarLUE(LUE lista, char dado){
    No * aux = lista.comeco;
    while(aux != NULL){
        if(aux->info == dado) return true;
        aux = aux->elo;
    }
    return false;
}

void liberarLUE(LUE lista){
    No * aux = lista.comeco;
    while (aux != NULL){
        No * temp = aux;
        aux = aux->elo;
        delete temp;
    }
}

bool retirarLue(LUE &lista, char dado){
    No * aux, * ant;
    if(lista.comeco == NULL){
        return false;
    }else{
        if(lista.comeco->info == dado){
            if(lista.fim->info == dado){
                delete lista.comeco;
                delete lista.fim;
            }else{
                No * aux = lista.comeco;
                lista.comeco = lista.comeco->elo;
                delete aux;
            }
        }else if(lista.fim->info == dado){
            No * ant = NULL;
            No * aux = lista.comeco;
                while(aux != NULL){
                if(aux->info == dado){
                    if(aux->info == dado){

                    }
                    else{
                        
                    }
                }
            }
        }else{
            
        }
    }
    
}

#endif 