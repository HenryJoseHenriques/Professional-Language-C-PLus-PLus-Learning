#include <sstream> // Adicionando para manipulação de streams
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void lerCSV(Hash<filmes> &tabela, string arquivoCSV)
{
    // cout << arquivoCSV;
    ifstream file(arquivoCSV);
    string linha;
    int h;

    if (!file.is_open()) // Verifica se o arquivo foi aberto corretamente
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    while (getline(file, linha)) // Lê cada linha do arquivo
    {
        stringstream s(linha); // Transforma a linha em um stream
        string infoFilmes[6];

        // Lê os primeiros 5 campos separados por ','
        for (int i = 0; i < 6; i++)
        {
            if (!getline(s, infoFilmes[i], ','))
            {
                cout << "Erro: a linha tem menos de 6 colunas." << endl;
                break;
            }
        }

        int cod = stoi(infoFilmes[0]);

        // Separando os atores pela delimiter '-'
        LDE<string> listaAtores;
        stringstream ss(infoFilmes[3]); // Info de atores
        string ator;

        while (getline(ss, ator, '-'))
        {
            inserirLDE(listaAtores, ator);
        }

        filmes novoFilme = {cod, infoFilmes[1], infoFilmes[4], infoFilmes[2], listaAtores, infoFilmes[5]};

        if (arquivoCSV == "ListaAtores.csv")
        {
            No<string> *aux = listaAtores.comeco;
            while (aux != NULL)
            {
                h = hashing(aux->info);
                inserirLDE(tabela.vetor[h], novoFilme);
                aux = aux->eloP;
            }
        }
        else if (arquivoCSV == "ListaCategorias.csv")
        {
            h = hashing(novoFilme.categoria);
            inserirLDE(tabela.vetor[h], novoFilme);
        }
        else if (arquivoCSV == "ListaDiretor.csv")
        {
            h = hashing(novoFilme.diretor);
            inserirLDE(tabela.vetor[h], novoFilme);
        }
        else if (arquivoCSV == "ListaFilmes.csv")
        {
            h = hashing(novoFilme.nome);
            inserirLDE(tabela.vetor[h], novoFilme);
        }
        else
        {
            cout << "\nErro ao ler filme do CSV.\n";
        }
    }
    file.close();
}

void gravarCSV(Hash<filmes> &tabela, string arquivoCSV)
{
    ofstream file(arquivoCSV);

    if (file.is_open())
    {
        for (int i = 0; i < TAM; i++)
        {
            No<filmes> *atual = tabela.vetor[i].comeco;
            while (atual != NULL)
            {
                // Gravando as informações do filme, exceto os atores
                file << atual->info.cod << ","
                     << atual->info.nome << ","
                     << atual->info.diretor << ",";

                // Concatenando os atores com '-' como separador
                No<string> *atualAtor = atual->info.atores.comeco;
                while (atualAtor != NULL)
                {
                    file << atualAtor->info; // Imprime o nome do ator
                    if (atualAtor->eloP != NULL)
                    {
                        file << "-"; // Adiciona o separador '-' entre os nomes dos atores
                    }
                    atualAtor = atualAtor->eloP;
                }

                // Continuando com as outras informações
                file << "," << atual->info.categoria << "," <<
                atual->info.disponibilidade << "\n";

                atual = atual->eloP;
            }
        }

        file.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

void lerCSV(Hash<login> &tabela, string arquivoCSV)
{
    ifstream file(arquivoCSV);
    string linha;
    int h;

    if (!file.is_open()) // Verifica se o arquivo foi aberto corretamente
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    while (getline(file, linha)) // Lê cada linha do arquivo
    {
        stringstream s(linha); // Transforma a linha em um stream
        string infoFilmes[3];

        // Lê os primeiros 5 campos separados por ','
        for (int i = 0; i < 3; i++)
        {
            if (!getline(s, infoFilmes[i], ','))
            {
                cout << "Erro: a linha tem menos de 3 colunas." << endl;
                break;
            }
        }

        int cod = stoi(infoFilmes[0]);

        login novoCadastro = {cod, infoFilmes[1], infoFilmes[2]};

        if (arquivoCSV == "listaUsuarios.csv")
        {
            h = hashing(novoCadastro.nome);
            inserirLDE(tabela.vetor[h], novoCadastro);
        }
        else
        {
            cout << "\nErro ao ler filme do CSV.\n";
        }
    }
    file.close();
}

void gravarCSV(Hash<login> &tabela, string arquivoCSV)
{
    ofstream file(arquivoCSV);

    if (file.is_open())
    {
        for (int i = 0; i < TAM; i++)
        {
            No<login> *atual = tabela.vetor[i].comeco;
            while (atual != NULL)
            {
                // Gravando as informações do filme, exceto os atores
                file << atual->info.matricula << ","
                     << atual->info.nome << ","
                     << atual->info.senha;
                atual = atual->eloP;
            }
        }
        file.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

void lerCSV(Hash<filmeAlugado> &lista, string arquivo)
{
    ifstream file(arquivo);
    string linha;

    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo de aluguéis." << endl;
        return;
    }

    while (getline(file, linha))
    {
        stringstream s(linha);
        string infoAluga[6];  
        for (int i = 0; i < 6; i++)
        {
            if (!getline(s, infoAluga[i], ','))
            {
                cout << "Erro: a linha tem menos de 6 colunas." << endl;
                break;
            }
        }

        int matriculaUser = stoi(infoAluga[0]);
        int codFilme = stoi(infoAluga[1]);
        string nomeFilme = infoAluga[2];
        string nomeUser = infoAluga[3];
        int data = stoi(infoAluga[4]);
        int codAluguel = stoi(infoAluga[5]); 
        filmeAlugado novo = {matriculaUser, codFilme, nomeFilme, nomeUser, data, codAluguel};

        if (arquivo == "listaAlugados.csv")
        {
            int indiceHash = codAluguel % TAM;
            inserirLDE(lista.vetor[indiceHash], novo);
        }
        else
        {
            cout << "\nErro ao ler do filmes alugados do CSV\n";
        }
    }

    file.close();
}

void gravarCSV(Hash<filmeAlugado> &lista, string arquivo)
{
    ofstream file(arquivo); // Abre o arquivo para escrita

    if (!file.is_open())
    {
        cout << "\nErro ao abrir o arquivo de alugueis.\n";
        return;
    }

    for (int i = 0; i < TAM; i++)
    {
        No<filmeAlugado> *aux = lista.vetor[i].comeco;
        while (aux != NULL)
        {
            file << aux->info.matriculaUser << ","
                 << aux->info.codFilme << ","
                 << aux->info.nomeFilme << ","
                 << aux->info.nomeUser << ","
                 << aux->info.data << ","
                 << aux->info.codAluguel << "\n";
            aux = aux->eloP;
        }
    }

    file.close();
}
