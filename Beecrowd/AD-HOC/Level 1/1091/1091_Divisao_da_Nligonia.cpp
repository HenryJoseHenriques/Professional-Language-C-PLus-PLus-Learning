/*
https://judge.beecrowd.com/pt/problems/view/1091
*/

#include <iostream>
using namespace std;

void Divisao(){
    int K,M,N,X,Y;
    while(true){
        cin >> K; //Número de consultas
        if (K == 0){ 
            break;
        }

        cin >> N >> M; //Coordenadas do ponto divisor
        
        for(int i = 0; i < K; i++){ 
        cin >> X >> Y; //Coordenadas de uma residência
            if(X > N and Y > M){
                cout << "NE\n";
            }
            else if(X > N and Y < M){
                cout << "SE\n";
            }
            else if(X < N and Y < M){
                cout << "SO\n";
            }
            else if(X < N and Y > M){
                cout << "NO\n";
            }
            else if(Y == M or X == N){
                cout << "divisa\n";
            }
        }
    }
}


int main()
{

    Divisao();

}