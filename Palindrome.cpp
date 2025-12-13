#include <iostream>
using namespace std;

int main() {
    int n, rev = 0;
    cin>>n;
    int x=n;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    cout << (rev == n ? "YES" : "NO");
}
