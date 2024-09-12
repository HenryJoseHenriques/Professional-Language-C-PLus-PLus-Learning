#ifndef LUE_hpp
#define LUE_hpp

#include <iostream>
#include <string>
using namespace std;

// lista, imitei a do professor
struct NoPalavra
{
    string palavra;
    NoPalavra *proximo = NULL;
}; 

struct ListaPalavras
{
    NoPalavra *comeco = NULL;
    NoPalavra *fim = NULL;
};

// aqui   pra ser tudo oq tem haver com as palavras
void inicializarLista(ListaPalavras &lista);
void inserirPalavra(ListaPalavras &lista, string palavra);
bool removerPalavra(ListaPalavras &lista, string palavra);
void mostrarLista(ListaPalavras lista); // meti isso daqui pra checa c ta tudo certo deixar como comentario ate a hora do teste
bool pesquisarLista(ListaPalavras lista, string palavra);

void carregarPalavras(ListaPalavras &lista, string nomeArquivo);
void gravarPalavras(ListaPalavras lista, string nomeArquivo);
int tamanhoLista(ListaPalavras lista);

//   pra ser o jogo na teoria
void verificarPalavra(string palavraSecreta, string tentativa);
void jogar(ListaPalavras &lista, int numPalavras);
void liberarLista(ListaPalavras &lista);

// eu fui adicionando pra ter uma base doq precisa ter pode mexer e tirar algo c tu n acha necessario

#endif
