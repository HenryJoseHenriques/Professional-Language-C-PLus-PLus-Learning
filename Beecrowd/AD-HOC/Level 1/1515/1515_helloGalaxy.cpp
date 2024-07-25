/*https://judge.beecrowd.com/pt/problems/view/1515*/

#include <iostream>
#include <string>
using namespace std;


void identificarPrimeiro(){
    int N, A,T,primeiro = 0, *anoDeEnvio = new int[N];
    string planeta, *planetaEmitente = new string[N];
    bool entradaValida = true;
    while(true){
        cin >> N;
        if(N == 0) break;
        if(N < 0) cout << "Entranda inválida\n";
        else{
            for(int i = 0; i < N; i ++){

                cin >> planeta >> A >> T;

                if(planeta.length() < 1 || planeta.length() > 50 ){
                    cout << "mensagem excedeu o limite de caracteres.\n";
                    entradaValida = false;
                }

                if(A < 2014 || A > 2113){
                    cout << "Ano fora do intervalo.\n";
                    entradaValida = false;
                }

                if(T < 1 || T > 1000){
                    cout << "O tempo está fora do intervalo de captura\n";
                    entradaValida = false;
                }

                if(entradaValida){
                    anoDeEnvio[i] = A - T;
                    planetaEmitente[i] = planeta;
                }
                else{
                    i--;
                    continue;
                }
                
            }

            for(int i = 1; i < N; i ++)
                if(anoDeEnvio[i] < anoDeEnvio[primeiro])
                    primeiro = i;
                

            cout << planetaEmitente[primeiro] << "\n";
        }
    }
}

int main(){
    identificarPrimeiro();
}