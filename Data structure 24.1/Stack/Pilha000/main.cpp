#include "Pilha.h"
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
  TPilha_SE<int> Pilha;
  Inicializar(Pilha);
  PUSH_SE(Pilha, 5);
  PUSH_SE(Pilha, 7);
  PUSH_SE(Pilha, 3);
  PUSH_SE(Pilha, 9);
  Imprimir(Pilha);
  cout << "\n" << POP_SE(&Pilha) << "\n\n";
  Imprimir(Pilha);
}