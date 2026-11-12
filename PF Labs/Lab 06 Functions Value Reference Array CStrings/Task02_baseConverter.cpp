#include <iostream>
using namespace std;

bool isValidDigit(int num, int base);
int toDecimal(int num, int base);
int fromDecimal(int decimalNum, int base02);

int main() {
    int num, base01, base02;

    while (true) {
        cout << "Enter number, its base, new base (0 to stop): ";
        cin >> num;
        if (num == 0) {
            cout << "Goodbye." << endl;
            break;
        }
        cin >> base01 >> base02;
                           
        if (!isValidDigit(num, base01)) {
            cout << "Invalid digit for base " << base01 << "." << endl;
        } else {
            int decimalVal = toDecimal(num, base01); 
            int convertedVal = fromDecimal(decimalVal, base02);
            cout << num << " (base " << base01 << ") = " 
                 << convertedVal << " (base " << base02 << ")" << endl;
        }
    }

    return 0;
}

bool isValidDigit(int num, int base) {
    int temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit >= base) {
            return false;
        }
        temp /= 10;
    }
    return true;
}

int toDecimal(int num, int base) {
    int decimalVal = 0;
    int multiplier = 1;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        decimalVal += digit * multiplier;
        multiplier *= base;
        temp /= 10;
    }
    return decimalVal;
}

int fromDecimal(int decimalNum, int base02) {
    if (decimalNum == 0) return 0;

    int result = 0;
    int place = 1;
    int temp = decimalNum;

    while (temp > 0) {
        int remainder = temp % base02;
        result += remainder * place;
        place *= 10;
        temp /= base02;
    }
    return result;
}