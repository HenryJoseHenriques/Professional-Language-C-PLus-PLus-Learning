#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    int alt = 1;
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
int getAltura(No <T> *raiz ){
    return (raiz==NULL) ? 0 : raiz->alt;
}

template <typename T>
int calcular_altura(No <T> *raiz){
    int aE = getAltura(raiz->esq);
    int aD = getAltura(raiz->dir);
    return (aE > aD) ? aE+1 : aD+1;
}

template <typename T>
No <T> * rotacao_simples_direita( No <T> *k ){
    cout << "RSD " << k->info << endl;
    No <T> *x = k->esq;
    No <T> *t2 = x->dir;
    x->dir = k;
    k->esq = t2;
    k->alt = calcular_altura(k);
    x->alt = calcular_altura(x);
    return x;
}

template <typename T>
No <T> * rotacao_simples_esquerda(No <T> *k){
    cout << "RSE " << k->info << endl;
    No <T> *y = k->dir;
    No <T> *t2 = y->esq;
    y->esq = k;
    k->dir = t2;
    k->alt = calcular_altura(k);
    y->alt = calcular_altura(y);
    return y;
}

template <typename T>
No <T> * rotacao_dupla_direita(No <T> *k){
    cout << "RDD " << k->info << endl;
    No <T> *x = k->esq;
    No <T> *w = x->dir;
    No <T> *t2 = w->esq;
    No <T> *t3 = w->dir;
    w->esq = x;
    w->dir = k;
    x->dir = t2;
    k->esq = t3;
    x->alt = calcular_altura(x);
    k->alt = calcular_altura(k);
    w->alt = calcular_altura(w);
    return w;
}

template <typename T>
No <T> * rotacao_dupla_esquerda(No <T> *k){
    cout << "RDE " << k->info << endl;
    No <T> *y = k->dir;
    No <T> *z = y->esq;
    No <T> *t2 = z->esq;
    No <T> *t3 = z->dir;
    z->esq = k;
    z->dir = y;
    k->dir = t2;
    y->esq = t3;
    k->alt = calcular_altura(k);
    y->alt = calcular_altura(y);
    z->alt = calcular_altura(z);
    return z;
}

template <typename T>
No <T> * rotacaoAVL(No <T> *k ){
    if( getAltura(k->esq) > getAltura(k->dir) ){ // Rota��o a direita
        No <T> *x = k->esq;
        if( getAltura(x->esq) >= getAltura(x->dir) )
            k = rotacao_simples_direita(k);
        else
            k = rotacao_dupla_direita(k);
    }
    else{ // Rotacao a esquerda
        No <T> *y = k->dir;
        if( getAltura(y->dir) >= getAltura(y->esq) )
            k = rotacao_simples_esquerda(k);
        else
            k = rotacao_dupla_esquerda(k);
    }
    return k;
}

template <typename T>
No <T> * inserir_avl(No <T> *raiz, T info){
    if( raiz == NULL ){
        raiz = new No<T>;
        if( raiz == NULL ) return NULL;
        raiz->info = info;
        raiz->alt = 1;
        return raiz;
    }
    if( info < raiz->info )
        raiz->esq = inserir_avl(raiz->esq, info);
    else
        raiz->dir = inserir_avl(raiz->dir, info);
    raiz->alt = calcular_altura(raiz);
    int aE = getAltura(raiz->esq);
    int aD = getAltura(raiz->dir);
    if( (aE-aD) == 2 || (aE-aD) == -2 ) raiz = rotacaoAVL(raiz);
    return raiz;
}

template <typename T>
T buscar_valor_troca(No <T> *raiz){
    if( raiz->dir == NULL )
        return raiz->info;
    else
        return buscar_valor_troca(raiz->dir);
}

template <typename T>
No <T> * retirar_avl(No <T> *raiz, T valor){
    if( raiz == NULL ) return NULL;
    if( raiz->info == valor ){
        No <T> *aux = raiz;
        if( raiz->esq == NULL && raiz->dir == NULL ){
            delete raiz;
            return NULL;
        }
        else if( raiz->esq == NULL && raiz->dir != NULL ){
            delete aux;
            return raiz->dir;
        }
        else if( raiz->esq != NULL && raiz->dir == NULL ){
            delete aux;
            return raiz->esq;
        }
        T aux2 = buscar_valor_troca(raiz->esq);
        raiz->info = aux2;
        return retirar_avl(raiz->esq, aux2);
    }
    if( valor < raiz->info )
        raiz->esq = retirar_avl(raiz->esq, valor);
    else
        raiz->dir = retirar_avl(raiz->dir, valor);
    raiz->alt = calcular_altura(raiz);
    int aE = getAltura(raiz->esq);
    int aD = getAltura(raiz->dir);
    if( (aE-aD) == 2 || (aE-aD) == -2 ) raiz = rotacaoAVL(raiz);
    return raiz;
}

template <typename T>
bool pesquisar_avl(No <T> *raiz, T valor){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ) return true;
    if( valor < raiz->info )
        return pesquisar_avl(raiz->esq, valor);
    else
        return pesquisar_avl(raiz->dir, valor);
}

template <typename T>
void liberar_avl(No <T> *&raiz){
    if( raiz == NULL ) return;
    liberar_avl(raiz->esq);
    liberar_avl(raiz->dir);
    delete raiz;
}

template <typename T>
void mostrar_avl(No <T> *raiz, int tab=3 ){
    cout << endl;
    for( int i=0; i<tab; i++ ) cout << " ";
    if( raiz == NULL ){
        cout << "*";
        return;
    }
    cout << raiz->info << "(" << raiz->alt << ")";
    mostrar_avl( raiz->esq, tab+3 );
    mostrar_avl( raiz->dir, tab+3 );
}




