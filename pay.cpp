//
// Created by Oliver Barta on 2025-10-10.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double manager_count = 0.0;
    double hourly_count = 0.0;
    double commission_count = 0.0;
    double piece_count = 0.0;
    double manager_pay = 0.0;
    double hourly_pay = 0.0;
    double commission_pay = 0.0;
    double piece_pay = 0.0;

    double gross_sales = 0.0;
    double weekly_pay = 0.0;
    double hours_this_week = 0.0;
    double hourly_wage = 0.0;
    double pieces_produced = 0.0;
    double value_per_piece = 0.0;
    int inpt = 0;

    while (true) {
        cin >> inpt;
        if (cin.fail()) {
            return 1;
        }
        switch (inpt) {
            case 1: // Manager
                cin >> weekly_pay;
                if (cin.fail()) {
                    return 1;
                }
                manager_count += 1.0;
                manager_pay += weekly_pay;
                break;

            case 2: // Hourly
                cin >> hours_this_week >> hourly_wage;
                if (cin.fail()) {
                    return 1;
                }
                if (hours_this_week <= 40) {
                    hourly_pay += hours_this_week * hourly_wage;
                } else {
                    hourly_pay += 40 * hourly_wage;
                    hourly_pay += (hours_this_week-40)*hourly_wage*1.5;
                }
                hourly_count += 1.0;
                break;

            case 3: // Commission
                cin >> gross_sales;
                if (cin.fail()) {
                    return 1;
                }
                commission_pay += 250+0.057*gross_sales;
                commission_count += 1.0;

                break;

            case 4: // Piece
                cin >> pieces_produced >> value_per_piece;
                if (cin.fail()) {
                    return 1;
                }
                piece_pay += pieces_produced * value_per_piece;
                piece_count += 1.0;
                break;

            case -1: // Output summary
                cout << endl;
                cout << "Summary\n";
                cout << "Worker Type    Number      Total Pay\n";
                cout << "====================================\n";

                // Print each row — integer count, two-decimal pay
                cout << "Manager        "
                     << setw(4) << static_cast<int>(manager_count) << "       "
                     << fixed << setprecision(2) << setw(9) << manager_pay << endl;

                cout.unsetf(ios::fixed); // remove fixed before integer count
                cout << "Hourly         "
                     << setw(4) << static_cast<int>(hourly_count) << "       "
                     << fixed << setprecision(2) << setw(9) << hourly_pay << endl;

                cout << "Commission     "
                     << setw(4) << static_cast<int>(commission_count) << "       "
                     << fixed << setprecision(2) << setw(9) << commission_pay << endl;

                cout << "Piece          "
                     << setw(4) << static_cast<int>(piece_count) << "       "
                     << fixed << setprecision(2) << setw(9) << piece_pay << endl;

                cout << "====================================\n";
                cout << "TOTAL          "
                     << setw(4) << static_cast<int>(manager_count + hourly_count + commission_count + piece_count) << "       "
                     << fixed << setprecision(2) << setw(9)
                     << manager_pay + hourly_pay + commission_pay + piece_pay << endl;

                return 0;

            default:
                return 1;
        }
    }
}
