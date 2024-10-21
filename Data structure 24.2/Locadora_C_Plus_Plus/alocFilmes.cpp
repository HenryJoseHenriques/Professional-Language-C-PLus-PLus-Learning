#include <iostream>
using namespace std;

string escreverNome()
{
    string nome;
    cout << "Digite o nome do filme\n";
    getline(cin, nome);
    clearScreen();
    return nome;
}

string escreverDiretor()
{
    string diretor;
    cout << "Digite o nome do diretor do filme\n";
    getline(cin, diretor);
    clearScreen();
    return diretor;
}

string escreverCategoria()
{
    string categoria;
    cout << "Digite a categoria do filme\n";
    getline(cin, categoria);
    clearScreen();
    return categoria;
}

LDE<string> escreverAtores()
{
    LDE<string> atores;
    string ator;
    inicializarLDE(atores);
    while (true)
    {
        cout << "Digite o nome de um ator do filme, ou digite S para finalizar a listagem de atores\n";
        getline(cin, ator);
        clearScreen();
        if (ator == "S" || ator == "s")
            break;
        inserirFinalLDE(atores, ator);
    }
    return atores;
}

filmes criarFilme()
{
    filmes novo;

    novo.nome = escreverNome();
    novo.diretor = escreverDiretor();
    novo.atores = escreverAtores();
    novo.categoria = escreverCategoria();
    novo.cod = cripto(novo.nome); // Será o código utilizado para pesquisa.

    return novo;
}

bool inicializarListas(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &ator)
{
    for (int i = 0; i < TAM; i++)
    {
        inicializarLDE(filme.vetor[i]); // será a lista de pesquisa categoria e código
        inicializarLDE(categoria.vetor[i]);
        inicializarLDE(diretor.vetor[i]);
        inicializarLDE(ator.vetor[i]);
    }
    return true;
}

bool addPorFilme(Hash<filmes> &lista, filmes novo)
{
    int h = hashing(novo.nome);
    if (pesquisarLDE(lista.vetor[h], novo))
    {
        return false;
    }
    else
    {
        inserirFinalLDE(lista.vetor[h], novo);
        return true;
    }
}

bool addPorCategoria(Hash<filmes> &lista, filmes novo)
{
    int h = hashing(novo.categoria);
    if (pesquisarLDE(lista.vetor[h], novo))
    {
        return false;
    }

    else
    {
        inserirFinalLDE(lista.vetor[h], novo);
        return true;
    }
}

bool addPorDiretor(Hash<filmes> &lista, filmes novo)
{
    int h = hashing(novo.diretor);
    if (pesquisarLDE(lista.vetor[h], novo))
    {
        return false;
    }
    else
    {
        inserirFinalLDE(lista.vetor[h], novo);
        return true;
    }
}

bool addPorAtor(Hash<filmes> &lista, filmes novo)
{
    No<string> *aux = novo.atores.comeco;
    while (aux != NULL)
    {
        int h = hashing(aux->info);
        if (pesquisarLDE(lista.vetor[h], novo))
        {
            cout << "Essa lista de atores ja possui esse filme.\n";
        }
        else
        {
            inserirFinalLDE(lista.vetor[h], novo);
        }
        aux = aux->eloP;
    }
    return true;
}

bool retornarFilmeF(Hash<filmes> filme, string dado, filmes &remove)
{
    int hF = hashing(dado);
    No<filmes> *aux = filme.vetor[hF].comeco;
    while (aux != NULL)
    {
        if (aux->info.nome == dado)
        {
            remove = aux->info;
            return true;
        }
        aux = aux->eloP;
    }
    return false;
}

bool retornarFilmeD(Hash<filmes> filme, string diretor, filmes &remove)
{
    int hF = hashing(diretor);
    No<filmes> *aux = filme.vetor[hF].comeco;
    while (aux != NULL)
    {
        if (aux->info.diretor == diretor)
        {
            remove = aux->info;
            return true;
        }
        aux = aux->eloP;
    }
    return false;
}

bool retornarFilmeC(Hash<filmes> filme, string categoria, filmes &remove)
{
    int hF = hashing(categoria);
    No<filmes> *aux = filme.vetor[hF].comeco;
    while (aux != NULL)
    {
        if (aux->info.categoria == categoria)
        {
            remove = aux->info;
            return true;
        }
        aux = aux->eloP;
    }
    return false;
}

bool retornarFilmeA(Hash<filmes> filme, string ator, filmes &remove)
{
    int hF = hashing(ator);
    No<filmes> *aux = filme.vetor[hF].comeco;
    while (aux != NULL)
    {
        No<string> *atores = aux->info.atores.comeco;
        while (atores != NULL)
        {
            if (atores->info == ator)
            {
                remove = aux->info;
                return true;
            }
            atores = atores->eloP;
        }
        aux = aux->eloP;
    }
    return false; 
}


bool retornarFilmeCod(Hash<filmes> filme, int cod, filmes &remove)
{
    int hF = cod % TAM;
    No<filmes> *aux = filme.vetor[hF].comeco;
    while (aux != NULL)
    {
        if (aux->info.cod == cod)
        {
            remove = aux->info;
            return true;
        }
        aux = aux->eloP;
    }
    return false;
}