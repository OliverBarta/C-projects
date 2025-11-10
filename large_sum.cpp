//
// Created by Oliver Barta on 2025-11-09.
//

#include <iostream>
#include "large_sum.h"
using namespace std;


int main() {
    string num1, num2;
    while (true) {
        enter_nums(num1, num2);
        if (num1 == "-1" || num2 == "-1") {
            cout << "The End" << endl;
            return 0;
        }
        if (num1.length() > 20 || num2.length() > 20 || num1 == "-2") {
            return 1;
        }

        int result[21] = {0};
        int result_len = 21;
        if (!add_large_numbers(num1, num2, result, result_len)) {
            return 1;
        }
        if (result[0] != 0) {
            return 1;
        }
        display_num(result, result_len);
    }
    return 0;
}

bool is_integer(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void enter_nums(string &num1, string &num2) {
    cin >> num1;
    if (cin.fail() || !is_integer(num1)) {
        num1 = "-2";
        return;
    }
    if (num1 == "-1") {
        num1 = "-1";
        return;
    }
    cin >> num2;
    if (cin.fail() || !is_integer(num2)) {
        num1 = "-2";
    } else if (num2 == "-1") {
        num2 = "-1";
    }

}

bool add_large_numbers(string num1, string num2, int result[], int &result_len) {
    int num1a[21] = {0};
    int num2a[21] = {0};

    for (int i = 0; i < num1.length(); i++) {
        num1a[21-num1.length()+i] = (num1[i] - '0');
    }
    for (int i = 0; i < num2.length(); i++) {
        num2a[21-num2.length()+i] = (num2[i] - '0');
    }

    int carry = 0;
    for (int i = 20; i >= 0; i--) {
        result[i] = num1a[i] + num2a[i] + carry;
        if (result[i] >= 10) {
            result[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        if (i == 0 && carry == 1) {
            return false;
        }
    }

    return true;
}

void display_num(int result[], int result_len) {
    int first_non_zero_index = 0;
    for (int i = 0; i < result_len; i++) {
        if (result[i] != 0) {
            first_non_zero_index = i;
            break;
        }
    }
    cout << "Sum: ";
    for (int i = first_non_zero_index; i < result_len; i++) {
        cout << result[i];
    }
    cout << endl;
}