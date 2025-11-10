//
// Created by Oliver Barta on 2025-11-09.
//


#include <iostream>
#include <iomanip>
#include <cmath>
#include "coord.h"

using namespace std;

int main() {
    Point3D point1, point2;
    get_point(point1);
    get_point(point2);
    print_point(point1);
    print_point(point2);

    cout << spatial_dist(point1, point2) << endl;
    cout << plani_dist(point1, point2) << endl;
    cout << height_diff(point1, point2) << endl;
    cout << azimuth(point1, point2) << endl;

    return 0;
}