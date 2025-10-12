//
// Created by Oliver Barta on 2025-10-03.
//

#include <iostream>

using namespace std;

int main() {

    int number = 0;

    cout << "Enter a number: ";
    cin >> number;

    //checks for invalid cases
    if (cin.fail() || number < 0) {
        return -1;
    }

    //the factorial value
    unsigned int fact = 1;

    if (number == 0) {
        fact = 1;
    } else {
        for (int i = 1; i <= number; i++) {
            fact *= i;
        }
    }


    //outputs answer
    cout << "The factorial of " << number << " is " << fact << "." << endl;
    return 0;
}