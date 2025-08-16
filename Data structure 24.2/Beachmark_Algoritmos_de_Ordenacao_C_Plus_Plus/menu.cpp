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
            if (n <= 0)
                cout << "Tamnho invalido\n";
        } while (n <= 0);

        do
        {
            clearScreen();
            cout << "\nEntre com a quantidade de repeticoes: \n";
            cin >> repeat;
            if (n <= 0)
                cout << "Quantidade invalida.\n";
        } while (repeat <= 0);
        cout << "\nEscolha o metodo de ordenacao que gostaria de testar: ";
        cout << "\t\n 0 - Sair";
        cout << "\t\n 1 - Inserction Sort";
        cout << "\t\n 2 - Shell Sort";
        cout << "\t\n 3 - Bubble Sort";
        cout << "\t\n 4 - Quick Sort";
        cout << "\t\n 5 - Selection Sort";
        cout << "\t\n 6 - Heap Sort";
        cout << "\t\n 7 - Merge Sort\n";
        cin >> opc;
        clearScreen();
        switch (opc)
        {
        case 0:
            break;
        case 1:
            cout << "INSERTION SORT\n";
            BenchMarkSort(n, repeat, insertion_sort);
            break;
        case 2:
            cout << "SHELL SORT\n";
            BenchMarkSort(n, repeat, shell_sort);
            break;
        case 3:
            cout << "BUBBLE SORT\n";
            BenchMarkSort(n, repeat, bubble_sort);
            break;
        case 4:
            cout << "QUICK SORT\n";
            BenchMarkSort(n, repeat, quick_sort);
            break;
        case 5:
            cout << "SELECTION SORT\n";
            BenchMarkSort(n, repeat, selection_sort);
            break;
        case 6:
            cout << "HEAP SORT\n";
            BenchMarkSort(n, repeat, heap_sort);
            break;
        case 7:
            cout << "MERGE SORT\n";
            BenchMarkSort(n, repeat, merge_sort);
            break;
        default:
            cout << "Opcao invalida, escolha novamente.\n";
            break;
        }
    } while (opc != 0);
}