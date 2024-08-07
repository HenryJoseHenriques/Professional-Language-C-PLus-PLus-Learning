/*https://judge.beecrowd.com/pt/problems/view/2373*/

#include <iostream>
using namespace std;

void bandeja(){
    int N;
    while(cin >> N && N != 0){
        int Cq = 0;
        for(int i = 0; i < N; i++){
            int L, C;
            cin >> L >> C;
            if(L > C) Cq += C;
        }
        cout << Cq << "\n";
    }
}

int main()
{
    bandeja();
}
