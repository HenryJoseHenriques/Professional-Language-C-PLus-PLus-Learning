#include <iostream>
using namespace std;

template <typename T> 
struct elementos {
  T dado;
  elementos *prox;
};