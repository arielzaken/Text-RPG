#pragma once

#include <memory>

template<typename T>
class Grid {
    int width, height;
    std::unique_ptr<T[]> grid;

public:
    Grid(int width, int height);
    T& at(uint16_t x, uint16_t y);
    const T& at(uint16_t x, uint16_t y) const;
    inline int getWidth() const;
    inline int getHeight() const;
};

// Constructor definition
template <typename T>
Grid<T>::Grid(int w, int h) : width(w), height(h) {
    grid = std::make_unique<T[]>(w * h);
    std::fill(grid.get(), grid.get() + w * h, T());
}

// at() definitions
template <typename T>
T& Grid<T>::at(uint16_t x, uint16_t y) {
    if(x > width || y > height)
        throw "Grid: out of bounds\n";
    return grid[x + y * width];
}

template <typename T>
const T& Grid<T>::at(uint16_t x, uint16_t y) const {
    if(x > width || y > height)
        throw "Grid: out of bounds\n";
    return grid[x + y * width];
}

// Getter definitions
template <typename T>
inline int Grid<T>::getWidth() const {
    return width;
}

template <typename T>
inline int Grid<T>::getHeight() const {
    return height;
}
