/*https://judge.beecrowd.com/pt/problems/view/1573*/

#include <iostream>
#include <cmath>
using namespace std;

void produzirChocolate(){
    int A,B,C,L;
    while (cin >> A >> B >> C && A != 0 && B != 0 && C != 0)
    {
        L = cbrt(A*B*C);
        cout << L << "\n";
    }
}

int main(){
    produzirChocolate();
}