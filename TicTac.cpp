#include<iostream>
using namespace std;
void box(char board[3][3]) {
    cout << "--------------------------------------------------------------------------------------------\n";
    for (int i = 0;i < 3;i++) {

        for (int j = 0;j < 3;j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "  |  ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---|-----|---\n";
        }
    }
}
bool check(char board[3][3], char player) {
    for (int i = 0;i < 3;i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}
int main() {
    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char player = 'X';
    int row, col, turn;
    cout << "\t\t\tWelcome to the game of Tic Tac Toe\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    for (turn = 0;turn < 9;turn++) {
        box(board);
        cout << "\t\t\tPlayer " << player << "'s turn\n";
        cout << "\t\tEnter the row(0-2) and column(0-2) number where you want to place your mark\n";
        cin >> row >> col;
        if (board[row][col] != ' ' || row > 2 || col > 2) {
            cout << "Invalid move\n";
            turn--;
            continue;
        }
        board[row][col] = player;
        if (check(board, player)) {
            cout << "Player " << player << " wins\n";
            break;
        }
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }
    if (turn == 9) {
        cout << "The game is a draw\n";
    }
}