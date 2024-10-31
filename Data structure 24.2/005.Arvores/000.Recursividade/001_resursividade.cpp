#include <iostream>
using namespace std;

int quociente(int x, int y){
    if(x < y == 0) return 0;
    return quociente(x-y,y)+1;
}

int main(){
    cout << quociente(28,4);
}