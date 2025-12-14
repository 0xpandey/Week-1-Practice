#include <iostream>
using namespace std;

int main() {
    int n, reverse = 0;
    cout << "Enter number to be reversed: ";
    cin >> n;

    while(n > 0) {
        reverse = reverse* 10 + (n % 10);
        n = n / 10;
    }

    cout << "Reversed number = " << rev;
    return 0;
}
