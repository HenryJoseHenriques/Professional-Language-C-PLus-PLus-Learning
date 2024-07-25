/*https://judge.beecrowd.com/pt/problems/view/1387*/

#include <iostream>
using namespace std;

void contarFilhos(){
    int L, R;
    while(true){
        cin >> L >> R;
        if(L == 0 and R == 0){
            break;
        }else if(L < 1 || R < 1 || L > 5 || R > 5){
            cout << "Valor inválido.\n";
        }
        else{
            cout << L+R << "\n";
        }
        
    }
}


int main()
{
    contarFilhos();
}
