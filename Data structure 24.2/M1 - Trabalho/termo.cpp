#include <iostream>
using namespace std;

void jogar(){}

bool adiconarNovaPalavra(ListaPalavras &lista, string palavra){
    if(pesquisarLista(lista, palavra)){
        return false;
    }else{
        inserirPalavra(lista, palavra);

        return true;
    }
}

bool removerPalavraExistente(ListaPalavras &lista, string palavra){
    if(pesquisarLista(lista, palavra)){
        removerPalavra(lista, palavra);
        return true;
    }else{
        return false;
    }
}

void comoJogar(){
    clearScreen();
    colorScreen cor;
    cout << "Descubra a palavra certa em 6 tentativas.\nDepois de cada tentativa, as peças mostram o quão perto você está da solução.\n";
    cout << cor.green <<  "T " << cor.reset << "E R M O\n";
    cout << "A letra " << cor.green <<  "T " << cor.reset << " faz parte da palavra na posição correta.\n";
    cout << "V I " << cor.yellow <<  "O " << cor.reset << "L A\n";
    cout << "A letra " << cor.yellow <<  "O " << cor.reset << " faz parte da palavra mas em outra posição.\n";
    cout << "Todas as palavras NÃO possuem acentos, evite adiconar palavra com acento pq não sabemos tratar.\n";
    cout << "As palavras podem possuir letras repetidas.\n";
    cout << "A palarava é escolhida aleatóriamente ao iniciar o jogo.\n\n";
    cout << "Pressione qualquer tecla para voltar\n";
    pauseScreen();
    clearScreen();
}

void HUD_AdicionarPalavra(ListaPalavras &lista, string listaTermo){
    clearScreen();
    string novaPalavra;
    cout << "Digite a palavra que deseja inserir.\n";
    cin >> novaPalavra;
    novaPalavra = palavraMinusculo(novaPalavra);
    if(!validadePalavra(novaPalavra)){
        cout << "Palavra com tamanho inválido!\n";
    }else{
        if(!adiconarNovaPalavra(lista, novaPalavra)){
            cout << "Essa palavra já existe na lista.\n";
        }else{
            gravarPalavras(lista, listaTermo);
            cout << "Palavra adicionada na lista.\n";
        }
    }
    pauseScreen();
    clearScreen();
}

void HUD_RemoverPalavra(ListaPalavras &lista, string listaTermo){
    clearScreen();
    string remove;
    cout << "Digite a palavra que deseja remover.\n";
    cin >> remove;
    remove = palavraMinusculo(remove);
    if(!validadePalavra(remove)){
        cout << "Palavra com tamanho inválido!\n";
    }else{
        if(!removerPalavraExistente(lista, remove)){
            cout << "Essa palavra não existe na lista.\n";
        }else{
            gravarPalavras(lista, listaTermo);
            cout << "Palavra removida da lista.\n";
        }
    }
    pauseScreen();
    clearScreen();
}

void creditos(){
    clearScreen();
    cout << "\nUNIVERSIDADE DO VALE DO ITAJAÍ\n";
    cout << "DISCIPLINA: ESTRUTURA DE DADOS\n";
    cout << "PROFESSOR: MARCOS CARRARD\n";
    cout << "ALUNOS: HENRY JOSÉ, VINÍCIUS MEDEIROS SANTOS\n";
    cout << "CURSO: ENGENHARIA DE COMPUTAÇÃO\n";
    pauseScreen();
    clearScreen();
}

void menu(){
    string listaTermo = "palavrasTermo.txt";
    int input = 0;
    ListaPalavras lista;

    inicializarLista(lista);
    carregarPalavras(lista, listaTermo);

    do{
        cout << "\t\tTERMO\t\t\n";
        cout << " 1 - JOGAR\n 2 - COMO JOGAR\n 3 - ADICIONAR PALAVRAS\n 4 - REMOVER PALAVRAS\n 5 - LISTA DE PALAVRAS\n 6 - CRÉDITOS\n 7 - SAIR\n ESCOLHA:";
        cin >> input;
        switch(input){
            case 1:
                jogar();
                break;
            case 2:
                comoJogar();
                break;
            case 3:
                HUD_AdicionarPalavra(lista, listaTermo);
                break;
            case 4:
                HUD_RemoverPalavra(lista, listaTermo);
                break;
            case 5:
                mostrarLista(lista);
                break;
            case 6:
                creditos();
                break;
            case 7:
                //Adiconar função para liberar memória...
                cout << "Saindo...";
                break;
            default:
                cout << "Opção inválida. Digite novamente.\n";
        }
    }while(input != 7);
}