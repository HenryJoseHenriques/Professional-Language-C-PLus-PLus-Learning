#include <iostream>
#include "arvore.cpp"
using namespace std;

// 1
template <typename T>
int contarFolhas(No<T> *raiz)
{
    int c = 0;
    if(raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL) c++;
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir) + c;
}

// 2
template <typename T>
bool eBinario(No<T> *raiz)
{
    if (raiz->info < raiz->dir->info && raiz->info > raiz->esq->info)
        return true;
    eBinario(raiz->dir);
    eBinario(raiz->esq);
    return false;
}

// 3

int main()
{

    return 0;
}