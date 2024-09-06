#include "LUE.hpp"
using namespace std;

void inicializarLista(ListaPalavras &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

void inserirPalavra(ListaPalavras &lista, string palavra)
{ // adiciona palavras na lista
    NoPalavra *novoNo = new NoPalavra;
    novoNo->palavra = palavra;
    novoNo->proximo = NULL;

    if (lista.comeco == NULL)
    {
        lista.comeco = novoNo;
        lista.fim = novoNo;
    }
    else
    {
        lista.fim->proximo = novoNo;
        lista.fim = novoNo;
    }
}

void liberarLista(ListaPalavras &lista)
{
    NoPalavra *atual = lista.comeco;
    while (atual != NULL)
    {
        NoPalavra *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    lista.comeco = NULL;
    lista.fim = NULL;
}

bool removerPalavra(ListaPalavras &lista, string palavra)
{ // ta no nome ja ele remove palavra da lista
    if (lista.comeco == NULL)
        return false;

    NoPalavra *anterior = NULL;
    NoPalavra *atual = lista.comeco;

    while (atual != NULL)
    {
        if (atual->palavra == palavra)
        { // aqui   se encontrou a palavra
            if (atual == lista.comeco)
            {
                lista.comeco = atual->proximo; // aqui   se for o primeiro
            }
            else
            {
                anterior->proximo = atual->proximo; // pula o atual
            }
            if (atual == lista.fim)
            {
                lista.fim = anterior; // se for o ultimo
            }
            delete atual; // deleta a palavra
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false; // n achou
}

void mostrarLista(ListaPalavras lista)
{ // tirei doq o professor tinha feito
    NoPalavra *atual = lista.comeco;
    while (atual != NULL)
    {
        cout << atual->palavra << endl;
        atual = atual->proximo;
    }
} // usar pra verificar c ta carregando certo dps ja fica ai guardado

bool pesquisarLista(ListaPalavras lista, string palavra)
{
    NoPalavra *atual = lista.comeco;
    while (atual != NULL)
    {
        if (atual->palavra == palavra)
            return true;
        atual = atual->proximo;
    }
    return false;
}

int tamanhoLista(ListaPalavras lista)
{
    int c = 0;
    NoPalavra *atual = lista.comeco;
    while (atual != NULL)
    {
        c++;
        atual = atual->proximo;
    }
    return c;
}
