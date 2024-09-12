#include <iostream>
#include <fstream>
using namespace std;

void carregarPalavras(ListaPalavras &lista, string nomeArquivo)
{ // carrega de um arquivo, copiei de um trabalho meu de algor 2
    ifstream arquivo(nomeArquivo);
    string palavra;
    if (arquivo.is_open())
    {
        while (getline(arquivo, palavra))
        {
            inserirPalavra(lista, palavra);
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

void gravarPalavras(ListaPalavras lista, string nomeArquivo)
{
    ofstream arquivo(nomeArquivo);
    NoPalavra *atual = lista.comeco;
    if (arquivo.is_open())
    {
        while (atual != NULL)
        {
            arquivo << atual->palavra << endl;
            atual = atual->proximo;
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}