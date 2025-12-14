#include <iostream>
using namespace std;

int main() {
    int n, temp, rev = 0;
    cout << "Enter number: ";
    cin >> n;

    temp = n;
    while(n > 0) {
        rev = rev * 10 + (n % 10);
        n = n / 10;
    }

    if(temp == rev)
        cout << "Palindrome Number";
    else
        cout << "Not a Palindrome";

    return 0;
}
