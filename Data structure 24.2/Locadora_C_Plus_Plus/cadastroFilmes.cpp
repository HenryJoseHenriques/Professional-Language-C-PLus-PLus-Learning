#include "lde.hpp"
#include "console.cpp"
#include "hashing.cpp"
#include "alocFilmes.cpp"
#include "files.cpp"
#include <iostream>
using namespace std;

void cadastrarFilme(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator)
{
    filmes novo = criarFilme();
    if (addPorFilme(filme, novo))
        cout << "Inserido na lista de Filmes.\n";
    else
        cout << "Filme ja inserido na Hash de Filmes.\n";

    if (addPorCategoria(categoria, novo))
        cout << "Inserido na lista de Categorias.\n";

    if (addPorDiretor(diretor, novo))
        cout << "Inserido na lista de Diretores.\n";
    else
        cout << "Filme ja inserido na lista de Diretores.\n";

    if (addPorAtor(ator, novo))
        cout << "Inserido na lista de Atores.\n";
    else
        cout << "Filme ja inserido na lista de Atores.\n";
}

bool removerFilmedasListas(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator)
{
    string nome;
    filmes remove;
    cout << "Digite o nome que deseja remover:";
    // cin >> nome;
    getline(cin, nome);

    int hF = hashing(nome);
    LDE<filmes> auxF = filme.vetor[hF];
    if (!retornarFilmeF(filme, nome, remove))
    {
        cout << "Filme NAO localizado para remocao.\n";
        return false;
    }
    else
    {
        cout << "Filme localizado para remocao.\n";

        if (retirarLDE(filme.vetor[hF], remove))
            cout << "\tRetirado da tabela de Filmes.\n";

        int hC = hashing(auxF.comeco->info.categoria);
        if (retirarLDE(categoria.vetor[hC], remove))
            cout << "\tRetirado da tabela de categorias.\n";

        int hD = hashing(auxF.comeco->info.diretor);
        if (retirarLDE(diretor.vetor[hD], remove))
            cout << "\tRetirado da tabela de diretores.\n";

        No<string> *aux = remove.atores.comeco;
        while (aux != NULL)
        {
            int hA = hashing(aux->info);
            if (retirarLDE(ator.vetor[hA], remove))
                ;
            cout << "\tRetirado da tabela de Atores para o ator " << aux->info << ".\n";
            aux = aux->eloP;
        }
        return true;
    }
}

bool alterarFilmes(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator)
{
    int cod;
    filmes altera;
    cout << "Digite o codigo do filme que deseja alterar os dados:";
    cin >> cod;

    int hF = cod % TAM;
    LDE<filmes> auxF = filme.vetor[hF];
    if (!retornarFilmeCod(filme, cod, altera))
    {
        cout << "Filme NAO localizado para alteracao.\n";
        return false;
    }
    else
    {
        cout << "Filme localizado para alteracao.\n";

        /*Filme isolado da tabela*/
        if (retirarLDE(filme.vetor[hF], altera))
            cout << "\tIsolado da tabela de Filmes.\n";

        int hC = hashing(auxF.comeco->info.categoria);
        if (retirarLDE(categoria.vetor[hC], altera))
            cout << "\tIsolado da tabela de categorias.\n";

        int hD = hashing(auxF.comeco->info.diretor);
        if (retirarLDE(diretor.vetor[hD], altera))
            cout << "\tIsolado da tabela de diretores.\n";
        No<string> *aux = altera.atores.comeco;
        while (aux != NULL)
        {
            int hA = hashing(aux->info);
            if (retirarLDE(ator.vetor[hA], altera))
                ;
            cout << "\tIsolado da tabela de Atores para o ator " << aux->info << ".\n";
            aux = aux->eloP;
        }

        /*Realização das modificações. */
        int opc;
        do
        {
            cout << "\n";
            cout << "\tSelecione a opcao que deseja alterar:\n";
            cout << "\t0 - Sair\n";
            cout << "\t1 - Nome\n";
            cout << "\t2 - Diretor\n";
            cout << "\t3 - Atores\n";
            cout << "\t4 - Categoria\n\n";
            cin >> opc;
            cin.ignore();
            switch (opc)
            {
            case 0:
                break;
            case 1:
                altera.nome = escreverNome();
                break;
            case 2:
                altera.diretor = escreverDiretor();
                break;
            case 3:
                altera.atores = escreverAtores();
                break;
            case 4:
                altera.categoria = escreverCategoria();
                break;
            default:
                cout << "\nOpcao invalida\n";
                break;
            }
        } while (opc > 0);

        /*Inserção das modificações */
        if (addPorFilme(filme, altera) && addPorCategoria(categoria, altera) && addPorDiretor(diretor, altera) && addPorAtor(ator, altera))
        {
            cout << "\nAlteracoes realizadas com sucesso";
            return true;
        }
        else
        {
            cout << "\nOcoreu um erro ao tentar realizar alteracoes\n";
            return false;
        }
    }
}

