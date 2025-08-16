#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

string date_now()
{
    // Obter o tempo atual como um ponto no tempo
    auto now = std::chrono::system_clock::now();
    // Converter o ponto no tempo para o formato de tempo do sistema
    time_t time_now = std::chrono::system_clock::to_time_t(now);
    // Converter o tempo em uma estrutura tm para formatação
    tm *local_time = std::localtime(&time_now);
    // Formatar a data no formato "DD/MM/YYYY" e armazenar
    std::ostringstream oss;
    oss << std::put_time(local_time, "%d/%m/%Y");
    string date_today = oss.str();
    return date_today;
}
