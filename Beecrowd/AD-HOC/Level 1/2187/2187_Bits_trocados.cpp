/*https://judge.beecrowd.com/pt/problems/view/2187*/

#include <iostream>
using namespace std;

void bitTrocados(){
    int X;
    for(int a = 1; cin >> X && X != 0; a++){
        int I,J,K,L,i,j,k;
        
        I = X / 50;
        i = X % 50;
        J = i / 10;
        j = i % 10;
        K = j / 5;
        k = j % 5;
        L = k / 1;
        
        cout << "Teste " << a << "\n";
        cout << I << " " << J << " " << K << " " << L << "\n";
        cout << "\n";
    }
}

int main()
{
    bitTrocados();
}