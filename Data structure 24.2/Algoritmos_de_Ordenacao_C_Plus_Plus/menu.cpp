#include <iostream>
#include <chrono>
#include "console.cpp"
#include "ordenation.cpp"
#include "testeOrdenation.cpp"
using namespace std;

void menu()
{
    int opc, n, repeat;
    do
    {
        do
        {
            clearScreen();
            cout << "\nEntre com o tamanho do vetor: \n";
            cin >> n;
            if(n <= 0) cout << "Tamnho invalido\n";
        } while (n <= 0);

        do
        {
            clearScreen();
            cout << "\nEntre com a quantidade de repeticoes: \n";
            cin >> repeat;
            if(n <= 0) cout << "Quantidade invalida.\n" ;
        } while (repeat <= 0);

        int *v = new int[n];

        cout << "\nEscolha o metodo de ordenacao que gostaria de testar: ";
        cout << "\t\n 0 - Sair";
        cout << "\t\n 1 - Inserction Sort";
        cout << "\t\n 2 - Shell Sort";
        cout << "\t\n 3 - Bubble Sort";
        cout << "\t\n 4 - Bubble Sort";
        cout << "\t\n 5 - Selection Sort";
        cout << "\t\n 6 - Selection Sort";
        cout << "\t\n 7 - Heap Sort";
        cout << "\t\n 8 - Merge Sort\n";
        cin >> opc;
        clearScreen();
        switch (opc)
        {
        case 0:
            delete v;
            break;
        case 1:
            TestarInsertion(n, repeat);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        default:
            break;
        }
    } while (opc != 0);
}