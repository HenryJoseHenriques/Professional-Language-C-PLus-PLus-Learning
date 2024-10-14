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
    No<T> *topo = NULL;
};

template <typename T>
void inicializarPILHA(PILHA<T> &lista)
{
    lista.topo = NULL;    // Inializa apontando para NULL
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

    if (lista.topo == NULL)
    {
        lista.topo = novo;
        return true;
    }
    else
    {
        lista.topo->eloPosterior = novo; // o último nó aponta para o novo nó
        novo->eloAnterior = lista.topo;  // O novo nó aponta de volta para o último nó
        lista.topo = novo;               // Atualiza o ponteiro do topo para o novo nó
        return true;
    }
    return false;
}

template <typename T>
bool pop(PILHA<T> &lista, T &valor)
{
    if (lista.topo == NULL) return false;  // Lista vazia
    No<T> *aux = lista.topo; // Aponta para o topo
    valor = aux->info;

    lista.topo = aux->eloAnterior; // Atualiza o topo para o próximo nó
    if (lista.topo != NULL)
    {
        lista.topo->eloPosterior = NULL; // Remove o vínculo do anterior
    }

    delete aux; // Libera a memória do nó removido
    return true;
}

template <typename T>
T top(PILHA<T> &lista) {
    return lista.topo->info; // Retorna o valor do topo
}

template <typename T>
bool isEmpty(PILHA<T> &lista)
{
    return !(lista.topo == NULL); // Lista vazia
}

template <typename T>
void mostrarPILHA(PILHA<T> lista, char ordem) {
    if (ordem == 'C' || ordem == 'c') {
        No<T> *aux = lista.topo;
        while (aux != NULL) {
            cout << aux->info << " ";
            aux = aux->eloPosterior; // Avança para o próximo nó
        }
    } else {
        No<T> *aux = lista.topo;
        while (aux != NULL) {
            cout << aux->info << " ";
            aux = aux->eloAnterior; // Avança para o nó anterior
        }
    }
}

// template <typename T>
// bool pesquisarPILHA(PILHA<T> lista, T valor) {
//     No<T> *aux = lista.topo;
//     while (aux != NULL) {
//         if (aux->info == valor)
//             return true;
//         aux = aux->eloPosterior;
//     }
//     return false;
// };