#include <iostream>
using namespace std;
#define TAM 17

template <typename T>
struct Hash{
    LDE <T> vetor[TAM];
};

int cripto(string frase){
    int total = 0;
    for( int i=0; i<frase.length(); i++ )
        total += int(frase[i]);
    return total;
}

int hashing(string frase){
    int total = cripto(frase);
    return total % TAM;
}

// int main(){
//     Hash <string> tabela;
//     string frase;
//     int opcao, pos;

//     for( int i=0; i<TAM; i++ ){
//         inicializarLDE(tabela.vetor[i]);
//     }

//     do{
//         cout << endl << "Menu:";
//         cout << endl << "\t0 - Fim";
//         cout << endl << "\t1 - Inserir";
//         cout << endl << "\t2 - Remover";
//         cout << endl << "\t3 - Pesquisar";
//         cout << endl << "\t4 - Mostrar Tabela";
//         cout << endl << "\t\tOpcao: ";
//         cin >> opcao;
//         fflush(stdin);

//         switch(opcao){
//             case 0 :
//                 break;
//             case 1 :
//                 cout << "Digite a frase a inserir: ";
//                 getline(cin, frase);
//                 pos = hashing(frase);
//                 if( inserirLDE(tabela.vetor[pos], frase) )
//                     cout << endl << "Insercao realizada com sucesso";
//                 else
//                     cout << endl << "Insercao falhou";
//                 break;
//             case 2 :
//                 cout << "Digite a frase a remover: ";
//                 getline(cin, frase);
//                 pos = hashing(frase);
//                 if( retirarLDE(tabela.vetor[pos], frase) )
//                     cout << endl << "Retirada realizada com sucesso";
//                 else
//                     cout << endl << "Frase nao presente na tabela";
//                 break;
//             case 3 :
//                 cout << "Digite a frase a pesquisar: ";
//                 getline(cin, frase);
//                 pos = hashing(frase);
//                 if( pesquisarLDE(tabela.vetor[pos], frase) )
//                     cout << endl << "Frase localizada na tabela";
//                 else
//                     cout << endl << "Frase nao presente na tabela";
//                 break;
//             case 4 :
//                 cout << endl << "Tabela Hashing: ";
//                 for( int i=0; i<TAM; i++ ){
//                     cout << i << " => ";
//                     mostrarLDE(tabela.vetor[i], 'C');
//                     cout << endl;
//                 }
//                 break;
//             default :
//                 cout << endl << "Erro: opcao invalida";
//         }

//     }while( opcao > 0 );

//     for( int i=0; i<TAM; i++ ){
//         liberarLDE(tabela.vetor[i]);
//     }
//     cout << endl;
// }
