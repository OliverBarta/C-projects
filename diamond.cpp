//
// Created by Oliver Barta on 2025-10-10.
//

#include <iostream>

using namespace std;

int main() {

    int rows = 0;
    int col = 1;

    cout << "Enter number of rows in your diamond: ";
    cin >> rows;

    if (cin.fail() || rows % 2 == 0 || rows >= 20) {
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int v = 0; v < (rows-col)/2; v++) {
            cout << " ";
        }
        for (int j = 0; j < col; j++) {
            cout << "*";
        }
        cout << endl;
        if (i < rows/2) {
            col = col+2;
        } else {
            col = col-2;
        }
    }


    return 0;
}