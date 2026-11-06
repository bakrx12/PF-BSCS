#include <iostream>
using namespace std;

bool isLeap(int year);
int daysInMonth(int month, int year);
bool isValidDate(int day, int month, int year);
int dayOfYear(int day, int month, int year);

int main() {
    int day, month, year;
    cout << "Enter date (d m y): ";
    cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        cout << "Invalid date." << endl;
    } else {
        int totalDays = isLeap(year) ? 366 : 365;
        int currentDayNum = dayOfYear(day, month, year);
        int daysLeft = totalDays - currentDayNum;

        cout << "Day number: " << currentDayNum << endl;
        cout << "Days left in " << year << ": " << daysLeft << endl;
    }
    return 0;
}

bool isLeap(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

bool isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12) {
        return false;
    }
    int maxDays = daysInMonth(month, year);
    if (day < 1 || day > maxDays) {
        return false;
    }
    return true;
}

int dayOfYear(int day, int month, int year) {
    int dayCount = 0;
    for (int m = 1; m < month; m++) {
        dayCount += daysInMonth(m, year);
    }
    dayCount += day;
    return dayCount;
}