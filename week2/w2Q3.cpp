// Program 3: shared_ptr + weak_ptr 
// - Two objects referencing each other
// - Fix circular dependency using `weak_ptr`

#include <iostream>
#include <memory>

using namespace std;

class B; 
// B is already created in start so that in it a pointed can be shared

class A {
    public:
        shared_ptr<B> b; // so her B is shared in B

        A(){
            cout<< "A created\n";
        }
        ~A(){
            cout<< "A destroyed\n";
        }
};

class B {
    public:
        weak_ptr<A> a; // and her B is shared in A but A is weak

        B(){
            cout<<"B created\n";
        }
        ~B(){
            cout<<"B destroyed\n";
        }
    
};

// clearly the first one is strong and the one which is share is weak
// mota moti strong is called the shared pointer

int main(){
    shared_ptr<A> objA = make_shared<A>();
    shared_ptr<B> objB = make_shared<B>();

    objA->b = objB; // A->B (shared)  shared in strong so it is called shared
    objB->a = objA; // B->A (weak>)   shared i  weak so it is called weak

    cout<< "End of the main\n";

    return 0;
    //when returned o every object which is created is destoryed evenly/induviduallliy
  
}

// shared_ptr increases reference count
// weak_ptr is used to avoid circular references between shared_ptrs.
// Two shared_ptrs pointing to each other cause memory leak
// weak_ptr does not increase reference count
// Using weak_ptr breaks the circular dependency
// Objects are destroyed properly at program end

// this will be the case (A ↔ B) so one should be weak