#include <iostream>
#include <cmath>
using namespace std;

int findGCD(int a, int b);
void reduceFraction(int &num, int &den);
bool calculate(int n1, int d1, char op, int n2, int d2, int &resNum, int &resDen);

int main() {
    int n1, d1, n2, d2;
    char slash1, slash2, op;

    cout << "Enter expression: ";
    cin >> n1 >> slash1 >> d1 >> op >> n2 >> slash2 >> d2;

    int resNum = 0, resDen = 1;

    if (!calculate(n1, d1, op, n2, d2, resNum, resDen)) {
        cout << "Cannot divide by zero." << endl;
    } else {
        cout << "Result: ";
        if (resDen == 1) {
            cout << resNum << endl;
        } else if (abs(resNum) > resDen) {
            int whole = resNum / resDen;
            int remNum = abs(resNum % resDen);
            cout << resNum << "/" << resDen << " = " << whole << " " << remNum << "/" << resDen << endl;
        } else {
            cout << resNum << "/" << resDen << endl;
        }
    }

    return 0;
}

int findGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduceFraction(int &num, int &den) {
    int gcd = findGCD(num, den);
    if (gcd > 0) {
        num /= gcd;
        den /= gcd;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

bool calculate(int n1, int d1, char op, int n2, int d2, int &resNum, int &resDen) {
    if (op == '+') {
        resNum = n1 * d2 + n2 * d1;
        resDen = d1 * d2;
    } else if (op == '-') {
        resNum = n1 * d2 - n2 * d1;
        resDen = d1 * d2;
    } else if (op == '*') {
        resNum = n1 * n2;
        resDen = d1 * d2;
    } else if (op == '/') {
        if (n2 == 0) {
            return false;
        }
        resNum = n1 * d2;
        resDen = d1 * n2;
    }

    reduceFraction(resNum, resDen);
    return true;
}