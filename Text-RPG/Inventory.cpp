#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int size)
{
    maxCapacity = size;
    items = new Item_A*[size];
    for (size_t i = 0; i < size; i++){
        items[i] = nullptr;
    }
}

Inventory::~Inventory()
{
    delete[] items;
    items = nullptr;
}

int Inventory::addItem(unsigned int index, Item_A &item)
{
    if(items[index] == nullptr){
        for(int i = 0; i < maxCapacity; i++)
            if(&item == items[i])
                return 1;
        items[index] = &item;
        return 0;
    }
    else
        return 1;
}

int Inventory::removeItem(unsigned int index)
{
    items[index] = nullptr;
    return 1;
}

void Inventory::displayItems() const
{
    for(int i = 0; i < maxCapacity; i++)
        if(items[i]!= nullptr)
            cout << i << ": " << items[i]->getName() << endl;
        else
            cout << i << ": " << endl;
}

void Inventory::swapItems(int i, int j)
{
    swap(items[i], items[j]);
}
