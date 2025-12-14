#include <iostream>
using namespace std;

int main() {
    int choice;
    char again;

    cout<<"Welcome to lucky colours game\n";
    do{
        cout << "Pick a number between 1 to 3: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << " Pink = Bonitaa"; 
            break;
            case 2: cout << " Blue = Calm";
             break;
            case 3: cout << " Yellow = Happinesss";
             break;
            default: cout << "choose between 1 to 3 only"; 
            break;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;

    } while(again == 'y');

    return 0;
}
