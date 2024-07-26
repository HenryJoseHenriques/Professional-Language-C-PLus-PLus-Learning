#include <iostream>
using namespace std;

void feedback(){
    int N,K,X;
    while(cin >> N && N != 0){ //Quantidade de dias de trabalho
        for(int i = 0; i < N; i++){

            cin >> K; //Quantidade de feedbacks

            if(K == 0) continue; //Não há feedbacks

            for(int j = 0; j < K; j++){
                cin >> X; //Feedbacks
                if(X < 1 || X > 4){
                    cout << "Entrada inválida\n";
                }else{
                    switch(X){
                        case 1:
                            cout << "Rolien\n";
                            break;
                        case 2:
                            cout << "Naej\n";
                            break;
                        case 3:
                            cout << "Elehcim\n";
                            break;
                        case 4:
                            cout << "Odranoel\n";
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
    feedback();
}