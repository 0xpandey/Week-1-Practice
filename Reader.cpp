#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream file;
    string line;
    file.open("Game Engine.txt");
    if (!file.is_open()) {
        cout<<"Error."<<endl;
        return 1;
    }
    while (getline(file, line)) {
        cout<<line<<endl;
    }
    file.close();
    return 0;
}
