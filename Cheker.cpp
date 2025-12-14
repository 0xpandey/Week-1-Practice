#include <iostream>
#include <string>
using namespace std;
int main() {
    const string correctPassword = "K8n2lrai#";
    string inputPassword;
    cout << "Enter password: ";
    cin >> inputPassword;
    if (inputPassword == correctPassword) {
        cout << "Access Granted" << endl;
    } else {
        cout << "Access Denied" << endl;
    }
    return 0;
}
