/*
Desenvolver um programa que analise uma expressão matemática e identifique se os 
elementos separadores de abertura ‘[‘, ‘{‘ e ‘(‘ são encerrados de forma correta com
os elementos separadores de encerramento ‘)‘, ‘}‘ e ‘]’.
Por simplicidade, o programa não verifica a ordem de emprego desses elementos de
abertura. Ou seja, expressões tais como 2 * ( 3 – [ 4+ { 2 + 3 }] ) e 2 * { 3 – ( 4 + [ 2 + 3 ]
) } são consideradas vá2  lidas.
Por outro lado, expressões tais como 2 * ( 3 – [ 4+5 ) ] são consideradas inválidas,
pois o último elemento aberto ‘[‘, posicionado antes do número 4, está sendo encerrado
com o ‘)’, posicionado após o número 5.
Utilizar a estrutura de pilha (TAD) como solução para o problema.
*/

#include <iostream>

int main() {
    
}