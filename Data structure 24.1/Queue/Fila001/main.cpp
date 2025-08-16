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
#include <random>
#include <time.h>
using namespace std;
#include "Fila.h"
#include "Clientes.h"

#define tam 5

// template <typename TIPO> 
// int operator+= (int &horas, TIPO &c){
//     return (horas += c.QuantTemp);
// }

int main() {
  TFILA_SE<clientes> atend;
  int HorasTotais = 0;
  Inicializar(atend);
  for(int i = 0; i < tam; i++){
    clientes temp;
    cout << "\nDigite o nome do " << i+1 << "º cliente atendido:\n";
    cin >> temp.nome; 
    ClearScreeen();
    cout << "\nDigite a unidade de tempo do " << i+1 << "º cliente atendido:\n";
    cin >> temp.QuantTemp; 
    ClearScreeen();
    QUEUE_SE(atend, temp);
    clientes horasclientes = DEQUEUE_SE(&atend);
    HorasTotais += horasclientes.QuantTemp;
  }
  cout << "\n A quantidade total de unidadades de tempo para o atendimento é: " << HorasTotais;
}