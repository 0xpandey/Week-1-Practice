// Program 2: unique_ptr Ownership Demo
// - Create entity via `unique_ptr`
// - Transfer ownership using `std::move`
// - Show original pointer becomes null

#include <iostream>
#include <memory>

using namespace std;

class Entity {
    public:
        Entity(){
            cout<< "Entity Created\n";
        }
        ~Entity(){
            cout<< "Entity destroyed\n";
        }

        void show(){
            cout<< "Entity is active\n";
        }
};

int main(){
    // createing a entity using unique_pointer
    unique_ptr<Entity> ptr1 = make_unique<Entity>();

    // transfer ownership using std::move
    unique_ptr<Entity> ptr2 = move(ptr1);

    //checking the pointer
    if(ptr1 == nullptr)
        cout<< "ptr1 is null after the ownership transfer\n";

    ptr2->show();

    return 0;
}

// unique_ptr allows only one owner
// Ownership cannot be copied
// Ownership can be transferred using std::move
// After transfer, the original pointer becomes null
// Object is destroyed automatically when last unique_ptr goes out of scope

