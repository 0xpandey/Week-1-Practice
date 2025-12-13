#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = 6;
    int target = 7;

    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == target) {
            cout << mid;
            return 0;
        } else if (a[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << -1;
    return 0;
}
