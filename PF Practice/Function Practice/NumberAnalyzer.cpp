#include<iostream>
using namespace std;

int getNumber();
bool checkEvenOdd(int number);
void displayResult(int number, bool EvenOdd);

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int reverseNumber(int number) {
    int reversed = 0;
    while (number > 0) {
        int lastDigit = number % 10;
        reversed = reversed * 10 + lastDigit;
        number /= 10;
    }
    return reversed;
}

int main()
{  
    int number = getNumber();
    bool isEven = checkEvenOdd(number);
    
    cout << "\nPrime Number until " << number << ":\n";
    bool first = true;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i)) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    cout << "\nPrime Number that are also prime when reversed:\n";
    first = true;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i) && isPrime(reverseNumber(i))) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    cout << "\n\n";

    displayResult(number, isEven);
    
    return 0;
}

int getNumber()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    return number;
}

bool checkEvenOdd(int number) {
    return (number % 2 == 0); 
}

void displayResult(int number, bool EvenOdd) {
    if (!EvenOdd) {
        cout << "Number is odd\n";
    }
    else {
        cout << "Number is Even\n";
    }