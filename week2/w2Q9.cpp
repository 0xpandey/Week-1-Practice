// Program 9: Entity Move Semantics
// - Store entities in vector
// - Push using `std::move`
// - Ensure no copy occurs

// Concept
// An Entity owns a heavy resource (like a mesh or texture).
// Game engines move entities into containers to avoid expensive copies


#include <iostream>
#include <vector>
using namespace std;

class Entity {
    int* resource ;  // simulateing a heavy engine resourece

    public:
        Entity(int value){
            resource = new int(value);
            cout<< "Entity created\n";
        }

        Entity(const Entity& other){
            resource = new int(*other.resource);
            cout<< "Entity copied\n";
        }

        Entity(Entity&& other) noexcept{
            resource = other.resource;
            other.resource = nullptr;
            cout<< "Entity moved\n";
        }

        ~Entity() {
            delete resource;
            cout<< "Entity destroyed\n";
        }
};

int main(){
    vector<Entity> entities;

    Entity player(1);

    entities.push_back(std::move(player));

    cout<< "End of main\n";

    return 0;
}