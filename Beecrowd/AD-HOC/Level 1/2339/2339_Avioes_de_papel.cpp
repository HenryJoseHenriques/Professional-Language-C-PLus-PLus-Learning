/*https://judge.beecrowd.com/pt/problems/view/2339 */

#include <iostream>
#define TAM 3
using namespace std;

void separarFolhas(){
    int C,P,F;
    cin >> C >> P >> F;
    P/F < C? cout << "N\n": cout << "S\n";
}

int main(){
    separarFolhas();
} 