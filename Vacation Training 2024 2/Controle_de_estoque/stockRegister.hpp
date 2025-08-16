#include <iostream>
using namespace std;

static int ID_count = 0;

struct ItemLog
{
    int ID;
    string name;
    string description;
    string category;
    string unit_of_measure;
    int available_quantity;
    int minimum_stock;
    string location;
    int reserve_quantity;
    float purchase_price;
    float sale_price;
    float profit_margin;
    string registration_date;
    string last_modification;
    const int initial_quantity;
};

bool operator==(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID == a2.ID);
}

bool operator!=(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID != a2.ID);
}

bool operator>=(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID >= a2.ID);
}

bool operator<=(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID <= a2.ID);
}

bool operator>(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID > a2.ID);
}

bool operator<(const ItemLog &a1, const ItemLog &a2)
{
    return (a1.ID < a2.ID);
}

int registerID()
{
    return ID_count++;
}

string registerName()
{
    string _name;
    cout << "Nome do produto: \n";
    getline(cin, _name);
    cout << _name;
    return _name;
}

string registerDescription()
{
    string _register;
    cout << "Descrição do produto\n";
    getline(cin, _register);
    cout << _register;
    return _register;
}

string registerCategory()
{
    int numCategory = 0;
    do
    {
        cout << "Escolha a categoria do produto:\n\n";
        cout << "1 - Eletronicos e Tecnologia\n";
        cout << "2 - Alimentos e Bebidas\n";
        cout << "3 - Vestuario e Acessorios\n";
        cout << "4 - Saude e Beleza\n";
        cout << "5 - Materiais de Escritorio\n";
        cout << "6 - Ferramentas e Equipamentos\n";
        cout << "7 - Materiais de Limpeza\n";
        cout << "8 - Automotivo\n";
        cout << "9 - Moveis e Decoracao\n";
        cout << "10 - Entretenimento\n";
        cin >> numCategory;
        switch (numCategory)
        {
        case 1:
            return "Eletronicos e Tecnologia";
            break;
        case 2:
            return "Alimentos e Bebidas";
            break;
        case 3:
            return "Vestuario e Acessorios";
            break;
        case 4:
            return "Saude e Beleza";
            break;
        case 5:
            return "Materiais de Escritorio";
            break;
        case 6:
            return "Ferramentas e Equipamentos";
            break;
        case 7:
            return "Materiais de Limpeza";
            break;
        case 8:
            return "Automotivo";
            break;
        case 9:
            return "Moveis e Decoracao";
            break;
        case 10:
            return "Entretenimento";
            break;
        default:
            cout << "Por favor, escolha uma opcao valida.\n";
            break;
        }
    } while (numCategory <= 0 || numCategory > 10);
}

string registeUnitOfMeasure()
{
    int numMeasure = 0;
    do
    {
        cout << "Unidade de Medidas:\n\n";
        cout << "01 - un (unidade)\n";
        cout << "02 - pct (pacote)\n";
        cout << "03 - cx (caixa)\n";
        cout << "04 - dz (duzia)\n";
        cout << "05 - kg (quilograma)\n";
        cout << "06 - g (grama)\n";
        cout << "07 - t (toneladas)\n";
        cout << "08 - l (litro)\n";
        cout << "09 - ml (mililitro)\n";
        cout << "10 - m^3 (metro cubido)\n";
        cout << "11 - m (metro)\n";
        cout << "12 - cm (centimetro)\n";
        cout << "13 - mm (milimetro)\n";
        cin >> numMeasure;
        cout << numMeasure;
        switch (numMeasure)
        {
        case 1:
            return "un";
            break;
        case 2:
            return "pct";
            break;
        case 3:
            return "cx";
            break;
        case 4:
            return "dz";
            break;
        case 5:
            return "kg";
            break;
        case 6:
            return "g";
            break;
        case 7:
            return "t";
            break;
        case 8:
            return "l";
            break;
        case 9:
            return "ml";
            break;
        case 10:
            return "m^3";
            break;
        case 11:
            return "m";
            break;
        case 12:
            return "cm";
            break;
        case 13:
            return "mm";
            break;
        default:
            cout << "Por favor, escolha uma opcao valida.\n";
            break;
        }
    } while (numMeasure <= 0 || numMeasure > 13);
}

int registerAvailableQuantity(int quantMin)
{
    int quant = 0;
    do
    {
        cout << "Digite a quantidade inicial do produto:\n";
        cin >> quant;
        if (quant <= 0)
            cout << "A quantidade não pode ser menor ou igual a 0, ou menor que o estoque minimo.\n";
    } while (quant <= 0 || quant < quantMin);
    return quant;
}

int registerMinimumStock()
{
    int minium = 0;
    do
    {
        cout << "Digite o estoque minimo do produto:\n";
        cin >> minium;
        if(minium < 0) cout << "A quantidade minima não pode ser menor que zero.\n";
    } while (minium < 0);
    return minium;
}
string location;
int reserve_quantity;
float purchase_price;
float sale_price;
float profit_margin;
string registration_date;
string last_modification;
const int initial_quantity;