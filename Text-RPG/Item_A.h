#pragma once
#include <string>
using namespace std;

class Item_A
{
    string name;
    float mass;
public:
    Item_A(string n, float m = 0.0f) : name(n), mass(m) {}
    string getName() { return name; }
    virtual void use() = 0;
};
