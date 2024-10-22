#include <iostream>
using namespace std;

bool novoAluguel(Hash<filmes> &lista, login User, filmeAlugado &instancia){
    //Extrair ad informações de lista e User e jogar na instancia;
}

void exibirAlugueis(Hash<filmeAlugado> listaAlugados){

}

void inicializarAlugueis(Hash<filmeAlugado> &listaAlugados){
    for(int i = 0; i < TAM; i++){
        inicializarLDE(listaAlugados.vetor[i]);
    }
}

void alugarFilmes(Hash<filmes> &lista, login User){
    string bancoAlugados = "listaAlugados.csv";
    Hash<filmeAlugado> listaAlugados;
    inicializarAlugueis(listaAlugados);
    int opc;
    do{
        cout << "\nMeu acervo:\n";
        cout << "\t0 - sair\n";
        cout << "\t1 - meus alugueis\n";
        cout << "\t2 - alugar filme\n";
        cin >> opc;
        cin.ignore();
        switch(opc){
            case 0:
            break;
            case 1:
                exibirAlugueis(listaAlugados);
            break;
            case 2:
                filmeAlugado instancia;
                if(novoAluguel(lista,User,instancia)){
                    inserirLDE(listaAlugados, instancia);
                    cout << "\nFilme alugado\n";
                }else{
                    cout << "\nNao foi possivel realizar o aluguel\n";
                }
            break;
        }
    }while(opc > 0);
}