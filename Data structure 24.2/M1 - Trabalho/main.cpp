#include <iostream>
#include <locale.h>
#include "LUE.cpp"
#include "files.cpp"
#include "utility.cpp"
#include "console.cpp"
#include "termo.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    string palavra = "garfo";
    menu();
}
