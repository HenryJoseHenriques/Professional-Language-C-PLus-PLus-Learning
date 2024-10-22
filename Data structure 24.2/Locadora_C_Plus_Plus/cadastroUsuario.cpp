#include <iostream>
using namespace std;

bool fazerCadastro(Hash<login> lista, login &novo)
{
    cout << "\nDigite seu nome de usuário:\n";
    getline(cin, novo.nome);
    string confSenha;
    do
    {
        cout << "\nDigite sua senha:\n";
        // cin >> novo.senha;
        getline(cin, novo.senha);
        cout << "\nDigite sua senha novamente: \n";
        getline(cin, confSenha);
        if (novo.senha != confSenha)
        {
            cout << "\nSenhas não coincidem! Tente novamente\n";
        }
        else
        {
            int hC = hashing(novo.nome);
            if (pesquisarLDE(lista.vetor[hC], novo))
            {
                return false;
            }
            else
            {
                novo.matricula = cripto(novo.nome);
                return true;
            }
        }
    } while (novo.senha != confSenha);
}

login credenciais()
{
    login entrar;
    cout << "\nEntre o nome do usuario:\n";
    getline(cin, entrar.nome);
    entrar.matricula = hashing(entrar.nome);
    cout << "\nEntre com a senha: \n";
    getline(cin, entrar.senha);
    return entrar;
}

bool fazerLogin(Hash<login> &usuarios, login signUp)
{
    int hL = hashing(signUp.nome);
    No<login> *aux = usuarios.vetor[hL].comeco;
    while (aux != NULL)
    {
        if (aux->info == signUp)
        {
            cout << "\nBem vindo, " << signUp.nome << "!\n"
                 << "Aproveite nosso catalogo :D\n";
            return true;
        }
        aux = aux->eloP;
    }
    cout << "\nUsuario nao encontrado. Faca o cadastro\n";
    return false;
}

void initUser(Hash<login> &usuarios)
{
    for (int i = 0; i < TAM; i++)
    {
        inicializarLDE(usuarios.vetor[i]);
    }
}

void entrarNoPortal(Hash<filmes> &lista)
{
    string listaUser = "listaUsuarios.csv";
    Hash<login> usuarios;
    initUser(usuarios);
    lerCSV(usuarios, listaUser);
    int opc;
    do
    {
        cout << "\n0 - sair\n";
        cout << "\n1 - fazer login\n";
        cout << "\n2 - fazer cadastro\n";
        cout << "\nEcolha: ";
        cin >> opc;
        cin.ignore();
        switch (opc)
        {
        case 0:
            break;
        case 1:
            if (fazerLogin(usuarios, credenciais()))
            {
                // Alugar filmes
            }
            else
            {
                cout << "\nNao foi possível acessar a locadora :(\n";
            }
            break;
        case 2:
            login novo;
            if (fazerCadastro(usuarios, novo))
            {
                int hL = novo.matricula % TAM;
                inserirFinalLDE(usuarios.vetor[hL], novo);
                gravarCSV(usuarios, listaUser);
                cout << "\nUsuario criado.\n";
            }
            else
            {
                cout << "\nUsuario Ja cadastrado! Faca Login\n";
            }
            break;
        }
    } while (opc > 0);
}
