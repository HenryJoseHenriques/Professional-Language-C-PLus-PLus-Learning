#include <iostream>
#include <cctype>
#include <string>
#include <random>
#include <time.h>

using namespace std;

string palavraMinusculo(string palavra)
{
    for (char &c : palavra)
    {
        c = tolower(c);
    }
    return palavra;
}

string removeracentos(string palavra)
{
    string revAcen = palavra;
    for (int i = 0; revAcen[i] != '\0'; i++)
    {
        if (revAcen[i] == 'á' || revAcen[i] == 'à' || revAcen[i] == 'â' || revAcen[i] == 'ã')
        {
            revAcen[i] = 'a';
        }
        if (revAcen[i] == 'é' || revAcen[i] == 'è' || revAcen[i] == 'ê')
        {
            revAcen[i] = 'e';
        }
        if (revAcen[i] == 'ó' || revAcen[i] == 'ò' || revAcen[i] == 'õ')
        {
            revAcen[i] = 'o';
        }
        if (revAcen[i] == 'í' || revAcen[i] == 'ì' || revAcen[i] == 'î')
        {
            revAcen[i] = 'i';
        }
        if (revAcen[i] == 'ú' || revAcen[i] == 'ù' || revAcen[i] == 'û')
        {
            revAcen[i] = 'u';
        }
        if (revAcen[i] == 'ç')
        {
            revAcen[i] = 'c';
        }
    }
    return revAcen;
}

bool validadePalavra(string palavra)
{
    if (palavra.size() == 5)
        return true;
    return false;
}

int numRandomico(ListaPalavras lista)
{
    srand(time(NULL));
    return rand() % tamanhoLista(lista) + 1;
}