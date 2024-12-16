#include <iostream>
#include "Inventory/Inventory.h"
#include "Item/Sword/Sword.h"

using namespace std;

int main() {
    Inventory inv(5);
    Sword swordA("A", 5.7);
    Sword swordB("B", 87.9);
    inv.displayItems();
    if(inv.addItem(3, swordA))
        cout << "error" << endl;
    inv.displayItems();
    if(inv.addItem(3, swordA))
        cout << "error" << endl;
    inv.displayItems();
    if(inv.addItem(3, swordB))
        cout << "error" << endl;
    inv.displayItems();
    if(inv.addItem(4, swordB))
        cout << "error" << endl;
    inv.displayItems();
    return 0;
}
