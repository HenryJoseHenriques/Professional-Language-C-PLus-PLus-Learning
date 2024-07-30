/*https://judge.beecrowd.com/pt/problems/view/2058*/

#include <iostream>
using namespace std;

void qtdTriangulos(){
    int N;
    while(cin >> N && N != 0){
        int triangulos = N - 2;
        
        if(N > 2)
            cout << triangulos << "\n";
        else
            cout << "Não existe polígonos com " << N << " lado(s)\n";
    }
}

int main()
{
    qtdTriangulos();
}
