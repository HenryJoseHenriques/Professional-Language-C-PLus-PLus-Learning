// alt + shif + f = endentação
#include <iostream>
#include "lue.hpp"

// using namespace std;

string gerarPalavraSecreta(ListaPalavras lista)
{
    int p = numRandomico(lista);
    int c = 0;
    NoPalavra *atual = lista.comeco;

    while (c < p)
    {
        atual = atual->proximo;
        c++;
    }
    return atual->palavra;
}

void preencherPalavrasSecretas(ListaPalavras lista, string palavraSecreta[])
{
    for (int i = 0; i < 10; i++)
    {
        bool palavraRepetida;
        do
        {
            palavraRepetida = false; // Assume que a palavra n�o � repetida
            palavraSecreta[i] = gerarPalavraSecreta(lista);
            for (int j = 0; j < i; j++)
            {
                if (palavraSecreta[i] == palavraSecreta[j])
                {
                    palavraRepetida = true;
                    break;
                }
            }
        } while (palavraRepetida);
    }
}

void verificarTentativa(string tentativa, string palavraSecreta)
{
    colorScreen cor;
    for (int j = 0; j < tentativa.size(); j++)
    {
        if (tentativa[j] == palavraSecreta[j])
        {
            // Letra est� na posi��o correta
            cout << cor.green << tentativa[j] << cor.reset;
        }
        else if (palavraSecreta.find(tentativa[j]) != string::npos)
        {
            // Letra est� na palavra mas na posi��o errada
            cout << cor.yellow << tentativa[j] << cor.reset;
        }
        else
        {
            // Letra n�o est� na palavra
            cout << tentativa[j];
        }
    }
    cout << endl;
}

