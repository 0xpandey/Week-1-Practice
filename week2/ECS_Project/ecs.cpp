#include "ecs.h"

Entity::Entity(int id) : id(id) {
    cout<< "Entity created\n";
}

void Entity::print() const {
    cout<< "Entity ID: "<< id << endl;
}

