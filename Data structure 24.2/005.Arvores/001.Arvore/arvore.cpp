#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No <T> *esq=NULL, *dir=NULL;
};

template <typename T>
void prefixado(No <T> *raiz){
    if( raiz == NULL ) return;
    cout << raiz->info << " ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

template <typename T>
void infixado(No <T> *raiz){
    if( raiz == NULL ) return;
    infixado(raiz->esq);
    cout << raiz->info << " ";
    infixado(raiz->dir);
}

template <typename T>
void posfixado(No <T> *raiz){
    if( raiz == NULL ) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " ";
}

template <typename T>
int contar(No <T> *raiz){
    if( raiz == NULL ) return 0;
    return contar(raiz->esq) + contar(raiz->dir) + 1;
}

template <typename T>
bool inserir_abb(No <T> *&raiz, T info){
    if( raiz == NULL ){
        raiz = new No<T>;
        if( raiz == NULL ) return false;
        raiz->info = info;
        return true;
    }
    if( info < raiz->info )
        return inserir_abb(raiz->esq, info);
    else
        return inserir_abb(raiz->dir, info);
}

template <typename T>
bool pesquisar_abb(No <T> *raiz, T valor){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ) return true;
    if( valor < raiz->info )
        return pesquisar_abb(raiz->esq, valor);
    else
        return pesquisar_abb(raiz->dir, valor);
}

template <typename T>
void liberar_abb(No <T> *&raiz){
    if( raiz == NULL ) return;
    liberar_abb(raiz->esq);
    liberar_abb(raiz->dir);
    delete raiz;
}

template <typename T>
void buscar_valor_troca(No <T> *raiz){
    if(raiz->dir == NULL){
        return raiz->info;
    }else{
        return buscar_valor_troca(raiz->dir);
    }
}

template <typename T>
void remover_abb(No <T> *&raiz, T valor){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ){
        No<T> * aux = raiz;
        if(raiz->esq == NUL && raiz->dir == NULL){
            raiz = NULL;
        }else if(raiz->esq == NUL && raiz->dir != NULL){
            raiz = raiz->dir;
        }else if(raiz->esq != NUL && raiz->dir == NULL){
            raiz = raiz->esq;
        }else{
            T  aux2 = buscar_valor_troca(raiz->esq);
            raiz->info = aux2;
            return remover_abb(raiz->esq, aux2);
        }
        delete aux;
        return true;
    }
    if( valor < raiz->info )
        return pesquisar_abb(raiz->esq, valor);
    else
        return pesquisar_abb(raiz->dir, valor);
}

