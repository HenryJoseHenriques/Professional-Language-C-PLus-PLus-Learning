/*1. Duas pilhas sequenciais numéricas estão ordenadas crescentemente a partir do topo. Transferir os elementos
dessas pilhas para uma terceira pilha, inicialmente vazia, de modo que ela fique ordenada decrescentemente com
o maior valor no topo.
*/
#include "pilha.h"
#include <iostream>
using namespace std;


template<typename T>
PILHA<T> intercalacao(PILHA<T> arm1, PILHA<T> arm2){
    PILHA <T> result;
    int auxA, auxB;
    bool stA, stB;

    stA = pop(arm1,auxA);
    stA = pop(arm2,auxB);

    inicializarPILHA(result);

    while(stA == true || stB == true){
        if(stA == true && stB == true){
            if(auxA < auxB){
                push(result, auxA);
                stA = pop(arm1, auxA);
            }else{
                push(result, auxB);
                stB = pop(arm2,auxB);
            }
        }
    }else{
        if(stA == true){
            
        }
    }

    return result;
}


int main()
{
    PILHA<int> arm1,arm2,arm3;

    inicializarPILHA(arm1);
    inicializarPILHA(arm2);
    inicializarPILHA(arm3);

    push(arm1, 15);
    push(arm1, 12);
    push(arm1, 9);
    push(arm1, 7);

    push(arm2,16);
    push(arm2,6);
    push(arm2,4);
    push(arm2,2);
    push(arm2,1);

    


}
