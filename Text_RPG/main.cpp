#include "Inventory/Inventory.h"
#include "Item/Sword/Sword.h"
#include "World/World.h"

int main() {
    Inventory inv(5);
    Sword swordA("A", 5.7);
    Sword swordB("B", 87.9);
    World world(20, 20);
    world.print();
    system("pause");
    return 0;
}
