#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
using namespace std;
template <typename T> 
struct queue {elementos<T> *inicio; };

template <typename T> void initQueue(queue<T> &Fila) {
  Fila.inicio = NULL;
}

//DEQUEUE: retira o primeiro elemento da Fila e retorna ele
template <typename T> 
T dequeue(queue<T> *Fila) {
  elementos<T> *temp; // Armazena o endereço da lista simplesmente encadeada
  // temp = new elementos<T>;
  T dado = 0;                     // Retorna o dado que vai ser retirado
  if (Fila->inicio != NULL) {  // Se a lists não estiver vazia
    dado = Fila->inicio->dado; // Recebe o dado que vai ser retornado
    temp = Fila->inicio;       // Armazena o endereço da lista
    Fila->inicio = temp->prox; // Recebe o endereço do próximo elemento para
                                // qual o elemento que o inicio da lista estava
                                // apontando.
    delete temp;
  }
  return dado; // Retorna o dado
}  


//QUEUE: insere um elemento no final da Fila  
template <typename T>
void insertQueue(queue<T> &Fila, T dado) {
  elementos<T> *NovoDado = new elementos<T>;
  NovoDado->dado = dado;
  NovoDado->prox = NULL;
  if (Fila.inicio != NULL){
    elementos<T> * Temp = Fila.inicio;
    while (Temp->prox != NULL) {
      Temp = Temp->prox;
    }
    Temp->prox = NovoDado;
  }
  if (Fila.inicio == NULL) {
    Fila.inicio = NovoDado;
  }
}

template <typename T> 
void printQueue(queue<T> Fila){
  elementos<T> * Temp;
    
  Temp = new elementos<T>;
  Temp = Fila.inicio;
    while (Temp != NULL) {
      cout << Temp->dado << "\n";
      Temp = Temp->prox;
    }
}

#endif