#include <iostream>

using namespace std;
//question 4 answers:
//compiler error because void can't be printed in cout
//statement terminator before the statement ends

void printWelcome() {
    cout << "Welcome to the Lab 04 Printer" << endl;
}

void printLine(char symbol, int length) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    cout << endl;
}

void printTable(int n) {
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << (n * i) << endl;
    }
}

void printTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        printLine('*', i);
    }
}

int main() {
    printLine('=', 30);
    printWelcome();
    printLine('=', 30);

    int num;
    cout << "Enter a number for its table: ";
    cin >> num;
    printTable(num);

    printLine('-', 30);

    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    printTriangle(rows);

    printLine('=', 30);

    return 0;
}