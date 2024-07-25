/*https://judge.beecrowd.com/pt/problems/view/1397 */

#include <iostream>
using namespace std;

void jogoDoMaior(){
    int R,X,Y,C1,C2;
    while(true){
        C1 = 0,C2 = 0;
        cin >> R;
        if(R == 0){
            break;
        }
        else if(R < 0){
            cout << "Entrada inválida.\n";
        }
        else{
            for(int i = 0; i < R; i++){
                cin >> X >> Y;
                if(X != Y){
                    X > Y? C1++:C2++;
                }
            }
            cout << C1 << " " << C2 << "\n";
        }
    }
}

int main(){
    jogoDoMaior();
}