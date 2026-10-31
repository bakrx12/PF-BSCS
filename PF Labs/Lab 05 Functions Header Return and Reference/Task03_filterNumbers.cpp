#include <iostream>
using namespace std;
 
int countDigits(int n);
int sumDigits(int n);
int reverseNumber(int n);
bool isPalindrome(int n);
bool isHarshad(int n);
 
int main() {
    int n;
 
    cout << "Enter a positive number (0 to stop): ";
    cin >> n;
 
    while (n != 0) {
        cout << "Digits: " << countDigits(n) << endl;
        cout << "Sum of digits: " << sumDigits(n) << endl;
        cout << "Reverse: " << reverseNumber(n) << endl;
        if (isPalindrome(n)) {
            cout << "Palindrome: Yes" << endl;
        }
        else {
            cout << "Palindrome: No" << endl;
        }
        if (isHarshad(n)) {
            cout << "Harshad number: Yes" << endl;
        }
        else {
            cout << "Harshad number: No" << endl;
        }
 
        cout << endl;
        cout << "Enter a positive number (0 to stop): ";
        cin >> n;
    }
    cout << "Goodbye!" << endl;
 
    for (int i = 100; i <= 200; i++) {
        if (isPalindrome(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
 
int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count = count + 1;
        n = n / 10;
    }
    return count;
}
 
int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
 
int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}
 
bool isPalindrome(int n) {
    if (reverseNumber(n) == n) {
        return true;
    }
    else {
        return false;
    }
}
 
bool isHarshad(int n) {
    if (n % sumDigits(n) == 0) {
        return true;
    }
    else {
        return false;
    }
}
