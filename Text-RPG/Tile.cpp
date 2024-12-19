#include "Tile.h"
#include "Entity_A.h"

// Custom copy constructor for Tile using iterators
Tile::Tile(const Tile& other) {
    // Access the underlying container of the stack (std::deque by default)
    auto& originalStackContainer = other.entityStack._Get_container(); // Using internal container access

    // Create a deep copy of the stack using iterators
    for (const auto& entityStackCopy : originalStackContainer) {
        // Create a new Entity_A to avoid shared ownership
        entityStack.push(EntityStack_t{ entityStackCopy.pEntity->clone(), entityStackCopy.currentHeight});
    }
}

Entity_A* Tile::getEntity() const
{
    if(entityStack.empty())
        return nullptr;
    return entityStack.top().pEntity;
}

int16_t Tile::getHeight() const
{
    if (entityStack.empty())
        return 0;
    return entityStack.top().currentHeight;
}

Tile::~Tile()
{
    while (!entityStack.empty()) {
        delete entityStack.top().pEntity;
        entityStack.pop();
    }
}
