//
// Created by Oliver Barta on 2025-11-09.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "coord.h"

using namespace std;

void get_point(Point3D &pt) {
    cin >> pt.id;
    cin >> pt.x;
    cin >> pt.y;
    cin >> pt.z;
    cin >> pt.order;
}
void print_point(const Point3D &pt) {
    cout << "Point ID: " << setw(10) << pt.id << endl;
    cout << "X Coordinate: " << setw(10) << pt.x << endl;
    cout << "Y Coordinate: " << setw(10) << pt.y << endl;
    cout << "Z Coordinate: " << setw(10) << pt.z << endl;
    cout << "Classification: " << setw(10) << pt.order << endl;
}

double spatial_dist(const Point3D &pt1, const Point3D &pt2) {
    return sqrt(pow(pt1.x-pt2.x, 2.0) + pow(pt1.y-pt2.y , 2.0) + pow(pt1.z-pt2.z , 2.0));
}

double plani_dist(const Point3D &pt1, const Point3D &pt2) {
    return sqrt(pow(pt2.x-pt1.x, 2.0)+pow(pt2.y-pt1.y, 2.0));
}

double height_diff(const Point3D &pt1, const Point3D &pt2) {
    return pt2.z-pt1.z;
}

double azimuth(const Point3D &pt1, const Point3D &pt2) {
    double angle = atan2(pt2.y-pt1.y, pt2.x-pt1.x);
    double degrees = angle * 180 / M_PI;
    if (degrees < 0) degrees += 360.0;
    return degrees;
}