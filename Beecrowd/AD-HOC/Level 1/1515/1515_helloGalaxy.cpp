/*https://judge.beecrowd.com/pt/problems/view/1515*/

#include <iostream>
#include <string>
using namespace std;


void identificarPrimeiro(){
    int N, A,T;
    string planeta;
    while(true){
        cin >> N;
        if(N == 0) break;

        int *anoDeEnvio = new int[N];
        string *planetaEmitente = new string[N];

        for(int i = 0; i < N; i ++){

            cin >> planeta >> A >> T;

            if(planeta.length() < 1 || planeta.length() > 50 || A < 2014 || A > 2113 || T < 1 || T > 1000){
                i--;
                continue;
            }else{
                anoDeEnvio[i] = A - T;
                planetaEmitente[i] = planeta;
            }
        }

        int primeiro = 0;
        for(int i = 1; i < N; i ++)
            if(anoDeEnvio[i] < anoDeEnvio[primeiro])
                primeiro = i;
                
        cout << planetaEmitente[primeiro] << "\n";

        delete[] anoDeEnvio;
        delete[] planetaEmitente;
    }
}

int main(){
    identificarPrimeiro();
}