/*https://judge.beecrowd.com/pt/problems/view/1026*/

#include <iostream>
#define TAM 32
using namespace std;

string DecimalParaBinario(int decimal){
    string binario = "";
    string binarioCorrigido = "";
    int resto;
    int quociente;
    for (int i = 0; i < TAM; i++){
        resto = decimal % 2;
        if(resto == 0)
            binario += "0";
        else
            binario += "1";
        quociente = decimal / 2;
        decimal = quociente;
    }
    for (int i = TAM-1; i >= 0; i--)
        binarioCorrigido += binario[i];
    binario = binarioCorrigido;
    return binario;
}

string FullAdder(string A, string B){
    string resultado = "";
    char carryout = '0';
    int i = 0;
    while(A[i] != '\0' and B[i] != '\0'){
        if(A[i] == '0' and B[i] == '0' and carryout == '0'){
            resultado += '0';
        }
        if(A[i] == '1' and B[i] == '0' and carryout == '0'){
            resultado += '1';
        }
        if(A[i] == '0' and B[i] == '1' and carryout == '0'){
            resultado += '1';
        }
        if(A[i] == '0' and B[i] == '0' and carryout == '1'){
            resultado += '1';
        }
        if(A[i] == '1' and B[i] == '1' and carryout == '0'){
            resultado += '1';
            carryout = '1';
        }
        if(A[i] == '1' and B[i] == '0' and carryout == '1'){
            resultado += '1';
            carryout = '1';
        }
        if(A[i] == '0' and B[i] == '1' and carryout == '1'){
            resultado += '1';
            carryout = '1';
        }
        i++;
    }
    return resultado;
}


int main()
{
    int x,y,r;
    string bx,by,br;
    cin >>x>>y;
    bx = DecimalParaBinario(x);
    by = DecimalParaBinario(y);
    br = FullAdder(bx,by);
    cout << br;
}