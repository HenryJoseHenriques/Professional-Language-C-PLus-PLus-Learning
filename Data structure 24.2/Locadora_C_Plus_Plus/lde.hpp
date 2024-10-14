#include <iostream>
using namespace std;

struct filme
{
    string nome;
    string diretor;
    string atores;
    string categoria;
    int tempo;
    int cod;
};

filme addFilme(string nome, string diretor, string atores, string categoria,int tempo,int cod)
{
    filme novo;
    novo.atores = atores;
    novo.diretor = diretor;
    novo.nome = nome;
    novo.tempo = tempo;
    novo.categoria = categoria;
    novo.cod = cod;
    return novo;
}

struct No
{
    filme info;
    No *eloA = NULL;
    No *eloP = NULL;
};

struct LDE
{
    No *comeco = NULL;
    No *fim = NULL;
};

void inicializarLDE(LDE &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

bool inserirFinalLDE(LDE &lista, filme valor)
{
    No *novo = new No;

    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (lista.comeco == NULL)
    { // Caso 1 - lista vazia
        lista.comeco = novo;
        lista.fim = novo;
    }
    else
    { // Caso 2 - Inserir no final
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
    }
    return true;
}

bool inserirLDE(LDE &lista, filme valor)
{
    No *novo = new No;

    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (lista.comeco == NULL)
    { // Caso A
        lista.comeco = novo;
        lista.fim = novo;
    }
    else if (valor.nome <= lista.comeco->info.nome)
    { // Caso B
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
    }
    else if (valor.nome > lista.fim->info.nome)
    { // Caso C
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
    }
    else
    { // Caso D
        No *aux = lista.comeco;
        while (aux != NULL)
        {
            No *prox = aux->eloP;
            if (aux->info.nome <= valor.nome && valor.nome < prox->info.nome)
            {
                aux->eloP = novo;
                prox->eloA = novo;
                novo->eloA = aux;
                novo->eloP = prox;
                break;
            }
            aux = aux->eloP;
        }
    }
    return true;
}

bool retirarLDE(LDE &lista, filme valor)
{
    if (lista.comeco == NULL)
        return false;
    No *aux, *ant, *prox;

    if (valor.cod == lista.comeco->info.cod)
    {
        aux = lista.comeco;
        if (valor.cod == lista.fim->info.cod)
        { // Caso a
            lista.comeco = NULL;
            lista.fim = NULL;
        }
        else
        { // Caso b
            lista.comeco = aux->eloP;
            lista.comeco->eloA = NULL;
        }
    }
    else
    {
        if (valor.cod == lista.fim->info.cod)
        { // Caso c
            aux = lista.fim;
            lista.fim = aux->eloA;
            lista.fim->eloP = NULL;
        }
        else
        { // Caso d
            aux = lista.comeco;
            while (aux != NULL)
            {
                if (aux->info.cod == valor.cod)
                {
                    ant = aux->eloA;
                    prox = aux->eloP;
                    ant->eloP = prox;
                    prox->eloA = ant;
                    break;
                }
                aux = aux->eloP;
            }
            if (aux == NULL)
                return false;
        }
    }

    delete aux;
    return true;
}

void mostrarLDE(LDE lista, char ordem)
{
    if (ordem == 'C' || ordem == 'c') 
    {
        No *aux = lista.comeco;
        filme infos = aux->info;
        while (aux != NULL)
        {
            cout << infos.nome << "\n" << infos.diretor << "\n" << infos.categoria << "\n" << infos.tempo << "\n";
            aux = aux->eloP; // Avan�a para o pr�ximo no
        }
    }
    else
    {
        No *aux = lista.fim;
        filme infos = aux->info;
        while (aux != NULL)
        {
            cout << infos.nome << "\n" << infos.diretor << "\n" << infos.categoria << "\n" << infos.tempo << "\n";
            aux = aux->eloA; // Avan�a para o no anterior
        }
    }
}

void liberarLDE(LDE &lista)
{
    No *temp, *aux = lista.comeco;
    while (aux != NULL)
    {
        temp = aux;
        aux = aux->eloP;
        delete temp;
    }
    lista.comeco = lista.fim = NULL;
}

bool pesquisarLDE(LDE lista, filme valor)
{
    No *aux = lista.comeco;
    while (aux != NULL)
    {
        if (aux->info.nome == valor.nome)
            return true;
        aux = aux->eloP;
    }
    return false;
}

