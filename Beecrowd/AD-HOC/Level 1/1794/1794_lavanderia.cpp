/*https://judge.beecrowd.com/pt/problems/view/1794 */

#include <iostream>
using namespace std;

void limiteLavaSecadora(){
        int LA,LB,SA,SB,N;
        do{
            cin >> N;
            cin >> LA >> LB;
            cin >> SA >> SB;
        }while(N < 1 or N > 100 or LA < 1 or LA > 100 or LB < 1 or LB > 100 or SA < 1 or SA > 100 or SB < 1 or SB > 100);

        if(N < LA or N >LB or N < SA or N > SB)
            cout << "impossivel\n";
        else
            cout << "possivel\n";
}

int main(){
    limiteLavaSecadora();
}