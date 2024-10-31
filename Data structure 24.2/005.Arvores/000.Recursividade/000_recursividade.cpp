#include <iostream>
using namespace std;

int sequencia(int x){
    cout << x << " ";
    if(x == 0) return 0;
    return sequencia(x-1);
}

int main(){
    sequencia(10);
}