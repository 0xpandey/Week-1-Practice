#include <iostream>
using namespace std;

int main() {
    string questions[3] = {
        "Capital of India?",
        "2 + 2 = ?",
        "C++ is a ___ language?"
    };

    string answers[3] = {"Delhi", "4", "Programming"};
    string user;
    int score = 0;

    for(int i = 0; i < 3; i++) {
        cout << questions[i] << " ";
        cin >> user;

        if(user == answers[i]) {
            score++;
            cout << "Correct\n";
        } else {
            cout << "Wrong\n";
        }
    }

    cout << "Final Score: " << score << "/3";
    return 0;
}
