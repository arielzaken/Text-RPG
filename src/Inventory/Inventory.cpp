#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int size)
{
    maxCapacity = size;
    items = new Item_A*[size];
}

Inventory::~Inventory()
{
    delete[] items;
    items = nullptr;
}

void Inventory::addItem(unsigned int index, Item_A *item)
{
    if(items[index] == nullptr)
        items[index] = item;
    else
        throw "addItem: Item already exists in this space.";
}

void Inventory::removeItem(unsigned int index)
{
    if(items[index] != nullptr)
        delete items[index];
    items[index] = nullptr;
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
