// Program 7: Component Add/Remove
//  - Add multiple components
//  - Remove a component safely
//  - Ensure no memory leak

// * Concept
//  - Each Entity owns its components
//  - Components are stored using unique_ptr
//  - Memory is freed automatically when removed


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

// Base Component class (engine style)
class Component {
    public:
        virtual ~Component() {
            cout<< "Component destroyed\n";
        }
};

// Render Component
class RenderComponent : public Component {
    public:
        RenderComponent(){
            cout<< "RenderComponent added\n";
        }
};

// Physics Component
class PhysicsComponent : public Component {
    public :
        PhysicsComponent(){
            cout<< "PhysicsComponent added\n";
        }
};

// Entity class (owns components)
class Entity {
    vector<unique_ptr<Component>> components;

    public:
        //Add a component (safe, no leak)
        template<typename T>
        void addComponent(){
            components.push_back(make_unique<T>()); //RAII allocatio
        }

        //Remove a component safely
        template<typename T>
        void removeComponent() {
            components.erase(
                remove_if(components.begin(),components.end(),
                    [](const unique_ptr<Component>& comp){
                        return dynamic_cast<T*>(comp.get()) != nullptr;
                    }),
                components.end()
            );
        }
};

int main(){
    Entity player;

    //Add multiple components
    player.addComponent<RenderComponent>();
    player.addComponent<PhysicsComponent>();

    cout<< "Removing PhysicsComponent...\n";

    //Remove one component safely
    player.removeComponent<PhysicsComponent>();

    cout<< "End of program\n";

    return 0;

}

// | Feature             | Reason                |
// | ------------------- | --------------------- |
// | `unique_ptr`        | Automatic destruction |
// | `erase + remove_if` | Safe removal          |
// | Virtual destructor  | Proper cleanup        |
// | No `new` / `delete` | No memory leak        |

// Engine-Level Understanding
//  - Components are owned by Entity
//  - Removing a component:
//      - unique_ptr goes out of scope
//      - Destructor is called
//  - This is exactly how ECS engines avoid leaks

