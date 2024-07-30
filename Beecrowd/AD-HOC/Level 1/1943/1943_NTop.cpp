/*https://judge.beecrowd.com/pt/problems/view/1943*/

#include <iostream>
using namespace std;

void topN(){
    int N;
    while(cin >> N && N!=0){
        if(N == 1)
            cout << "Top 1\n";
        else if(N > 1 && N <= 3)
            cout << "Top 3\n";
        else if(N > 3 && N <= 5)
            cout << "Top 5\n";
        else if(N > 5 && N <= 10)
            cout << "Top 10\n";
        else if(N > 10 && N <= 25)
            cout << "Top 25\n";
        else if(N > 25 && N <= 50)
            cout << "Top 50\n";
        else if(N > 50 && N <= 100)
            cout << "Top 100\n";
        else
            cout << "Ranking irrelevante\n";
    }
}

int main()
{
    topN();
}
