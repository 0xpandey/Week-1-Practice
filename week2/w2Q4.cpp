// Program 4: Move Constructor Implementation
// Create a class with:
//  - Copy constructor
//  - Move constructor
//  - Log when each is called

// see in this program i could have done the simple example of constructor
// but for better understanding 
// i planned to do and example of an simple component of an game engine

#include <iostream>
using namespace std;

class TextureComponent {
    int* textureID; 
    // considering it a simulated GPU texture resource

    public :
        //constructor -- loads a texture
        TextureComponent(int id){
            textureID = new int(id);  // allocate texture
            cout<< "Texture loaded (constructor)\n";
        }

        // copy constructor -- duplicate texture
        TextureComponent(const TextureComponent& other) {
            textureID = new int(*other.textureID); // deep copy
            cout << "Texture copied (copy constructor)\n";
        }

        // Move constructor -- transfer texture ownership
        TextureComponent(TextureComponent&& other) {
            textureID = other.textureID; // take ownership
            other.textureID = nullptr;   // source loses texture
            cout << "Texture moved (move constructor)\n";
        }

        // destructor -- unload texture
        ~TextureComponent(){
            delete textureID;
            cout<< "Texture unloaded (Destructor)\n";
        }
};

int main(){
    // creating a texture component
    TextureComponent playerTexture(101);

    // copying same texture to differnent component
    TextureComponent enemyTexture = playerTexture;

    // moveing the texture 
    TextureComponent uiTexture = std::move(playerTexture);

    return 0;

}

// Copy Constructor (Slow)
//  -- Used when duplicating entities
//  -- Creates new texture
//  -- Expensive for GPU/memory

// Move Constructor (Fast)
//  -- Used when transferring components
//  -- No duplication
//  -- Ownership moved

// In game engines, move constructors are used to 
// transfer ownership of heavy resources like textures 
// efficiently.