//
// Created by Oliver Barta on 2025-10-23.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double theta_deg, double rhs) {
    return (tan(theta_deg) - sin(theta_deg) - rhs);
}

double bisection(double lo, double hi, double rhs, double tol, int count) {
    count += 1;
    if (count > 256) {
        return 500.1234;
    }
    double mid = (lo + hi)/2.0;

    if (f(lo, rhs)*f(mid, rhs)<=0) {
        hi = mid;
    } else if (f(mid, rhs)*f(hi, rhs)<=0) {
        lo = mid;
    }
    if (fabs(f(mid, rhs)) <= tol) {
        return mid;
    } else {
        return bisection(lo, hi, rhs, tol, count);
    }


}

int main() {
    double lo, hi, rhs, tol;
    int count = 0;
    cin >> rhs >> lo >> hi >> tol;
    if (cin.fail()) {
        return 1;
    }

    if (lo < 0 || hi >= 90) {
        return 1;
    }
    lo = lo*M_PI/180.0;
    hi = hi*M_PI/180.0;
    if (f(lo,rhs)*f(hi,rhs)>0) {
        return 1;
    }

    cout << fixed << setprecision(10);
    double deg = bisection(lo, hi, rhs, tol, count)*180.0/M_PI;
    if (deg == 500.1234) {
        return 1;
    }
    cout << deg << " deg" << endl;
    cout << scientific << setprecision(12);
    cout << f((deg*M_PI/180), rhs);
    return 0;
}
