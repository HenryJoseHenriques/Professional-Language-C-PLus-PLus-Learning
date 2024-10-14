#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void lerCSV(Hash &tabela, string arquivoCSV)
{
    ifstream file(arquivoCSV);
    string linha;

    if (!file.is_open()) // Verifica se o arquivo foi aberto corretamente
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    while (getline(file, linha)) // Lê cada linha do arquivo
    {
        stringstream s(linha); // Transforma a linha em um stream
        string infoFilmes[6];

        for (int i = 0; i < 6; i++)
        {
            if (!getline(s, infoFilmes[i], ','))
            {
                cout << "Erro: a linha tem menos de 6 colunas." << endl;
                break;
            }
        }
        int h = hashing(infoFilmes[0]);
        filme novo = addFilme(infoFilmes[0], infoFilmes[1], infoFilmes[2], infoFilmes[3], stoi(infoFilmes[4]), stoi(infoFilmes[5])); //stoi converte string para int no C++11
        inserirLDE(tabela.vetor[h],novo); //inseri na tabela hashing
    }
    file.close();
}

void gravarCSV(Hash &tabela, string arquivoCSV)
{
    ofstream file(arquivoCSV);
    if (file.is_open())
    {
        for (int i = 0; i < TAM; i++)
        {
            No *atual = tabela.vetor[i].comeco;
            while (atual != NULL)
            {

                file << atual->info.nome << ","
                     << atual->info.categoria << ","
                     << atual->info.diretor << ","
                     << atual->info.atores << ","
                     << atual->info.tempo << ","
                     << atual->info.cod << "\n";

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
