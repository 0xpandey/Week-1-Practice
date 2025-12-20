#ifndef ECS_H
#define ECS_H

#include <iostream>
using namespace std;

// Simple Entity
class Entity {
    int id;

public:
    Entity(int id);
    void print() const;
};

#endif
