#include <iostream>



int main() {
    // int x =43;
    // int * ptr = &x;
    // std::cout << "*ptr = " << *ptr << std::endl;
    // int * ptr2 = ptr;
    // std::cout << "*ptr2 = " << *ptr2 << std::endl;


    // ------------------ //
    int* array = new int[100];
    for(int i = 0 ; i< 100 ; i++){
        array[i] = i+1;
    }
    int* ptr = array;
    std:: cout<< "*ptr = " << *ptr << std::endl;
    delete[] array;

    float*  newarray = new float[100];
    int* ptr2 = ptr;
    std:: cout<< " *ptr2 = " << *ptr2 << std::endl;

    

     







    return 0;
}