bool pesquisarPorCod(Hash<filmes> lista)
{
    int cod;
    filmes pesquisa;
    cout << "Digite o codigo do filme que deseja pesquisar: ";
    cin >> cod;
    // getline(cin,cod);
    cout << "\nFilme encontrado do codigo: " << cod << "\n";
    if (!retornarFilmeCod(lista, cod, pesquisa))
    {
        cout << "Filme não presente na lista por codigo\n";
        return false;
    }
    else
    {
        int h = cod % TAM;
        No<filmes> *aux = lista.vetor[h].comeco;
        while (aux != NULL)
        {
            if (aux->info.cod == cod)
            {
                cout << "\nFilme: " << aux->info.nome;
                cout << "\nCategoria: " << aux->info.categoria;
                cout << "\nDiretor: " << aux->info.diretor;
                cout << "\nAtores: ";
                No<string> *atores = aux->info.atores.comeco;
                while (atores != NULL)
                {
                    cout << "\n\t" << atores->info;
                    atores = atores->eloP;
                }
                cout << "\n";
            }
            aux = aux->eloP;
        }
        return true;
    }
}

bool pesquisarPorFilme(Hash<filmes> lista)
{
    string nome;
    filmes pesquisa;
    cout << "Digite o nome do filme que deseja pesquisa: ";
    // cin >> nome;
    getline(cin, nome);
    cout << "\nFilme encontrado com o nome: " << nome << "\n";
    if (!retornarFilmeF(lista, nome, pesquisa))
    {
        cout << "\nFilme nao presente na listagem.\n";
        return false;
    }
    else
    {
        int h = hashing(nome);
        No<filmes> *aux = lista.vetor[h].comeco;
        while (aux != NULL)
        {
            if (aux->info.nome == nome)
            {
                cout << "\nCodigo: " << aux->info.cod;
                cout << "\nFilme: " << aux->info.nome;
                cout << "\nCategoria: " << aux->info.categoria;
                cout << "\nDiretor: " << aux->info.diretor;
                cout << "\nAtores: ";
                No<string> *atores = aux->info.atores.comeco;
                while (atores != NULL)
                {
                    cout << "\n\t" << atores->info;
                    atores = atores->eloP;
                }
                cout << "\n";
            }
            aux = aux->eloP;
        }
        return true;
    }
}

bool pesquisarPorCategoria(Hash<filmes> lista)
{
    string categoria;
    filmes pesquisa;
    cout << "Digite a categoria dos filmes que deseja pesquisa: ";
    // cin >> categoria;
    getline(cin, categoria);
    cout << "\nFilme encontrado com a categoria: " << categoria << "\n";
    if (!retornarFilmeC(lista, categoria, pesquisa))
    {
        cout << "\nFilme dessa categoria não presente.\n";
        return false;
    }
    else
    {
        int h = hashing(categoria);
        No<filmes> *aux = lista.vetor[h].comeco;
        while (aux != NULL)
        {
            if (aux->info.categoria == categoria)
            {
                cout << "\nFilme: " << aux->info.nome;
                cout << "\nDiretor: " << aux->info.diretor;
                cout << "\nAtores: ";
                No<string> *atores = aux->info.atores.comeco;
                while (atores != NULL)
                {
                    cout << "\n\t" << atores->info;
                    atores = atores->eloP;
                }
                cout << "\n";
            }
            aux = aux->eloP;
        }
        return true;
    }
}

