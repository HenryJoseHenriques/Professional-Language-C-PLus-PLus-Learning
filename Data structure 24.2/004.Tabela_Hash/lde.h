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
struct LDE
{
    No<T> *comeco = NULL;
    No<T> *fim = NULL;
};

template <typename T>
void inicializarLDE(LDE<T> &lista)
{
    lista.comeco = NULL; // Inializa apontando para NULL
    lista.fim = NULL;    // Inializa apontando para NULL
}

template <typename T>
No<T> *criarNO(T valor)
{
    No<T> *novo = new No <T>;
    novo->info = valor;
    novo->eloAnterior = NULL;
    novo->eloPosterior = NULL;

    return novo;
}

template <typename T>
bool inserirFinalLDE(LDE<T> &lista, T valor)
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
        lista.fim->eloPosterior = novo; //o último nó aponta para o novo nó
        novo->eloAnterior = lista.fim; //O novo nó aponta de volta para o último nó
        lista.fim = novo; //Atualiza o ponteiro do fim para o novo nó
        return true;
    }
    return false;
}

template <typename T>
bool inserirLDE(LDE<T> &lista, T valor){
    No<T> * novo = criarNO(valor);

    if(lista.comeco == NULL){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    else if(valor < lista.comeco->info){
        novo->eloPosterior = lista.comeco; //O elo posterior do novo nó aponta para o antigo nó
        lista.comeco->eloAnterior = novo; //O o elo anteior do antigo nó aponta para o novo
        lista.comeco = novo;
        return true;
    }

    else if(valor > lista.fim->info){
        lista.fim->eloPosterior = novo; //O elo posteior do antigo fim aponta para o novo fim
        novo->eloAnterior = lista.fim; //O elo anterior do do novo fim aponta para o fim antigo.
        lista.fim = novo;
        return true;
    }

    else{
        No<T> * aux = lista.comeco; //Aponta para o começo da lista
        while(aux != NULL){
            No<T> * prox = aux->eloPosterior; //aponta para próximo(um a frente)
            if(aux->info < valor && valor < prox->info){ //Verifica se o valor está entre o nó atual(aux) e próximo nó (prox)
                aux->eloPosterior = novo; // O posterior do atual nó aponta para o novo nó
                prox->eloAnterior = novo; // O anterior do próximo nó aponta para o novo nó
                novo->eloAnterior = aux; // O anterior do novo nó aponta para o nó atual
                novo->eloPosterior = prox; // O posterior do novo nó aponta para o próximo nó
                break;
            }
            aux = aux->eloPosterior;
        }
        return true;
    }
    return false;
}

template <typename T>
bool retirarLDE(LDE<T> &lista, T valor) {
    if (lista.comeco == NULL) return false;  // Lista vazia

    No<T> *aux;

    // Caso o valor esteja no início da lista
    if (valor == lista.comeco->info) {
        aux = lista.comeco;

        if (valor == lista.fim->info) {  // Se for o único elemento
            lista.comeco = NULL;
            lista.fim = NULL;
        } else {  // Mais de um elemento
            lista.comeco = aux->eloPosterior;
            lista.comeco->eloAnterior = NULL;
        }
    } else {
        // Caso o valor esteja no final da lista
        if (valor == lista.fim->info) {
            aux = lista.fim;
            lista.fim = aux->eloAnterior;
            lista.fim->eloPosterior = NULL;
        } else {
            // Caso o valor esteja no meio da lista
            aux = lista.comeco;
            while (aux != NULL) {
                if (aux->info == valor) {
                    No<T> *ant = aux->eloAnterior;
                    No<T> *prox = aux->eloPosterior;
                    
                    // Ajustando os ponteiros dos nós adjacentes
                    ant->eloPosterior = prox;
                    prox->eloAnterior = ant;
                    
                    break;
                }
                aux = aux->eloPosterior;
            }

            if (aux == NULL) return false;  // Valor não encontrado
        }
    }

    delete aux;  // Libera a memória do nó removido
    return true;
}

template <typename T>
void mostrarLDE(LDE <T> lista, char ordem){
    if( ordem == 'C' || ordem == 'c' ){
        No <T> *aux = lista.comeco;
        while( aux != NULL ){
            cout << aux->info << " ";
            aux = aux->eloPosterior; // Avança para o próximo no
        }
    } else {
        No <T> *aux = lista.fim;
        while( aux != NULL ){
            cout << aux->info << " ";
            aux = aux->eloAnterior; // Avança para o no anterior
        }
    }
}

template<typename T>
bool pesquisarLDE(LDE<T> lista, T valor){
    No<T> *aux = lista.comeco;
    while(aux != NULL){
        if(aux->info == valor) return true;
        aux = aux->eloPosterior;
    }
    return false;
}