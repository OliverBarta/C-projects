//
// Created by Oliver Barta on 2025-10-23.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
void enter_data(double &a, double &b, double &c);
void quadratic(double a, double b, double c, double &first_real, double &first_imag, double &second_real, double &second_imag);
void display_results(double first_real, double first_imag, double second_real, double second_imag);

int main () {
    double a, b, c;
    double first_real, first_imag, second_real, second_imag;
    enter_data(a, b, c);
    quadratic(a, b, c, first_real, first_imag, second_real, second_imag);
    display_results(first_real, first_imag, second_real, second_imag);
    return 0;
}

void enter_data(double &a, double &b, double &c) {
    cout << "Enter the value for a: ";
    cin >> a;
    cout << "  a = " << a << endl << endl;
    cout << "Enter the value for b: ";
    cin >> b;
    cout << "  b = " << b << endl << endl;
    cout << "Enter the value for c: ";
    cin >> c;
    cout << "  c = " << c << endl << endl;
}
void quadratic(double a, double b, double c, double &first_real, double &first_imag, double &second_real, double &second_imag) {
    double discrim = pow(b,2.0)-4.0*a*c;
    if (discrim>=0) {
        first_real = (-b+sqrt(discrim))/(2.0*a);
        second_real = (-b-sqrt(discrim))/(2.0*a);
        first_imag = 0.0;
        second_imag = 0.0;
    } else {
        first_imag = sqrt(-discrim)/(2.0*a);
        second_imag = -sqrt(-discrim)/(2.0*a);
        first_real = -b/(2.0*a);
        second_real = -b/(2.0*a);
    }
}

void display_results(double first_real, double first_imag, double second_real, double second_imag) {
    cout << fixed << setprecision(4);
    if (first_imag == 0.0 && second_imag == 0.0) {
        cout << "The roots of the equation are " << first_real << " and "
        << second_real << "." << endl
        << endl;
    } else {
        cout.setf(ios::showpos);
        cout << "The roots of the equation are " << first_real << first_imag
        << "j and " << second_real << second_imag << "j." << endl
        << endl;
    }
}