#pragma once
#include <memory>

template<typename T>
class Hexgrid {
    uint16_t width, height, size;
    std::unique_ptr<T[]> grid;

public:
    Hexgrid(uint16_t width, uint16_t height);
    Hexgrid(const Hexgrid& other);
    Hexgrid(const Hexgrid& other, uint16_t element, uint16_t row, uint16_t _width, uint16_t _height);
    T& at(uint16_t x, uint16_t y);
    const T& at(uint16_t x, uint16_t y) const;
    uint16_t numOfLines() const;
    uint16_t numOfElements(uint16_t line) const;
    int getWidth() const;
    int getHeight() const;
};

// Constructor definition
template <typename T>
// w - the length of the top side
// h - the length of the middle side
inline Hexgrid<T>::Hexgrid(uint16_t w, uint16_t h) : width(w), height(h) {
    if (w > h)
        throw "Hexgrid: w > h, w must be less or equal to h.";
    size = h * h - w * w + w;
    grid = std::make_unique<T[]>(size);
}

template<typename T>
inline Hexgrid<T>::Hexgrid(const Hexgrid& other) : Hexgrid(other.width, other.height)
{
    memcpy(grid, other.grid, size * sizeof(T));
}

template<typename T>
inline Hexgrid<T>::Hexgrid(const Hexgrid& other, uint16_t row, uint16_t element, uint16_t _width, uint16_t _height) : Hexgrid(_width, _height)
{

}

// at() definitions
template <typename T>
inline T& Hexgrid<T>::at(uint16_t row, uint16_t element) {
    if (x > width || y > height)
        throw "Hexgrid: out of bounds\n";
    return Hexgrid[x + y * width];
}

template <typename T>
inline const T& Hexgrid<T>::at(uint16_t x, uint16_t y) const {
    if (x > width || y > height)
        throw "Hexgrid: out of bounds\n";
    return Hexgrid[x + y * width];
}

template<typename T>
inline uint16_t Hexgrid<T>::numOfLines() const
{
    return 2*(height - width) + 1;
}

template<typename T>
inline uint16_t Hexgrid<T>::numOfElements(uint16_t line) const
{
    if (line > numOfLines())
        throw "out of bounds";
    uint16_t res;
    if (line < (int16_t)height - width) res = width + line;
    else if (line > (int16_t)height - width) res = 2 * height - (width + line);
    else res = height;
    return res;
}

// Getter definitions
template <typename T>
inline int Hexgrid<T>::getWidth() const {
    return width;
}

template <typename T>
inline int Hexgrid<T>::getHeight() const {
    return height;
}
