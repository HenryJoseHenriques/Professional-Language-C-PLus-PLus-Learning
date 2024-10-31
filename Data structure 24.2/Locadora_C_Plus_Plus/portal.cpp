#include "console.cpp"
#include "lde.hpp"
#include "hashing.cpp"
#include "alocFilmes.cpp"
#include "files.cpp"
#include "aluguelFilmes.cpp"
#include "cadastroFilmes.cpp"
#include "cadastroUsuario.cpp"
#include <iostream>
using namespace std;

void menuLocadora() {
    string t1 = "ListaFilmes.csv";
    string t2 = "ListaCategorias.csv";
    string t3 = "ListaDiretor.csv";
    string t4 = "ListaAtores.csv";

    Hash<filmes> filme, categoria, diretor, atores;
    inicializarListas(filme, categoria, diretor, atores);
    lerCSV(filme, t1);
    lerCSV(categoria, t2);
    lerCSV(diretor, t3);
    lerCSV(atores, t4);

    int opc;
    do {
        clearScreen();
        cout << "===============================" << endl;
        cout << "    Menu da Locadora de Filmes  " << endl;
        cout << "===============================" << endl;
        cout << "0 - Finalizar" << endl;
        cout << "1 - Cadastrar Filme" << endl;
        cout << "2 - Remover Filme" << endl;
        cout << "3 - Alterar Filme" << endl;
        cout << "4 - Pesquisar Filme" << endl;
        cout << "5 - Listar Filmes" << endl;
        cout << "6 - Entrar no Portal do Usuário" << endl;
        cout << "===============================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 0:
                liberarTabela(filme);
                liberarTabela(categoria);
                liberarTabela(diretor);
                liberarTabela(atores);
                cout << "Sistema finalizado. Até logo!" << endl;
                break;
            case 1:
                cadastrarFilme(filme, categoria, diretor, atores);
                gravarCSV(filme, t1);
                gravarCSV(categoria, t2);
                gravarCSV(diretor, t3);
                gravarCSV(atores, t4);
                cout << "Filme cadastrado com sucesso!" << endl;
                break;
            case 2:
                if (removerFilmedasListas(filme, categoria, diretor, atores)) {
                    cout << "Filme removido com sucesso!" << endl;
                    gravarCSV(filme, t1);
                    gravarCSV(categoria, t2);
                    gravarCSV(diretor, t3);
                    gravarCSV(atores, t4);
                } else {
                    cout << "Não foi possível remover o filme." << endl;
                }
                break;
            case 3:
                if (alterarFilmes(filme, categoria, diretor, atores)) {
                    cout << "Filme alterado com sucesso!" << endl;
                    gravarCSV(filme, t1);
                    gravarCSV(categoria, t2);
                    gravarCSV(diretor, t3);
                    gravarCSV(atores, t4);
                } else {
                    cout << "Alterações não refletiram no disco." << endl;
                }
                break;
            case 4:
                tiposDePesquisa(filme, categoria, diretor, atores);
                break;
            case 5:
                listarFilmes(filme);
                break;
            case 6:
                entrarNoPortal(filme, categoria, diretor, atores, t1, t2, t3, t4);
                break;
            default:
                cout << "Opção inválida. Por favor, tente novamente." << endl;
                break;
        }

        cout << "Pressione Enter para continuar...";
        cin.ignore();

    } while (opc != 0);
}