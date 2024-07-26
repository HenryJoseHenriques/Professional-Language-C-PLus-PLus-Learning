/*https://judge.beecrowd.com/pt/problems/view/1743*/

#include <iostream>
using namespace std;

void maquinaDeVerificacao(){
    bool c1[5],c2[5],compativel = true;

    cin >> c1[0] >> c1[1] >> c1[2] >> c1[3] >> c1[4];
    cin >> c2[0] >> c2[1] >> c2[2] >> c2[3] >> c2[4];

    for(int i = 0; i < 5; i++){
        if(c1[i] == c2[i]){
            compativel = false;
            break;
        }
    }
    
    if(compativel)
        cout << "Y\n";
    else
        cout << "N\n";
    
    }

int main(){
    maquinaDeVerificacao();
}