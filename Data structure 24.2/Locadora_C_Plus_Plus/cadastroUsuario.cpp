#include <iostream>
using namespace std;

bool fazerCadastro(Hash<login> lista, login &novo) {
    cout << "\n=== Cadastro de Usuário ===\n";
    cout << "Digite seu nome de usuário: ";
    getline(cin, novo.nome);
    
    string confSenha;
    do {
        cout << "\nDigite sua senha: ";
        getline(cin, novo.senha);
        cout << "Digite sua senha novamente: ";
        getline(cin, confSenha);
        
        if (novo.senha != confSenha) {
            cout << "\nSenhas não coincidem! Tente novamente.\n";
        } else {
            int hC = hashing(novo.nome);
            if (pesquisarLDE(lista.vetor[hC], novo)) {
                cout << "\nUsuário já cadastrado! Por favor, escolha outro nome.\n";
                return false;
            } else {
                novo.matricula = cripto(novo.nome);
                return true;
            }
        }
    } while (novo.senha != confSenha);
}

login credenciais() {
    login entrar;
    cout << "\n=== Login ===\n";
    cout << "Entre com o nome do usuário: ";
    getline(cin, entrar.nome);
    entrar.matricula = hashing(entrar.nome);
    cout << "Entre com a senha: ";
    getline(cin, entrar.senha);
    return entrar;
}

bool fazerLogin(Hash<login> &usuarios, login signUp) {
    int hL = hashing(signUp.nome);
    No<login> *aux = usuarios.vetor[hL].comeco;
    
    while (aux != NULL) {
        if (aux->info == signUp) {
            cout << "\nBem-vindo, " << signUp.nome << "!\n";
            cout << "Aproveite nosso catálogo :D\n";
            return true;
        }
        aux = aux->eloP;
    }
    cout << "\nUsuário não encontrado. Faça o cadastro.\n";
    return false;
}

void initUser(Hash<login> &usuarios) {
    for (int i = 0; i < TAM; i++) {
        inicializarLDE(usuarios.vetor[i]);
    }
}

void entrarNoPortal(Hash<filmes> &filme, Hash<filmes> &categoria, Hash<filmes> &diretor, Hash<filmes> &atores, string t1, string t2, string t3, string t4) {
    string listaUser = "listaUsuarios.csv";
    login User;
    Hash<login> usuarios;
    initUser(usuarios);
    lerCSV(usuarios, listaUser);
    login novo;
    int opc;
    do {
        cout << "\n=== Portal do Usuário ===\n";
        cout << "0 - Sair\n";
        cout << "1 - Fazer Login\n";
        cout << "2 - Fazer Cadastro\n";
        cout << "Escolha uma opção: ";
        cin >> opc;
        cin.ignore();
        
        switch (opc) {
            case 0:
                liberarTabela(usuarios);
                cout << "Você saiu do portal. Até logo!\n";
                break;
            case 1:
                User = credenciais();
                if (fazerLogin(usuarios, User)) {
                    alugarFilmes(filme, categoria, diretor, atores, User, t1, t2, t3, t4);
                } else {
                    cout << "\nNão foi possível acessar a locadora :(\n";
                }
                break;
            case 2:
                
                if (fazerCadastro(usuarios, novo)) {
                    int hL = novo.matricula % TAM;
                    inserirFinalLDE(usuarios.vetor[hL], novo);
                    gravarCSV(usuarios, listaUser);
                    cout << "\nUsuário criado com sucesso!\n";
                } else {
                    cout << "\nUsuário já cadastrado! Faça Login.\n";
                }
                break;
            default:
                cout << "Opção inválida. Por favor, tente novamente.\n";
                break;
        }
    } while (opc > 0);
}