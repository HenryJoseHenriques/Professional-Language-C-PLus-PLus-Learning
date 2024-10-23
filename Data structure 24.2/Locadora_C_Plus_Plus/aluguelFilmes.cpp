#include <iostream>
using namespace std;

void inicializarAlugueis(Hash<filmeAlugado> &listaAlugados)
{
    for (int i = 0; i < TAM; i++)
    {
        inicializarLDE(listaAlugados.vetor[i]); // Inicializa cada slot da hash
    }
}

void exibirAlugueis(Hash<filmeAlugado> listaAlugados)
{
    cout << "Filmes alugados : ";
    for (int i = 0; i < TAM; i++)
    {
        No<filmeAlugado> *aux = listaAlugados.vetor[i].comeco;
        while (aux != NULL)
        {
            cout << "\tNome : " << aux->info.nomeFilme << "\n";
            cout << "\tUsuario: " << aux->info.nomeUser << "\n";
            cout << "\tData do aluguel: " << aux->info.data << "\n";
            aux = aux->eloP;
        }
    }
}

bool novoAluguel(Hash<filmes> lista, login User, filmeAlugado &instancia, filmes &alugado)
{
    int codFilme;
    cout << "\nDigite o codigo do filme que deseja alugar: \n";
    cin >> codFilme;
    cin.ignore();

    if (!retornarFilmeCod(lista, codFilme, alugado))
    {
        cout << "\nFilme nao encontrado para ser alugado\n";
        return false;
    }
    else
    {
        if (alugado.disponibilidade == "nao")
        {
            cout << "\nFilme ja esta alugado\n";
            return false;
        }
        else
        {
            instancia.codFilme = alugado.cod;
            instancia.nomeFilme = alugado.nome;
            instancia.matriculaUser = User.matricula;
            instancia.nomeUser = User.nome;
            instancia.codAluguel = cripto(instancia.nomeFilme) + cripto(instancia.nomeUser);
            cout << "\nDigite o dia do mes em que esta alugando o filme (1-31): \n";
            cin >> instancia.data;

            return true;
        }
    }
}

void retiraAluga(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator, filmes alugado)
{
    int hF = hashing(alugado.nome);
    retirarLDE(filme.vetor[hF], alugado);
    int hC = hashing(alugado.categoria);
    retirarLDE(categoria.vetor[hC], alugado);
    int hD = hashing(alugado.diretor);
    retirarLDE(diretor.vetor[hD], alugado);
    No<string> *aux = alugado.atores.comeco;
    while (aux != NULL)
    {
        int hA = hashing(aux->info);
        if (retirarLDE(ator.vetor[hA], alugado))
            ;
        aux = aux->eloP;
    }
    cout << "\nRetirado para alteracao de disponibilidade.\n";
}

void reinserirAluga(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator, filmes alugado)
{
    int hF = hashing(alugado.nome);
    inserirLDE(filme.vetor[hF], alugado);
    int hC = hashing(alugado.categoria);
    inserirLDE(categoria.vetor[hC], alugado);
    int hD = hashing(alugado.diretor);
    inserirLDE(diretor.vetor[hD], alugado);
    No<string> *aux = alugado.atores.comeco;
    while (aux != NULL)
    {
        int hA = hashing(aux->info);
        if (inserirLDE(ator.vetor[hA], alugado))
            ;
        aux = aux->eloP;
    }
    cout << "\nReinserido apos alteracao de disponibilidade\n";
}

bool pesquisaAluguelLista(LDE<filmeAlugado> lista, int codFilme, filmeAlugado &instancia)
{
    No<filmeAlugado> *aux = lista.comeco;
    while (aux != NULL)
    {
        if (aux->info.codFilme == codFilme)
        {
            instancia = aux->info;
            return true;
        }
        aux = aux->eloP;
    }
    return false;
}

bool devolverFilmeAlugado(Hash<filmes> filme, Hash<filmeAlugado> &lista, filmes &retorno)
{
    int codFilme;
    cout << "\nDigite o código do filme a ser devolvido:\n";
    cin >> codFilme;
    cin.ignore();
    filmeAlugado devolve;
    
    int hA = codFilme % TAM;
    cout << "\n" << hA << "\n";
    if (!pesquisaAluguelLista(lista.vetor[hA], codFilme, devolve))
    {
        return false;
    }
    else
    {
        retornarFilmeCod(filme, codFilme, retorno);
        retirarLDE(lista.vetor[hA], devolve);
        return true;
    }
}


// Função principal para gerenciar o aluguel de filmes
void alugarFilmes(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator, login User, string t1, string t2, string t3, string t4)
{
    string bancoAlugados = "listaAlugados.csv";
    Hash<filmeAlugado> listaAlugados;
    inicializarAlugueis(listaAlugados);
    lerCSV(listaAlugados, bancoAlugados);
    filmeAlugado instancia;
    filmes alugado;

    int opc;
    do
    {
        cout << "\tMenu de Alugueis : \n";
        cout << "\t0 - Sair\n";
        cout << "\t1 - Ver meus alugueis\n";
        cout << "\t2 - Alugar filme\n";
        cout << "\t3 - Devolver filme\n";
        cout << "\tOpcao: \n";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 0:
            liberarTabela(listaAlugados);
            break;
        case 1:
            exibirAlugueis(listaAlugados);
            break;
        case 2:
            if (novoAluguel(filme, User, instancia, alugado))
            {
                /*Processo de retirada do novo alugado para mudança de status*/
                retiraAluga(filme, categoria, diretor, ator, alugado);
                alugado.disponibilidade = "nao";
                reinserirAluga(filme, categoria, diretor, ator, alugado);
                gravarCSV(filme, t1);
                gravarCSV(categoria, t2);
                gravarCSV(diretor, t3);
                gravarCSV(ator, t4);
                /*Processo de inserção do aluguel */
                int hAl = instancia.codFilme % TAM;
                cout << "\n" << hAl << "\n";
                inserirLDE(listaAlugados.vetor[hAl], instancia); // Insere o novo aluguel na lista
                gravarCSV(listaAlugados, bancoAlugados);
                cout << "\nFilme alugado com sucesso !\n";
            }
            else
            {
                cout << "\nNão foi possível realizar o aluguel.\n";
            }
            break;
        case 3:
            if (devolverFilmeAlugado(filme, listaAlugados, alugado))
            {
                /*Processo de retirada do novo alugado para mudança de status*/
                retiraAluga(filme, categoria, diretor, ator, alugado);
                alugado.disponibilidade = "sim";
                reinserirAluga(filme, categoria, diretor, ator, alugado);
                gravarCSV(filme, t1);
                gravarCSV(categoria, t2);
                gravarCSV(diretor, t3);
                gravarCSV(ator, t4);
                /*Processo de reinserção do aluguel*/
                gravarCSV(listaAlugados, bancoAlugados);
                cout << "\nFilme disponivel para aluguel\n";
            }
            else
            {
                cout << "\nEsse filme esta disponivel para ser alugado\n";
            }
            break;
        default:
            cout << "\nOpção inválida !\n";
        }
    } while (opc > 0);
}
