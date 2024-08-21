#include "listaUnicamenteEncadeada.hpp"

int main(){
    Agenda a1;

    a1.nome = "Henry José";
    a1.endereco = "Casa de mãe Joana, 69";
    a1.telefone = "4002-8922";
    a1.idade = 50;

    Agenda * a2 = new Agenda;
    //a2 = &a1; //Está apontando para o endereço de memória de a1
    a2->nome = "Henrique Joseph"; //Está sobreescrevendo a1
    a2->endereco = "Onde Judas bateu as botas, 420";
    a2->telefone = "180";
    a2->idade = 300;

    No * aux1 = new No;
    No * aux2 = new No;
    No * aux3 = new No;
    aux1->info = 'H';
    aux1->elo = aux2;

    cout << "aux1 = " << aux1 << "\n";
    cout << "Conteúdo de aux1 " << aux1->info << " " << aux1->info << "\n"; 

    aux2->info = 'E';
    aux2->elo = aux3;

    cout << "aux2 = " << aux2 << "\n";
    cout << "Conteúdo de aux2 " << aux2->info << " " << aux2->info << "\n"; 
    
    aux3->info = 'N';
    aux3->elo = NULL;

    cout << "aux3 = " << aux3 << "\n";
    cout << "Conteúdo de aux3 " << aux3->info << " " << aux3->info << "\n"; 

    delete a2;
    return 0;
}