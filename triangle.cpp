//
// Created by Oliver Barta on 2025-10-23.
//

#include <iostream>

#include <cmath>
#include <iomanip>

using namespace std;

void enter_sides(double &a, double &b, double &c);
void check_sides(double &a, double &b, double &c);
void calculate_angle(double a, double b, double c);

int main() {
    double a, b, c;
    enter_sides(a, b, c);
    check_sides(a, b, c);
    if (a == -1) {
        return 1;
    }
    calculate_angle(a, b, c);

    return 0;
}

void enter_sides(double &a, double &b, double &c) {
    cin >> a >> b >> c;

}
void check_sides(double &a, double &b, double &c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        a = -1;
    }
    if (a + b <= c) {
        a = -1;
    }
    if (b + c <= a) {
        a = -1;
    }
    if (c + a <= b) {
        a = -1;
    }
}

void calculate_angle(double a, double b, double c) {
    double angle = acos((pow(a,2)+pow(b,2)-pow(c,2))/(2.0*a*b));
    cout << fixed << setprecision(2) << endl;
    cout << angle*180/ M_PI << endl;
}