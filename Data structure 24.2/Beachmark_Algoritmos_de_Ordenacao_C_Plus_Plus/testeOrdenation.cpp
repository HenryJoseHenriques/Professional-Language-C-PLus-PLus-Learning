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

int *copiarVetor(int *v, int n)
{
    int *c = new int[n];
    for (int i = 0; i < n; i++)
        c[i] = v[i];
    return c;
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

double timerRegisterSort(int n, int r, void(sort)(int *v, int m, int k), int *(caseV)(int t))
{
    double soma = 0.0f, media;
    int *vectorT = caseV(n);
    for (int i = 0; i < r; i++)
    {
        int *copyVector = copiarVetor(vectorT, n);
        auto inicio = steady_clock::now();
        sort(copyVector, 0, n);
        auto fim = steady_clock::now();
        auto duracao = fim - inicio;
        soma += duration_cast<nanoseconds>(duracao).count();
        delete[] copyVector;
    }
    delete[] vectorT;
    media = soma / r;
    return media;
}

void BenchMarkSort(int n, int r, void(sort)(int *v,int m, int n))
{
    colorScreen color;
    double mediaP, mediaM, mediaT;

    mediaP = timerRegisterSort(n, r, sort, VetorPiorCaso);
    mediaM = timerRegisterSort(n, r, sort, VetorMelhorCaso);
    mediaT = timerRegisterSort(n, r, sort, VetorCasoMedio);

    cout << "\nTeste de ordenacao com  tamanho " << n << " e " << r <<" repeticoes: \n";
    cout << color.red << "\t\nPior caso: " << mediaP << " ns \n"
         << color.reset;
    cout << color.yellow << "\t\nCaso Medio: " << mediaT << " ns \n"
         << color.reset;
    cout << color.green << "\t\nMelhor caso: " << mediaM << " ns \n"
         << color.reset;
    pauseScreen();
}