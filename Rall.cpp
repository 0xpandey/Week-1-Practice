#include <iostream>



// https://cpp.references.com
// https://wiki.libsdl.org/SDL3/CategorySurface


// class Collection{
//     public:
//         Collection(){
//             data = new int[10];
//             try {
//                 throw 20;
//             }catch(int e){
//                 //some erroer message
//             }
//         }
//         ~Collection(){
//             //  destructor is still called
//             std::cout<< "destructor is called\n ";
//             delete[] data;
//         }
//         int& operator[](std::size_t idx){ 
//             return data[idx];
//         }
//         const int& operator[](std::size_t idx) const { 
//             return data[idx]; 
//         }   
//     private:
//         int* data;
// };

struct Surface{
    Surface(){
        // allocate surface
        surface = SDL_CreateSurface(nullptr);
        std::cout << "Surface created\n";
    }
    ~Surface(){
        SDL_FreeSurface(surface);
        std::cout << "Surface destroyed\n";
    }

    SDL_Surface* surface;
}

int main(){

    // Collection mycollection;
    // mycollection[0] = 42;
    // mycollection[1] = 7;
    // mycollection[2] = 13;

    // std::cout << mycollection[0] << std::endl;



    return 0;
}