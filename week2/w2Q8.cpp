// Program 8: Reference vs Pointer Demo
// - Same function implemented with reference & pointer
// - Show safety difference


// We update a TransformComponent position using:
//  - Pointer version
//  - Reference version


#include <iostream>
using namespace std;

// simple transform component
struct Transform {
    int x;
};

// Function using POINTER
void moveWithPointer(Transform* t){
    if (t != nullptr){  // checking an the  accessing 
        t->x += 10; 
        cout<< "Moved with pointer\n";
    } else {
        cout<< "Null pointer , cannot move\n";
    }
}

//Fuction using Referneces
void moveWithReferences(Transform& t){
    t.x += 10;
    cout<< "Moved with reference\n";
}

int main(){
    Transform player{0};

    moveWithPointer(&player);

    moveWithReferences(player);

    cout<< "Final position " << player.x << endl;
    return 0;
}

// | Feature      | Pointer   | Reference |
// | ------------ | --------- | --------- |
// | Can be null  |   Yes     |   No      |
// | Needs check  |   Yes     |   No      |
// | Reassignment |   Yes     |   No      |
// | Syntax       |   `->`    |  `.`      |
// | Safety       | Less safe | Safer     |


// Reference → Mandatory component access
// Pointer → Optional component access
