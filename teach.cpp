//
// Created by Oliver Barta on 2025-10-03.
//

#include <iostream>

using namespace std;

int main() {

    int x = rand() % 10;
    int y = rand() % 10;

    int total_correct_first_try = 0;

    int total_questions = 0;

    int input = 0;

    bool first_try = true;

    while (input != -1) {
        cout << "\nHow much is " << x << " times " << y << "? (Enter -1 to end)";
        cin >> input;

        if (cin.fail()) {
            return -1;
        }

        if (x*y == input && input != -1) {
            cout << "\nVery good!\n\n";
            x = rand() % 10;
            y = rand() % 10;
            total_questions++;
            if (first_try) {
                total_correct_first_try++;
            }
            first_try = true;
        } else if (input != -1) {
            cout << "No. Please try again. " << endl;
            first_try = false;
        }

    }

    cout << "\nCorrectly answered " << total_correct_first_try << " of " << total_questions << " on the first try.\n";

    return 0;
}

