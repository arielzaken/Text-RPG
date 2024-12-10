#pragma once
#include "Item/Item_A.h"
#include <array>
class Inventory
{
    Item_A** items;
    unsigned int maxCapacity = 0;
public:
    Inventory(int size);
    ~Inventory();
    void addItem(unsigned int index, Item_A* item);
    void removeItem(unsigned int index);
    void displayItems() const;
    void swapItems(int i, int j);
};
