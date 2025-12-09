#include <iostream>
using namespace std;

void evenodd(int a){
    
    if(a %2==0){
        cout<< " even";
    } else{
        cout<< " odd";
    }
}
int main() {
    evenodd(4);
    

    return 0;
}