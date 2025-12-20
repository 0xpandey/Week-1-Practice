// Program 6: Enum + Bitflag System
// - Define component flags
// - Combine flags using bitwise ops
// - Check enabled components

// each entity can have multiple components enabled using bit flags

#include <iostream>
using namespace std;

// defining component flags using bit shiftflag

enum Component {
    NONE = 0, // no component
    RENDER = 1 << 0, // 0001
    PHYSICS = 1 << 1, // 0010
    AI = 1 << 2, // 0100
    AUDIO = 1 << 3 // 1000
};

int main(){
    int entityCompoments = NONE ; 

    entityCompoments |= RENDER;
    entityCompoments |= PHYSICS;

    cout <<"Components enabled:\n";

    //check if Render components is enabled
    if(entityCompoments & RENDER)
        cout<< "- Render Component\n";
    
    //check if Physics component is enabled
    if(entityCompoments & PHYSICS)
        cout<< "- Physics Component\n" ;

    //check if AI component is enabled
    if(!(entityCompoments & AI))
        cout<< "- AI Component not enabled\n";
    
    return 0;
}

// components have been give their own binary value 
//  & for checkingg the component
// << for bit shifting
// Bitflags allow multiple components to be stored efficiently using bitwise operations
