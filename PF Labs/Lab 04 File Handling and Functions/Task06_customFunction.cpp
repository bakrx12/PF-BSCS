#include <iostream>

using namespace std;

//answers for question 6:
    //q 2: deleting cmath would throw error:
    //'sqrt' was not declared in this scope

    //q 3 because of math
    //negative number squared will return positive

    //q 4   output: 27 8
    //      value passed: 2
    //because result() is outside of main()






double customSqrt(double num) {
    if (num <= 0) return 0;
    double x = num;
    for (int i = 0; i < 20; i++) {
        x = 0.5 * (x + num / x);
    }
    return x;
}

double hypotenuse(double a, double b) {
    return customSqrt(a * a + b * b);
}

double pointDistance(double x1, double y1, double x2, double y2) {
    return hypotenuse(x2 - x1, y2 - y1);
}

int main() {
    double h, d;
    cout << "Enter wall height and distance from the wall: ";
    cin >> h >> d;
    cout << "Ladder length needed: " << hypotenuse(h, d) << endl;

    double x1, y1, x2, y2;
    cout << "Enter point 1 (x y): ";
    cin >> x1 >> y1;
    cout << "Enter point 2 (x y): ";
    cin >> x2 >> y2;
    cout << "Distance: " << pointDistance(x1, y1, x2, y2) << endl;

    return 0;
}