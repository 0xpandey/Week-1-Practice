// Small game-engine component manager
// *features
//  -- enum class (type-safe
//  -- Functions to add, remove, check, toggle components
//  -- Very simple engine-style logic
//  -- Short comments for clarity

#include <iostream>
using namespace std;

enum class Component : unsigned int {
    NONE = 0,
    RENDER = 1 << 0, // 0001
    PHYSICS = 1 << 1, // 0010
    AI = 1 << 2, // 0100
    AUDIO = 1 << 3 // 1000
};

// enables component
void addComponent(unsigned int& mask , Component c){
    mask |= static_cast<unsigned int>(c);  //for adding use bitwise or
}

// remove a component
void removeComponent(unsigned int& mask , Component c){
    mask &= ~static_cast<unsigned int>(c); //for clearing use &
}

// check if a component exists
bool hasComponent(unsigned int mask, Component c){
    return mask & static_cast<unsigned int>(c);
}

// toggle a component
void toggleComponent(unsigned int& mask , Component c){
    mask ^= static_cast<unsigned int>(c);  // flipping th bit
}

int main(){
    unsigned int entityMask = 0;

    addComponent(entityMask,Component::RENDER);
    addComponent(entityMask,Component::PHYSICS);
    addComponent(entityMask,Component::AUDIO);

    cout<< " Enabled components:\n";

    if(hasComponent(entityMask ,Component::RENDER)){
        cout<< "- Render\n";
    }

    if(hasComponent(entityMask ,Component::PHYSICS)){
        cout<< "- Physics\n";
    }

    if(!hasComponent(entityMask ,Component::AI)){
        cout<< "- AI not enabled\n";
    }

    // Toggle Physics component
    
    toggleComponent(entityMask,Component::AUDIO);

    cout<< "\nAFter toggleing Physics:\n";

    if(!hasComponent(entityMask, Component::PHYSICS))
        cout<< "- Physics disabled\n";
    
    if(!hasComponent(entityMask, Component::AUDIO))
        cout<< "- Audio disabled\n";
    
    return 0;
    
}


// | Operator | Use              |               
// | -------- | ---------------- | 
// |  |=       | Add component    |
// | `&`      | Check component  |               
// | `~`      | Remove component |               
// | `^`      | Toggle component |               

