#include <iostream>
#include <random>
#include <time.h>
using namespace std;
#include "Fila.h"

int main() {
  TFila_SE<int> Fila_Teste;
  Inicializar(Fila_Teste);
  srand(time(NULL));

  // for (int i = 0; i < 50; i++) {
  //   int r = rand() % 50 + 1;
  //   QUEUE_SE(Fila_Teste, r);
  // }

  QUEUE_SE(Fila_Teste, 1);
  QUEUE_SE(Fila_Teste, 6);
  QUEUE_SE(Fila_Teste, 3);
  QUEUE_SE(Fila_Teste, 8);
  QUEUE_SE(Fila_Teste, 5);
  
  Imprimir(Fila_Teste);

  cout << "\n";

  cout << DEQUEUE_SE(&Fila_Teste) << "\n";

  cout << "\n";

  Imprimir(Fila_Teste);
}