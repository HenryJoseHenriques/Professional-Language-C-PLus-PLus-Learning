/*https://judge.beecrowd.com/pt/problems/view/2328*/

#include <iostream>
using namespace std;

void chocolate(){
    int N;
    while(cin >> N && N !=0){
        int V[N], T = 0;
        for(int i = 0; i < N; i++){
            cin >> V[i];
            T += V[i] - 1;
        }
        cout << T << "\n";
    }
}

int main()
{
    chocolate();
}