#ifndef PILHA_HPP
#define PILHA_HPP
template <typename T> 
struct stack { elementos<T> *inicio; };

template <typename T> 
void initStack(stack<T> &pilha) {
  pilha.inicio = NULL;
}

template <typename T> 
elementos<T> * criarElemento(T dado){
  elementos<T> *NovoDado;
  NovoDado = new elementos<T>;
  NovoDado->dado = dado;
  NovoDado->prox = NULL;
  return NovoDado;
}

// POP: retira um elemento do topo da pilha
template <typename T> 
T pop(stack<T> *pilha) {
    elementos<T> *temp = pilha->inicio;
    pilha->inicio = temp->prox;
    T DADO;
    DADO = temp->dado;
    delete temp;
    return DADO;
}

// PUSH: insere um elemento no topo da pilha.
template <typename T> 
void push(stack<T> &pilha, T dado) {
  elementos<T> *NovoDado = criarElemento(dado);
  if (pilha.inicio != NULL) {
    elementos<T> *Temp = pilha.inicio;
    NovoDado->prox = Temp;
    pilha.inicio = NovoDado;
  }
  if (pilha.inicio == NULL) 
    pilha.inicio = NovoDado;
}

template <typename T> 
void printStack(stack<T> pilha) {
  elementos<T> *Temp  = pilha.inicio;
  while (Temp != NULL) {
    cout << Temp->dado << "\n";
    Temp = Temp->prox;
  }
}

#endif