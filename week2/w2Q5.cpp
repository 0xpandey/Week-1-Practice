// Program 5: Lambda with STL
// - Store entities in `vector`
// - Use lambda to:
//     - sort
//     - filter
//     - count


// Concept
// Each Entity has:
//  -- id
//  -- health

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Game engine entity
struct Entity {
    int id;
    int health;
};

int main(){

    vector<Entity> entities = {
        {1,80},
        {2,40},
        {3,100},
        {4,60}
    };


    // sorting entities by health
    sort(entities.begin() , entities.end() , 
    [](const Entity& a,const Entity& b){
        return a.health < b.health;  // lambda comparison
    });

    cout<< "Entities sorted by health:\n";
    for (const auto& e : entities)
        cout << "ID: "<< e.id << " health: " << e.health << endl;
    
    // filtrer entities with health > 50
    cout<< "\nEntities wiht health  > 50:\n";
    for_each(entities.begin(),entities.end(), 
            [](const Entity& e){
                if (e.health > 50)
                    cout<< "ID: " << e.id << endl;
            });
    
    // count entites wiht health >=60
    int countHealthy = count_if(entities.begin(),entities.end(),
            [](const Entity& e){
                return e.health >=60;
            });
    
    cout << "\nEntities with health >= 60: " << countHealthy << endl;

    return 0;
}

// | Operation  | Lambda Purpose                |
// | ---------- | ----------------------------- |
// | `sort`     | Compares two entities         |
// | `filter`   | Prints only matching entities |
// | `count_if` | Counts matching entities      |

