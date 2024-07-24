/*https://judge.beecrowd.com/pt/problems/view/1379*/ 

#include <iostream>
using namespace std;

void MediaMediana(){
    int A,B,C;
    while (true)
    {
        cin >> A >> B;
        if(A == 0 && B == 0){
            break;
        }
        else{
            C = 2*A - B;
            cout << C << "\n";
        }
    }
    

}

int main(){
    MediaMediana();
}
