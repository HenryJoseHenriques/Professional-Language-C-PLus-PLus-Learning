#include <iostream>
using namespace std;

/*
O prof. João determinou que os quadrados seriam divididos em duas classes: 
aqueles com média menor ou igual a 127 serão considerados pretos e aqueles 
com média maior a 127 serão considerados brancos.
 */

void LeituraOtica(){
    int N,Q, V[5]; 
    while (true){
        cin >> N;
        if(N == 0) break;
        if(N < 0){
            cout << "Entranda inválida.\n";
        }
        else{
            for(int i = 0; i < N; i++){
                int P = 0;
                cin >> V[0] >> V[1] >> V[2] >> V[3] >> V[4];
                for(int j = 0; j < 5; j++){
                    if(V[j] <= 127){
                        P++;
                        Q = j;
                    }
                }
                    
                if(P != 1){
                    cout << "*\n";
                }else{
                    switch (Q)
                    {
                    case 0:
                        cout << "A\n";
                        break;
                    case 1:
                        cout << "B\n";
                        break;
                    case 2:
                        cout << "C\n";
                        break;
                    case 3:
                        cout << "D\n";
                        break;
                    case 4:
                        cout << "E\n";
                        break;
                    default:
                        cout << "ERROR";
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    LeituraOtica();
}