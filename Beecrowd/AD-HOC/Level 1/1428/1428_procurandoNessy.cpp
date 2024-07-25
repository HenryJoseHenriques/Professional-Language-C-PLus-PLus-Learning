#include <iostream>
using namespace std;

void adicionarSonar(){
    int t,n,m,l,c,x;
    bool r = true;

    while(true){
        cin >> t;
        if(t == 0) break;

        if(t < 0)
            cout << "Entrada inválida\n";        
        else{
            for(int k = 0; k < t ; k++){
                cin >> n >> m;
                if(n < 6 or m > 10000){
                    cout << "Entrada inválida\n";
                }else{
                    /*Meus deus, o que eu boto aqui*/
                }
            }
            
        }
    }
}

int main(){
    adicionarSonar();
}