bool pesquisarPorDiretor(Hash<filmes> lista)
{
    string diretor;
    filmes pesquisa;
    cout << "Digite o nome do diretor dos filmes que deseja pesquisa: ";
    getline(cin, diretor);
    cout << "\nFilme encontrado com o diretor: " << diretor << "\n";
    if (!retornarFilmeD(lista, diretor, pesquisa))
    {
        cout << "\nFilme com esse diretor nao encontrado.\n";
        return false;
    }
    else
    {
        int h = hashing(diretor);
        No<filmes> *aux = lista.vetor[h].comeco;
        while (aux != NULL)
        {
            if (aux->info.diretor == diretor)
            {
                cout << "\nCodigo: " << aux->info.cod;
                cout << "\nFilme: " << aux->info.nome;
                cout << "\nAtores: ";
                No<string> *atores = aux->info.atores.comeco;
                while (atores != NULL)
                {
                    cout << "\n\t" << atores->info;
                    atores = atores->eloP;
                }
                cout << "\n";
            }
            aux = aux->eloP;
        }
        return true;
    }
}

bool pesquisarPorAtor(Hash<filmes> lista)
{
    string ator;
    filmes pesquisa;
    cout << "Digite o ator dos filmes que deseja pesquisa: ";
    // cin >> ator;
    getline(cin, ator);
    cout << "\nFilme encontrado do ator: " << ator << "\n";
    if (!retornarFilmeA(lista, ator, pesquisa))
    {
    }
    else
    {
        int h = hashing(ator);
        No<filmes> *aux = lista.vetor[h].comeco;

        while (aux != NULL)
        {
            No<string> *atores = aux->info.atores.comeco;
            while (atores != NULL)
            {
                if (atores->info == ator)
                {
                    cout << "\nCodigo: " << aux->info.cod;
                    cout << "\nFilme: " << aux->info.nome;
                    cout << "\nCategoria: " << aux->info.categoria;
                    cout << "\nDiretor: " << aux->info.diretor;
                    cout << "\n";
                }
                atores = atores->eloP;
            }
            aux = aux->eloP;
        }
    }
}

void tiposDePesquisa(Hash<filmes> filme, Hash<filmes> categoria, Hash<filmes> diretor, Hash<filmes> ator)
{
    int opc;
    do
    {
        cout << "Pesquisar por:\n";
        cout << "\t0 - sair\n";
        cout << "\t1 - codigo\n";
        cout << "\t2 - filme\n";
        cout << "\t3 - categoria\n";
        cout << "\t4 - diretor\n";
        cout << "\t5 - ator\n";
        cin >> opc;
        cin.ignore();
        switch (opc)
        {
        case 0:
            break;
        case 1:
            pesquisarPorCod(filme);
            break;
        case 2:
            pesquisarPorFilme(filme);
            break;
        case 3:
            pesquisarPorCategoria(categoria);
            break;
        case 4:
            pesquisarPorDiretor(diretor);
            break;
        case 5:
            pesquisarPorAtor(ator);
            break;
        default:
            cout << "Opcao invalida\n";
        }
    } while (opc > 0);
}

void listarFilmes(Hash<filmes> filme)
{
    cout << "Lista de filmes disponiveis na locadora: \n";

    for (int i = 0; i < TAM; i++)
    {
        cout << i << " => \n";
        No<filmes> *aux = filme.vetor[i].comeco;
        while (aux != NULL)
        {
            cout << "\tCodigo: " << aux->info.cod << "\n";
            cout << "\tFilme: " << aux->info.nome << "\n";
            cout << "\tCategoria: " << aux->info.categoria << "\n";
            cout << "\tDiretor: " << aux->info.diretor << "\n";
            cout << "\tAtores: ";
            No<string> *atores = aux->info.atores.comeco;
            while (atores != NULL)
            {
                cout << atores->info << "\t";
                atores = atores->eloP;
            }
            aux = aux->eloP;
            cout << "\n\n";
        }
    }
}

void insercaoDisco(Hash<filmes> filme, Hash<filmes> categoria, Hash<filmes> diretor, Hash<filmes> ator, string t1, string t2, string t3, string t4)
{
    gravarCSV(filme, t1);
    gravarCSV(categoria, t2);
    gravarCSV(diretor, t3);
    gravarCSV(ator, t4);
    cout << "\nGravado nos CSV\n";
}

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
             << "\tOpcao: ";
        cin >> opc;
        cin.ignore();
        clearScreen();
        switch (opc)
        {
        case 0:
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
        default:
            cout << "Opcao invalida.\n";
        }

    } while (opc > 0);
}