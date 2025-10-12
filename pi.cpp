//
// Created by Oliver Barta on 2025-10-11.
//

#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main() {
    double tolerance;

    //Prompt and check tolerance
    do {
        cout << "Enter tolerance (0.0 < ε < 0.1): ";
        cin >> tolerance;
    } while (tolerance <= 0.0 || tolerance >= 0.1);

    double pi_old = 0.0;
    double pi_new = 0.0;
    int term = 0;

    //Loop through terms until convergence
    do {
        pi_old = pi_new;
        double term_value = pow(-1, term) / (2.0 * term + 1.0);
        pi_new = pi_old + 4.0 * term_value;
        cout << term << "\t\t" << fixed << setprecision(12) << pi_new << endl;
        term++;
    } while (fabs(pi_new - pi_old) >= tolerance);

    return 0;
}