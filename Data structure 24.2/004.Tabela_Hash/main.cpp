#include <iostream>
#include "hash.cpp"
using namespace std;

int main(){
    hashing<string> teste;
    hash_table(teste, "Matheus");
    hash_table(teste, "Vinicius");
    hash_table(teste, "Marcos");
    hash_table(teste, "Henry");
    hash_table(teste, "João");
    hash_table(teste, "Gabriel");
    hash_table(teste, "Theo");
}