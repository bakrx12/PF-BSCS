#include <iostream>
using namespace std;

// Prototypes
int getNumber();

int reverseNumber(int number);
int countDigits(int number);
int power(int base, int exp);
void displayResult(int number, bool evenOdd);

bool checkEvenOdd(int number);
bool isPrime(int number);
bool isNegative(int number);
bool isPositive(int number);
bool isPowerOfTwo(int number);
bool isPerfectNumber(int number);
bool isPerfectSquare(int number);
bool isPalindrome(int number);
bool isArmstrong(int number);

// Non-positive numbers (<= 1) are not prime
bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Processes +ve integers ONLY, returns 0 for -ve
int reverseNumber(int number) {
    int reversed = 0;
    while (number > 0) {
        int lastDigit = number % 10;
        reversed = reversed * 10 + lastDigit;
        number /= 10;
    }
    return reversed;
}

// Negative numbers are not palindromes due to '-' sign
// Formula: number == reverseNumber(number)
bool isPalindrome(int number) {
    if (number < 0) return false;
    return number == reverseNumber(number);
}

// Dynamic digit counter 
int countDigits(int number) {
    if (number == 0) return 1;
    int count = 0;
    int temp = (number < 0) ? -number : number;
    while (temp > 0) {
        count++;
        temp /= 10;
    }
    return count;
}

// Integer power calculation
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Formula: sum(digit ^ total_digits) == original_number
// Hardcoding 3 digits breaks 4-digit Armstrong numbers (e.g., 1634)
bool isArmstrong(int number) {
    if (number < 0) return false; // Armstrong numbers are non-negative
    if (number == 0) return true;  // 0 is an Armstrong number (0^1 = 0)
    
    int digits = countDigits(number);
    int tempDigit = number;
    int sum = 0;
    
    while (tempDigit > 0) {
        int lastDigit = tempDigit % 10;
        sum += power(lastDigit, digits);
        tempDigit /= 10;
    }
    
    return sum == number;
}

// 0 is neither positive nor negative
bool isNegative(int number) {
    return number < 0;
}

bool isPositive(int number) {
    return number > 0;
}

// Negative numbers and 0 are not powers of 2 (e.g., 1 is 2^0)
bool isPowerOfTwo(int number) {
    if (number <= 0) return false;
    return (number & (number - 1)) == 0;
}

// Sum of proper divisors (excluding the number itself) must equal the number. 
// Numbers <= 0 are not perfect numbers. (e.g., 6 = 1 + 2 + 3)
bool isPerfectNumber(int number) {
    if (number <= 0) return false;
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

// Floating point precision issues with sqrt(). 
// Integer-only calculation prevents inaccuracies.
// Negative numbers cannot be perfect square integers.
bool isPerfectSquare(int number) {
    if (number < 0) return false;
    for (int i = 0; i * i <= number; i++) {
        if (i * i == number) return true;
    }
    return false;
}

int main() {  
    int number = getNumber();
    bool isEven = checkEvenOdd(number);

    displayResult(number, isEven);

    // Checks for the entered number
    cout << "Prime Number: " << (isPrime(number) ? "Yes" : "No") << "\n";
    cout << "Palindrome: " << (isPalindrome(number) ? "Yes" : "No") << "\n";
    cout << "Armstrong: " << (isArmstrong(number) ? "Yes" : "No") << "\n";

    // Display Newly Added Checks
    cout << "Negative: " << (isNegative(number) ? "Yes" : "No") << "\n";
    cout << "Positive: " << (isPositive(number) ? "Yes" : "No") << "\n";
    cout << "Power of 2: " << (isPowerOfTwo(number) ? "Yes" : "No") << "\n";
    cout << "Perfect Number: " << (isPerfectNumber(number) ? "Yes" : "No") << "\n";
    cout << "Perfect Square: " << (isPerfectSquare(number) ? "Yes" : "No") << "\n";

    // Armstrong numbers up to N
    cout << "\nArmstrong Numbers until " << number << ":\n";
    bool first = true;
    for (int i = 0; i <= number; i++) {
        if (isArmstrong(i)) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    if (first) cout << "None";
    cout << "\n";

    // Primes up to N
    cout << "\nPrime Numbers until " << number << ":\n";
    first = true;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i)) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    if (first) cout << "None";
    cout << "\n";

    // Reversible primes check
    cout << "\nPrime Number that are also prime when reversed:\n";
    first = true;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i) && isPrime(reverseNumber(i))) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    if (first) cout << "None";
    cout << "\n\n";

    return 0;
}

int getNumber() {
    int number;
    cout << "Enter Number: ";
    cin >> number;
    return number;
}

bool checkEvenOdd(int number) {
    return (number % 2 == 0); 
}

void displayResult(int number, bool evenOdd) {
    if (!evenOdd) {
        cout << "Number is odd\n";
    }
    else {
        cout << "Number is Even\n";
    }
}