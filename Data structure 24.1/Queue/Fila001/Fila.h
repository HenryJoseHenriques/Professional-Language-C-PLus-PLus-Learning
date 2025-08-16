/*
Aplicação de Fila
Desenvolva um programa para 'simular' o atendimento a clientes de um banco, utilizando uma fila para o 
guichê de atendimento:
Cada cliente deve ter um nome e a quantidade de unidades de tempo(ex: número de boletos) do seu 
atendimento
Crie 5 clientes com um número de unidades de tempo aleatório, inserindo cada cliente na fila. 
Crie um laço para fazer o atendimento, que será realizado com base nas unidades de tempo de cada 
cliente. Ex: Cliente 1 tem 3 unidades de tempo, o laço precisa executar 3 vezes decrementando as 
unidades de tempo a cada atendimento.
No final mostre a quantidade de unidades de tempo total necessárias para atender todos os clientes.
*/


#include <iostream>
using namespace std;

void ClearScreeen(){
  cout << "\033[2J\033[0;0H"; //Comando para limpar a a tela
}

template <typename TIPO> 
struct ELEMENTOS_SE {
  TIPO dado;
  ELEMENTOS_SE *prox;
};

template <typename TIPO> 
struct TFILA_SE {
ELEMENTOS_SE<TIPO> *inicio; 
};

template <typename TIPO> 
void Inicializar(TFILA_SE<TIPO> &Fila) {
  Fila.inicio = NULL;
}

//DEQUEUE: retira o primeiro elemento da Fila
template <typename TIPO> 
TIPO DEQUEUE_SE(TFILA_SE<TIPO> *Fila) {
  ELEMENTOS_SE<TIPO>
      *temp; // Armazena o endereço da lista simplesmente encadeada
  temp = new ELEMENTOS_SE<TIPO>;
  TIPO dado;                     // Retorna o dado que vai ser retirado
  if (Fila->inicio != NULL) {  // Se a lists não estiver vazia
    dado = Fila->inicio->dado; // Recebe o dado que vai ser retornado
    temp = Fila->inicio;       // Armazena o endereço da lista
    Fila->inicio = temp->prox; // Recebe o endereço do próximo elemento para
                                // qual o elemento que o inicio da lista estava
                                // apontando, está apontando.
  }
  return dado; // Retorna o dado
}  


//QUEUE: insere um elemento no final da Fila  
template <typename TIPO> 
void QUEUE_SE(TFILA_SE<TIPO> &Fila, TIPO dado) {
  ELEMENTOS_SE<TIPO> *NovoDado;
  NovoDado = new ELEMENTOS_SE<TIPO>;
  NovoDado->dado = dado;
  NovoDado->prox = NULL;
  if (Fila.inicio != NULL){
    ELEMENTOS_SE<TIPO> *Temp = Fila.inicio;
    while (Temp->prox != NULL) {
      Temp = Temp->prox;
    }
    Temp->prox = NovoDado;
  }
  if (Fila.inicio == NULL) {
    Fila.inicio = NovoDado;
  }
}

template <typename TIPO> 
void Imprimir(TFILA_SE<TIPO> Fila){
  ELEMENTOS_SE<TIPO> * Temp;
    
  Temp = new ELEMENTOS_SE<TIPO>;
  Temp = Fila.inicio;
    while (Temp != NULL) {
      cout << Temp->dado << "\n";
      Temp = Temp->prox;
    }
}