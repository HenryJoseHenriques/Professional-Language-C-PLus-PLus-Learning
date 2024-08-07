/*https://judge.beecrowd.com/pt/problems/view/2369*/
#include <iostream>
using namespace std;

void tarifaDaConta(){
    int N;
    while(cin >> N && N != 0){
        int preco = 7;
        for(int i = 1; i <= N; ++i){
            if(i <= 10){
                continue;
            } else if(i <= 30){
                preco += 1;  
            } else if(i <= 100){
                preco += 2;
            } else {
                preco += 5;
            }
        }
        cout << preco << "\n";
    }
}

int main()
{
    tarifaDaConta();
}