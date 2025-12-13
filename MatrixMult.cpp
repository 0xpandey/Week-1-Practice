#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    cout << "rows and columns of matrix1: ";
    cin >> row1 >> col1;

    cout << "rows and columns of matrix2: ";
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "multiplication impossible";
        return 0;
    }

    int M1[10][10], M2[10][10], res[10][10];

    cout << "matrix1 :\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> M1[i][j];
        }
    }

    cout << "matrix2 :\n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> M2[i][j];
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                res[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }

    cout << "multiplied matrix:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
