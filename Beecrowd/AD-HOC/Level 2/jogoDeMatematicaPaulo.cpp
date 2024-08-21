/*https://judge.beecrowd.com/pt/problems/view/1192*/

#include <iostream>
#include <string>
using namespace std;

void jogoDeMatematica(){
    int N;
    while(cin >> N && N != 0){
        string V[N];
        for(int i = 0; i < N; i++){
            cin >> V[i];
            if(V[i].size() < 3 || V[i].size() > 3){
                i++;
                cout<< "formato inválido.\n";
                continue;
            }
            cout << (int)V[i][0] << "\n";
        }
    }
}


int main()
{
    jogoDeMatematica();
}