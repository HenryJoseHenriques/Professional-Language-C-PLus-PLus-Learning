/*https://judge.beecrowd.com/pt/problems/view/2189*/

#include <iostream>
using namespace std;

void quermesse(){
    int N,C, j = 1;
    while(cin >> N && N)
    {
        for(int i = 1; i <= N; i++)
        {
            cin >> C;
            if(C == i)
                cout << "Teste " << j++ << "\n" << C << "\n\n";
        }
    }
}

int main()
{
    quermesse();
}