// Precisa terminar
void preencherAlfabeto(string palavraUsuario, string palavraSecreta)
{
    char alfabetoMinusculo[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'};
}

void ranking(int c)
{
    cout << "\nProgresso: ";
    switch (c)
    {
    case 1:
        cout << "�TIMO, DE PRIMEIRA.\n";
        break;
    case 2:
        cout << "BOM, NA SEGUNDA TENTATIVA.\n";
        break;
    case 3:
        cout << "LEGAL, NA TERCEIRA TENTATIVA.\n";
        break;
    case 4:
        cout << "MEDIANO, NA QUARTA TENTATIVA.\n";
        break;
    case 5:
        cout << "POR POUCO, NA QUINTA TENTATIVA.\n";
        break;
    case 6:
        cout << "NA RISCA, NA �LTIMA TENTATIVA.\n";
        break;
    }
}

void termo(ListaPalavras lista, string palavraSecreta)
{
    ListaTentativas listaTentativas;
    inicializarTentativas(listaTentativas);
    bool vitoria = false;
    colorScreen cor; // Instância para as cores

    for (int i = 1; i <= 6; i++)
    {
        string usuarioTentativa;
        cout << "Tentativa " << i << ": ";
        cin >> usuarioTentativa;

        if (validadePalavra(palavraMinusculo(usuarioTentativa)))
        {
            // usuarioTentativa = palavraMinusculo(usuarioTentativa);

            // Insere a tentativa na lista de tentativas
            inserirTentativa(listaTentativas, usuarioTentativa);

            if (usuarioTentativa == palavraSecreta)
            {
                vitoria = true;
                cout << "Parabéns, você acertou!\n";
                ranking(i);
                pauseScreen();
                break;
            }
            else
            {
                // Exibe a tentativa com as cores correspondentes
                for (int j = 0; j < usuarioTentativa.size(); j++)
                {
                    if (usuarioTentativa[j] == palavraSecreta[j])
                    {
                        // Letra está na posição correta
                        cout << cor.green << usuarioTentativa[j] << cor.reset;
                    }
                    else if (palavraSecreta.find(usuarioTentativa[j]) != string::npos)
                    {
                        // Letra está na palavra mas na posição errada
                        cout << cor.yellow << usuarioTentativa[j] << cor.reset;
                    }
                    else
                    {
                        // Letra não está na palavra
                        cout << usuarioTentativa[j];
                    }
                }
                cout << endl;
                //  ranking(i);
            }
        }
        else
        {
            cout << "Palavra com tamanho inválido.\n";
            i--;
        }
    }
    if (!vitoria)
    {
        cout << "Você perdeu. A palavra correta era: " << palavraSecreta << "\n";
        pauseScreen();
    }

    // Liberar memória das tentativas
    liberarTentativas(listaTentativas);
}

void dueto(ListaPalavras lista, string palavra[])
{
    ListaTentativas listaTentativas;
    inicializarTentativas(listaTentativas);
    bool vitoria1 = false, vitoria2 = false;
    colorScreen cor;

    for (int i = 1; i <= 8; i++)
    {
        string usuarioTentativa;
        cout << "Tentativa " << i << " (dueto): ";
        cin >> usuarioTentativa;

        if (validadePalavra(palavraMinusculo(usuarioTentativa)))
        {
            // Insere a tentativa na lista de tentativas
            inserirTentativa(listaTentativas, usuarioTentativa);

            if (vitoria1 == false)
            {
                // Verifica e exibe a tentativa para a primeira palavra secreta
                cout << "Palavra 1: ";
                verificarTentativa(usuarioTentativa, palavra[1]);
                if (usuarioTentativa == palavra[1])
                {
                    vitoria1 = true;
                }
            }

            if (vitoria2 == false)
            {
                // Verifica e exibe a tentativa para a segunda palavra secreta
                cout << "Palavra 2: ";
                verificarTentativa(usuarioTentativa, palavra[2]);
                if (usuarioTentativa == palavra[2])
                {
                    vitoria2 = true;
                }
            }

            if (vitoria1 && vitoria2)
            {
                cout << "Parab�ns, voc� acertou ambas as palavras!\n";
                ranking(i);
                pauseScreen();
                break;
            }
        }
        else
        {
            cout << "Palavra com tamanho inválido.\n";
            i--;
        }
    }
    if (!vitoria1 || !vitoria2)
    {
        cout << "Voc� perdeu. As palavras corretas eram: " << palavra[1] << " e " << palavra[2] << "\n";
        pauseScreen();
    }
    // Liberar mem�ria das tentativas
    liberarTentativas(listaTentativas);
}

void triteto(ListaPalavras lista, string palavra[])
{
    ListaTentativas listaTentativas;
    inicializarTentativas(listaTentativas);
    bool vitoria1 = false, vitoria2 = false, vitoria3 = false;
    colorScreen cor;

    for (int i = 1; i <= 10; i++)
    {
        string usuarioTentativa;
        cout << "Tentativa " << i << " (triteto): ";
        cin >> usuarioTentativa;

        if (validadePalavra(palavraMinusculo(usuarioTentativa)))
        {
            // Insere a tentativa na lista de tentativas
            inserirTentativa(listaTentativas, usuarioTentativa);

            if (vitoria1 == false)
            {
                // Verifica e exibe a tentativa para a primeira palavra secreta
                cout << "Palavra 1: ";
                verificarTentativa(usuarioTentativa, palavra[3]);
                if (usuarioTentativa == palavra[3])
                {
                    vitoria1 = true;
                }
            }

            if (vitoria2 == false)
            {
                // Verifica e exibe a tentativa para a segunda palavra secreta
                cout << "Palavra 2: ";
                verificarTentativa(usuarioTentativa, palavra[4]);
                if (usuarioTentativa == palavra[4])
                {
                    vitoria2 = true;
                }
            }

            if (vitoria3 == false)
            {
                // Verifica e exibe a tentativa para a terceira palavra secreta
                cout << "Palavra 3: ";
                verificarTentativa(usuarioTentativa, palavra[5]);
                if (usuarioTentativa == palavra[5])
                {
                    vitoria3 = true;
                }
            }
            if (vitoria1 && vitoria2 && vitoria3)
            {
                cout << "Parab�ns, voc� acertou todas as palavras!\n";
                ranking(i);
                pauseScreen();
                break;
            }
        }
        else
        {
            cout << "Palavra com tamanho inválido.\n ";
            i--;
        }
    }
    if (!vitoria1 || !vitoria2 || !vitoria3)
    {
        cout << "Voc� perdeu. As palavras corretas eram: "
             << palavra[3] << ", " << palavra[4] << ", "
             << palavra[5];
        pauseScreen();
    }

    // Liberar mem�ria das tentativas
    liberarTentativas(listaTentativas);
}

void quarteto(ListaPalavras lista, string palavra[])
{
    ListaTentativas listaTentativas;
    inicializarTentativas(listaTentativas);
    bool vitoria1 = false, vitoria2 = false, vitoria3 = false, vitoria4 = false;

    colorScreen cor;

    for (int i = 1; i <= 12; i++)
    {
        string usuarioTentativa;
        cout << "Tentativa " << i << " (quarteto): ";
        cin >> usuarioTentativa;

        if (validadePalavra(palavraMinusculo(usuarioTentativa)))
        {
            // Insere a tentativa na lista de tentativas
            inserirTentativa(listaTentativas, usuarioTentativa);

            if (vitoria1 == false)
            {
                // Verifica e exibe a tentativa para a primeira palavra secreta
                cout << "Palavra 1: ";
                verificarTentativa(usuarioTentativa, palavra[3]);
                if (usuarioTentativa == palavra[6])
                {
                    vitoria1 = true;
                }
            }

            if (vitoria2 == false)
            {
                // Verifica e exibe a tentativa para a segunda palavra secreta
                cout << "Palavra 2: ";
                verificarTentativa(usuarioTentativa, palavra[4]);
                if (usuarioTentativa == palavra[7])
                {
                    vitoria2 = true;
                }
            }

            if (vitoria3 == false)
            {
                // Verifica e exibe a tentativa para a terceira palavra secreta
                cout << "Palavra 3: ";
                verificarTentativa(usuarioTentativa, palavra[5]);
                if (usuarioTentativa == palavra[8])
                {
                    vitoria3 = true;
                }
            }

            if (vitoria4 == false)
            {
                // Verifica e exibe a tentativa para a quarta palavra secreta
                cout << "Palavra 4: ";
                verificarTentativa(usuarioTentativa, palavra[6]);
                if (usuarioTentativa == palavra[9])
                {
                    vitoria4 = true;
                }
            }

            if (vitoria1 && vitoria2 && vitoria3 && vitoria4)
            {
                cout << "Parab�ns, voc� acertou todas as palavras!\n";
                ranking(i);
                pauseScreen();
                break;
            }
        }
        else
        {
            cout << "Palavra com tamanho inválido.\n ";
            i--;
        }
    }
    if (!vitoria1 || !vitoria2 || !vitoria3 || !vitoria4)
    {
        cout << "Voc� perdeu. As palavras corretas eram: "
             << palavra[6] << ", " << palavra[7] << ", "
             << palavra[8] << ", " << palavra[9] << "\n";
        pauseScreen();
    }

    // Liberar mem�ria das tentativas
    liberarTentativas(listaTentativas);
}

void liberarMemoria(ListaPalavras &lista, ListaTentativas &listaTentativas)
{
    liberarLista(lista);
    liberarTentativas(listaTentativas);
}

void jogar(ListaPalavras lista)
{
    int e;
    string palavraSecreta[10];
    preencherPalavrasSecretas(lista, palavraSecreta);

    ListaTentativas listaTentativas;
    inicializarTentativas(listaTentativas);

    do
    {
        clearScreen();
        cout << "Escolha o modo de jogo\n";
        cout << "1 - termo.\n2 - dueto.\n3 - triteto.\n4 - Quarteo.\n5 - Sair\n Escolha: ";
        cin >> e;
        switch (e)
        {
        case 1:
            termo(lista, palavraSecreta[0]);
            break;
        case 2:
            dueto(lista, palavraSecreta);
            break;
        case 3:
            triteto(lista, palavraSecreta);
            break;
        case 4:
            quarteto(lista, palavraSecreta);
            break;
        case 5:
            liberarMemoria(lista, listaTentativas);
            return;
        default:
            cout << "Opção inválida.\n";
            break;
        }
    } while (e != 4);

    clearScreen();
}

bool adiconarNovaPalavra(ListaPalavras &lista, string palavra)
{
    if (pesquisarLista(lista, palavra))
    {
        return false;
    }
    else
    {
        inserirPalavra(lista, palavra);
        return true;
    }
}

bool removerPalavraExistente(ListaPalavras &lista, string palavra)
{
    if (pesquisarLista(lista, palavra))
    {
        removerPalavra(lista, palavra);
        return true;
    }
    else
    {
        return false;
    }
}

void comoJogar()
{
    clearScreen();
    colorScreen cor;
    cout << "Descubra a palavra certa em 6 tentativas.\nDepois de cada tentativa, as pe�as mostram o qu�o perto voc� est� da solu��o.\n";
    cout << cor.green << "T " << cor.reset << "E R M O\n";
    cout << "A letra " << cor.green << "T " << cor.reset << " faz parte da palavra na posi��o correta.\n";
    cout << "V I " << cor.yellow << "O " << cor.reset << "L A\n";
    cout << "A letra " << cor.yellow << "O " << cor.reset << " faz parte da palavra mas em outra posi��o.\n";
    cout << "P U L " << cor.red << "G" << cor.reset << " A\n";
    cout << "A letra " << cor.red << "G" << cor.reset << " n�o faz parte da palavra.\n";
    cout << "Todas as palavras N�O possuem acentos, evite adiconar palavra com acento pq n�o sabemos tratar.\n";
    cout << "As palavras podem possuir letras repetidas.\n";
    cout << "A palavra � escolhida aleatoriamente ao iniciar o jogo.\n\n";
    cout << "Pressione qualquer tecla para voltar\n";
    pauseScreen();
    clearScreen();
}

void HUD_AdicionarPalavra(ListaPalavras &lista, string listaTermo)
{
    clearScreen();
    string novaPalavra;
    cout << "Digite a palavra que deseja inserir.\n";
    cin >> novaPalavra;
    novaPalavra = palavraMinusculo(novaPalavra);
    if (!validadePalavra(novaPalavra))
    {
        cout << "Palavra com tamanho inv�lido!\n";
    }
    else
    {
        if (!adiconarNovaPalavra(lista, novaPalavra))
        {
            cout << "Essa palavra j� existe na lista.\n";
        }
        else
        {
            gravarPalavras(lista, listaTermo);
            cout << "Palavra adicionada na lista.\n";
        }
    }
    pauseScreen();
    clearScreen();
}

void HUD_RemoverPalavra(ListaPalavras &lista, string listaTermo)
{
    clearScreen();
    string remove;
    cout << "Digite a palavra que deseja remover.\n";
    cin >> remove;
    remove = palavraMinusculo(remove);
    if (!validadePalavra(remove))
    {
        cout << "Palavra com tamanho inv�lido!\n";
    }
    else
    {
        if (!removerPalavraExistente(lista, remove))
        {
            cout << "Essa palavra n�o existe na lista.\n";
        }
        else
        {
            gravarPalavras(lista, listaTermo);
            cout << "Palavra removida da lista.\n";
        }
    }
    pauseScreen();
    clearScreen();
}

void creditos()
{
    clearScreen();
    cout << "\nUNIVERSIDADE DO VALE DO ITAJA�\n";
    cout << "DISCIPLINA: ESTRUTURA DE DADOS\n";
    cout << "PROFESSOR: MARCOS CARRARD\n";
    cout << "ALUNOS: HENRY JOS�, VIN�CIUS MEDEIROS SANTOS\n";
    cout << "CURSO: ENGENHARIA DE COMPUTA��O\n";
    pauseScreen();
    clearScreen();
}

void menu()
{
    string listaTermo = "palavrasTermo.txt";
    int input = 0;
    ListaPalavras lista;

    inicializarLista(lista);
    carregarPalavras(lista, listaTermo);

    ListaTentativas listaTentativas; // Inicializa a lista de tentativas
    inicializarTentativas(listaTentativas);

    do
    {
        clearScreen();
        cout << "\t\tTERMO\t\t\n";
        cout << " 1 - JOGAR\n 2 - COMO JOGAR\n 3 - ADICIONAR PALAVRAS\n 4 - REMOVER PALAVRAS\n 5 - LISTA DE PALAVRAS\n 6 - CRÉDITOS\n 7 - SAIR\n ESCOLHA:";
        cin >> input;
        switch (input)
        {
        case 1:
            jogar(lista);
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
            clearScreen();
            mostrarLista(lista);
            pauseScreen();
            break;
        case 6:
            creditos();
            break;
        case 7:
            liberarMemoria(lista, listaTentativas);
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida. Digite novamente.\n";
        }
    } while (input != 7);
}