#include <iostream>
using namespace std;

//question no. 5 answer (rel to functions)

//Leap year check: (determining by divisibility over 4)
//Temperature Formula: 9 / 5 * celsius + 32



int largest(int a, int b, int c) {
    int maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

double toFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

char letterGrade(int marks) {
    if (marks >= 80) return 'A';
    if (marks >= 70) return 'B';
    if (marks >= 60) return 'C';
    if (marks >= 50) return 'D';
    return 'F';
}

int main() {
    int n1, n2, n3;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;
    // 1. Storing the returned value
    int big = largest(n1, n2, n3);
    cout << "Largest: " << big << endl;

    int year;
    cout << "Enter a year: ";
    cin >> year;
    // 2. Testing returned value in a condition
    if (isLeapYear(year)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }

    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    cout << celsius << " C = " << toFahrenheit(celsius) << " F" << endl;

    int marks;
    cout << "Enter marks: ";
    cin >> marks;
    // 3. Printing returned value directly
    cout << "Grade: " << letterGrade(marks) << endl;

    return 0;
}