#pragma once

#include <memory>
#include <functional>
#include <math.h>
#include "Primitives.h"

using namespace std;

template<typename T>
using ForRegionF_t = std::function<void(T& element, uint16_t x, uint16_t y)>;

template<typename T>
using ForRegionCF_t = std::function<void(const T& element, uint16_t x, uint16_t y)>;

template<typename T>
class Grid {
    int width, height;
    std::unique_ptr<T[]> grid;
public:
    Grid() : Grid(0, 0) {}
    Grid(int width, int height);
    Grid(const Grid& other);
    Grid(Grid&& other);

    Grid<T>& operator=(Grid&& other);
    Grid<T>& operator=(const Grid& other);

    T& at(uint16_t x, uint16_t y);
    const T& at(uint16_t x, uint16_t y) const;
    T& at(Vec2D<uint16_t> pos);
    const T& at(Vec2D<uint16_t> pos) const;

    void forRegion(ForRegionF_t<T> pFunc, uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
    void forRegion(ForRegionF_t<T> pFunc, uint16_t x, uint16_t y, uint16_t r);

    void forRegion(ForRegionCF_t<T> pFunc, uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2) const;
    void forRegion(ForRegionCF_t<T> pFunc, uint16_t x, uint16_t y, uint16_t r) const;

    void forEach(ForRegionF_t<T> pFunc);
    void forEach(ForRegionCF_t<T> pFunc) const;

    inline int getWidth() const;
    inline int getHeight() const;
};

// Constructor definition
template <typename T>
inline Grid<T>::Grid(int w, int h) : width(w), height(h) {
    grid = std::make_unique<T[]>(w * h);
}

template<typename T>
inline Grid<T>::Grid(const Grid& other) : Grid<T>(other.getWidth(), other.getHeight()){
    std::copy(other.grid.get(), other.grid.get() + width * height, grid.get());
}

template<typename T>
inline Grid<T>::Grid(Grid&& other) : width(other.getWidth()), height(other.getHeight())
{
    grid = std::move(other.grid);
}

template<typename T>
Grid<T>& Grid<T>::operator=(Grid&& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        grid = std::move(other.grid);
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

template<typename T>
Grid<T>& Grid<T>::operator=(const Grid& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        grid = std::make_unique<T[]>(width * height);
        std::copy(other.grid.get(), other.grid.get() + width * height, grid.get());
    }
    return *this;
}


// at() definitions
template <typename T>
inline T& Grid<T>::at(uint16_t x, uint16_t y) {
    if(x > width || y > height)
        throw "Grid index out of bounds";
    return grid[x + y * width];
}

template <typename T>
inline const T& Grid<T>::at(uint16_t x, uint16_t y) const {
    if(x > width || y > height)
        throw "Grid index out of bounds";
    return grid[x + y * width];
}

template<typename T>
inline T& Grid<T>::at(Vec2D<uint16_t> pos)
{
    return at(pos[X], pos[Y]);
}

template<typename T>
inline const T& Grid<T>::at(Vec2D<uint16_t> pos) const
{
    return at(pos[X], pos[Y]);
}

template<typename T>
void Grid<T>::forRegion(ForRegionF_t<T> pFunc, uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
    if (x1 > x2)
        std::swap(x1, x2);
    if (y1 > y2)
        std::swap(y1, y2);
    if (x1 >= width || y1 >= height)
        throw "out of bounds";
    for (uint16_t i = x1; i <= x2; i++) {
        for (uint16_t j = y1; j <= y2; j++) {
            pFunc(at(i, j), i, j);
        }
    }
}

template<typename T>
inline void Grid<T>::forRegion(ForRegionF_t<T> pFunc, uint16_t x, uint16_t y, uint16_t r)
{
    forRegion(pFunc, max(x - r, 0), max(y - r, 0), min(x + r, width - 1), min(y + r, height - 1));
}

template<typename T>
inline void Grid<T>::forRegion(ForRegionCF_t<T> pFunc, uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2) const
{
    if (x1 > x2)
        std::swap(x1, x2);
    if (y1 > y2)
        std::swap(y1, y2);
    if (x1 >= width || y1 >= height)
        throw "out of bounds";
    for (uint16_t i = x1; i <= x2; i++) {
        for (uint16_t j = y1; j <= y2; j++) {
            pFunc(at(i, j), i, j);
        }
    }
}

template<typename T>
inline void Grid<T>::forRegion(ForRegionCF_t<T> pFunc, uint16_t x, uint16_t y, uint16_t r) const
{
    forRegion(pFunc, max(x - r, 0), max(y - r, 0), min(x + r, width - 1), min(y + r, height - 1));
}

template<typename T>
inline void Grid<T>::forEach(ForRegionF_t<T> pFunc)
{
    for (uint32_t i = 0; i < width * height; i++){
        pFunc(grid[i], i%width, (uint16_t)(i/width));
    }
}

template<typename T>
inline void Grid<T>::forEach(ForRegionCF_t<T> pFunc) const
{
    for (uint32_t i = 0; i < width * height; i++) {
        pFunc(grid[i], i % width, (uint16_t)(i / width));
    }
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
