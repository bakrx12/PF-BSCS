#include<iostream>
using namespace std;

int getNumber();
bool checkEvenOdd(int number);
void displayResult(int number, bool EvenOdd);

int main()
{  
    int number = getNumber();
    checkEvenOdd(number);

    displayResult();
}

int getNumber()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    return number;
}

bool checkEvenOdd(int number) {
    bool EvenOdd;
    if (number%2 == 0) {
        EvenOdd = true;
        return EvenOdd;
    }
    else {
        EvenOdd = false;
        return EvenOdd;
    }
}

void displayResult(int number,bool EvenOdd) {
    if (!EvenOdd) {
        cout << "Number is odd";
    }
    else {
        cout << "Number is Even";
    }
}