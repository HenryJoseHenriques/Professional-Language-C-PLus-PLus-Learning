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

void menuLocadora()
{
    string t1, t2, t3, t4;
    t1 = "ListaFilmes.csv";
    t2 = "ListaCategorias.csv";
    t3 = "ListaDiretor.csv";
    t4 = "ListaAtores.csv";

    Hash<filmes> filme, categoria, diretor, atores;
    inicializarListas(filme, categoria, diretor, atores);
    lerCSV(filme, t1);
    lerCSV(categoria, t2);
    lerCSV(diretor, t3);
    lerCSV(atores, t4);

    int opc;
    do
    {
        cout << endl
             << "Menu da locadora de filmes:";
        cout << endl
             << "\t0 - Finalizar";
        cout << endl
             << "\t1 - Cadastrar";
        cout << endl
             << "\t2 - Remover";
        cout << endl
             << "\t3 - Alterar";
        cout << endl
             << "\t4 - Pesquisar";
        cout << endl
             << "\t5 - Listar";
        cout << endl
             << "\t6 - Entrar";
        cout << endl
             << "\tOpcao: ";
        cin >> opc;
        cin.ignore();
        clearScreen();
        switch (opc)
        {
        case 0:
            liberarTabela(filme);
            liberarTabela(categoria);
            liberarTabela(diretor);
            liberarTabela(atores);
            break;
        case 1:
            cadastrarFilme(filme, categoria, diretor, atores);
            gravarCSV(filme, t1);
            gravarCSV(categoria, t2);
            gravarCSV(diretor, t3);
            gravarCSV(atores, t4);
            break;
        case 2:
            if (removerFilmedasListas(filme, categoria, diretor, atores))
            {
                cout << "Filme totalmente removido\n";
                gravarCSV(filme, t1);
                gravarCSV(categoria, t2);
                gravarCSV(diretor, t3);
                gravarCSV(atores, t4);
            }
            else
            {
                cout << "Não foi possível remover o filme.\n|";
            }
            break;
        case 3:
            if (alterarFilmes(filme, categoria, diretor, atores))
            {
                cout << "\nFilme devidamente alterado\n";
                gravarCSV(filme, t1);
                gravarCSV(categoria, t2);
                gravarCSV(diretor, t3);
                gravarCSV(atores, t4);
            }
            else
            {
                cout << "\nAlteracoes nao refletiram no disco\n";
            }
            break;
        case 4:
            tiposDePesquisa(filme, categoria, diretor, atores);
            break;
        case 5:
            listarFilmes(filme);
            break;
        case 6:
            entrarNoPortal(filme, categoria, diretor, atores, t1,t2,t3,t4);
            break;
        default:
            cout << "Opcao invalida.\n";
        }

    } while (opc > 0);
}