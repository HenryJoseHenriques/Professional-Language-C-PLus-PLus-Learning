#include <iostream>
using namespace std;

template <typename T>
struct No
{
    T info;
    No<T> *eloAnterior = NULL;
    No<T> *eloPosterior = NULL;
};

template <typename T>
struct PILHA
{
    No<T> *comeco = NULL;
    No<T> *fim = NULL;
};

template <typename T>
void inicializarPILHA(PILHA<T> &lista)
{
    lista.comeco = NULL; // Inializa apontando para NULL
    lista.fim = NULL;    // Inializa apontando para NULL
}

template <typename T>
No<T> *criarNO(T valor)
{
    No<T> *novo = new No<T>;
    novo->info = valor;
    novo->eloAnterior = NULL;
    novo->eloPosterior = NULL;

    return novo;
}

template <typename T>
bool push(PILHA<T> &lista, T valor)
{
    No<T> *novo = criarNO(valor);

    if (lista.comeco == NULL)
    {
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }
    else
    {
        lista.fim->eloPosterior = novo; // o último nó aponta para o novo nó
        novo->eloAnterior = lista.fim;  // O novo nó aponta de volta para o último nó
        lista.fim = novo;               // Atualiza o ponteiro do fim para o novo nó
        return true;
    }
    return false;
}

template <typename T>
T pop(PILHA<T> &lista)
{
    // if (lista.comeco == NULL) return false;  // Lista vazia
    No<T> *aux = lista.comeco; // Aponta para o topo
    T valor = aux->info;

    lista.comeco = aux->eloPosterior; // Atualiza o topo para o próximo nó
    if (lista.comeco != NULL)
    {
        lista.comeco->eloAnterior = NULL; // Remove o vínculo do anterior
    }
    else
    {
        lista.fim = NULL; // Se a pilha ficou vazia, atualiza fim
    }

    delete aux; // Libera a memória do nó removido
    return valor;
}

template <typename T>
T top(PILHA<T> &lista) {
    return lista.comeco->info; // Retorna o valor do topo
}

template <typename T>
bool isEmpty(PILHA<T> &lista)
{
    return lista.comeco == NULL; // Lista vazia
}

template <typename T>
void mostrarPILHA(PILHA<T> lista, char ordem) {
    if (ordem == 'C' || ordem == 'c') {
        No<T> *aux = lista.comeco;
        while (aux != NULL) {
            cout << aux->info << " ";
            aux = aux->eloPosterior; // Avança para o próximo nó
        }
    } else {
        No<T> *aux = lista.fim;
        while (aux != NULL) {
            cout << aux->info << " ";
            aux = aux->eloAnterior; // Avança para o nó anterior
        }
    }
}

template <typename T>
bool pesquisarPILHA(PILHA<T> lista, T valor) {
    No<T> *aux = lista.comeco;
    while (aux != NULL) {
        if (aux->info == valor)
            return true;
        aux = aux->eloPosterior;
    }
    return false;
};