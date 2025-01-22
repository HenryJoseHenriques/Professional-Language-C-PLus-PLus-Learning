#include <iostream>
using namespace std;

struct ItemLog
{
    int ID;
    string name;
    long description;
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

bool newItemLog(ItemLog &productItem) {}
bool modifiedItemLog(ItemLog &productItem) {}
bool deleteItemLog(ItemLog &productItem, int ID) {}
void printItemLog(ItemLog productItem) {}
template<typename T>
void printFullStock(No <T> *raiz) {}