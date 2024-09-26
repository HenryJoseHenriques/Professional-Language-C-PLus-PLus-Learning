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
struct FILA
{
    No<T> *comeco = NULL;
    No<T> *fim = NULL;
};

template <typename T>
void inicializarFILA(FILA<T> &lista)
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
bool enqueue(FILA<T> &lista, T valor)
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
T dequeue(FILA<T> &lista) {
    //if (lista.comeco == NULL) return false;  // Lista vazia
    
    No<T> *aux = lista.comeco;  // Aponta para o primeiro elemento
    T valor = lista.comeco->info;
    
    // Caso haja apenas um elemento
    if (lista.comeco == lista.fim) {
        lista.comeco = NULL;
        lista.fim = NULL;
    } else {
        // Mais de um elemento
        lista.comeco = aux->eloPosterior;
        lista.comeco->eloAnterior = NULL;  // Remove o vínculo do anterior
    }

    delete aux;  // Libera o nó removido
    return valor;
}

template <typename T>
T front(FILA<T> &lista) {
    return lista.comeco->info;
}

template <typename T>
bool isEmpty(FILA<T> &lista)
{
    return lista.comeco == NULL; // Lista vazia
}

template <typename T>
void mostrarFILA(FILA<T> lista, char ordem) {
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

template<typename T>
bool pesquisarFILA(FILA<T> &lista, T valor) {
    No<T> *aux = lista.comeco;
    while(aux != NULL) {
        if(aux->info == valor) return true;
        aux = aux->eloPosterior;
    }
    return false;
}