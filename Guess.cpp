#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int secretNumber, guess;
    srand(time(0));
    secretNumber = rand() % 100 + 1;
    cout<<"Guess the number (1 to 100): "<<endl;
    do {
        cout<<"Enter your guess: ";
        cin>>guess;
        if (guess > secretNumber) {
            cout<<"Too high!"<<endl;
        } 
        else if (guess < secretNumber) {
            cout<<"Too low!"<<endl;
        } 
        else {
            cout<<"You passes the game"<<end1;
        }
    }while (guess != secretNumber);
    return 0;
}