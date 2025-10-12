//
// Created by Oliver Barta on 2025-10-03.
//

#include <iostream>

using namespace std;

int main() {

    //the size of the sides of the square
    int size = 0;

    cout << "Enter size: ";
    cin >> size;

    //ensures the size of the sides of the square are:
    //between and including 2 to 20
    //even
    //and a number
    if (size > 20 || size < 2 || size % 2 != 0 || cin.fail()) {
        return -1;
    }

    //coordinates in the square
    int y = 0;
    int x = 0;

    while (y < size) {
        while (x < size) {
            //if the coordinates are at the edge it prints "*"
            if (x == 0 || x == size-1 || y == 0 || y == size-1) {
                cout << "*";
            } else {
                cout << " ";
            }
            x++;
        }
        //goes down a line
        cout << endl;
        x = 0;
        y++;
    }

    return 0;
}