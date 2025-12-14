#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getComputerChoice() {
    return rand() % 3;
}

string choiceToString(int choice) {
    if (choice == 0) return "Rock";
    if (choice == 1) return "Paper";
    return "Scissors";
}

int main() {
    srand(time(0));

    int userChoice, compChoice;
    char playAgain;

    do {
        cout << "0: Rock\n1: Paper\n2: Scissors\nEnter your choice: ";
        cin >> userChoice;

        if (userChoice < 0 || userChoice > 2) {
            cout << "Invalid choice\n";
            continue;
        }

        compChoice = getComputerChoice();

        cout << "You chose: " << choiceToString(userChoice) << endl;
        cout << "Computer chose: " << choiceToString(compChoice) << endl;

        if (userChoice == compChoice)
            cout << "It's a draw!\n";
        else if ((userChoice == 0 && compChoice == 2) ||
                 (userChoice == 1 && compChoice == 0) ||
                 (userChoice == 2 && compChoice == 1))
            cout << "You win!\n";
        else
            cout << "Computer wins!\n";

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
