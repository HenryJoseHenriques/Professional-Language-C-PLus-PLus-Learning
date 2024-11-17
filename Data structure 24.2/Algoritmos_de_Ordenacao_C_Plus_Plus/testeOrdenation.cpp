#include <iostream>
#include <chrono>
#include <random>
#include <time.h>
using namespace std;
using namespace std::chrono;

void printVector(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int *VetorPiorCaso(int n)
{
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = n - i - 1;
    }
    return v;
}

int *VetorMelhorCaso(int n)
{
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    return v;
}

int *VetorCasoMedio(int n)
{
    int *v = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
    return v;
}

void TestarInsertion(int n, int r)
{
    double somaM = 0.0f, somaP = 0.0f, somaT = 0.0f, mediaP, mediaM, mediaT;

    for (int i = 0; i < r; i++)
    {
        int *SelectionP = VetorPiorCaso(n);
        printVector(SelectionP, n);

        auto inicio = steady_clock::now();
        insertion_sort(SelectionP, n);
        auto fim = steady_clock::now();
        auto duracao = fim - inicio;

        somaP += duration_cast<nanoseconds>(duracao).count();
        delete[] SelectionP;
    }
    cout << "\nSoma pior: " << somaP << "\n";
    mediaP = somaP / r;

    for (int i = 0; i < r; i++)
    {
        int *SelectionM = VetorMelhorCaso(n);
        printVector(SelectionM, n);

        auto inicio = steady_clock::now();
        insertion_sort(SelectionM, n);
        auto fim = steady_clock::now();
        auto duracao = fim - inicio;

        somaM += duration_cast<nanoseconds>(duracao).count();
        delete[] SelectionM;
    }
    cout << "Soma melhor: " << somaM << "\n";
    mediaM = somaM / r;

    for (int i = 0; i < r; i++)
    {
        int *SelectionT = VetorCasoMedio(n);
        printVector(SelectionT, n);

        auto inicio = steady_clock::now();
        insertion_sort(SelectionT, n);
        auto fim = steady_clock::now();
        auto duracao = fim - inicio;

        somaT += duration_cast<nanoseconds>(duracao).count();
        delete[] SelectionT;
    }
    cout << "Soma Medio: " << somaT << "\n";
    mediaT = somaT / r;

    cout << "\nTeste de ordenacao do Inserction Sort com " << r << " repeticoes\n";
    cout << "\t\nPior caso " << mediaP << " ns \n";
    cout << "\t\nMelhor caso " << mediaM << " ns \n";
    cout << "\t\nCaso Medio " << mediaT << " ns \n";
    pauseScreen();
}