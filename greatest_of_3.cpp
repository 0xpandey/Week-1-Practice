#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b && a >= c){
        cout << a <<" is the GREATEST number.";
    }
    else if (b >= a && b >= c){
        cout << b <<" is the GREATEST number.";
    }
    else{
        cout << c <<" is the GREATEST number.";
    }

    return 0;
}
