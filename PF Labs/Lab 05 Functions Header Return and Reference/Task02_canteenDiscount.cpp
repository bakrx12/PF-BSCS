#include <iostream>
using namespace std;
 
void showMenu();
int priceOf(int code);
void printName(int code);
int discountPercent(int subtotal);
double finalBill(int subtotal);
 
int main() {
    int code, qty;
    int subtotal = 0;
 
    showMenu();
    cout << "Enter item code (0 to finish): ";
    cin >> code;
 
    while (code != 0) {
        if (priceOf(code) == 0) {
            cout << "Invalid code, try again." << endl;
        }
        else {
            cout << "Quantity: ";
            cin >> qty;
            cout << "  ";
            printName(code);
            cout << " x " << qty << " = Rs " << priceOf(code) * qty << endl;
            subtotal = subtotal + priceOf(code) * qty;
        }
        cout << "Enter item code (0 to finish): ";
        cin >> code;
    }
 
    cout << "Subtotal: Rs " << subtotal << endl;
    cout << "Discount: Rs " << subtotal - finalBill(subtotal) << endl;
    cout << "Amount to pay: Rs " << finalBill(subtotal) << endl;
    return 0;
}
 
void showMenu() {
    cout << "===== SCHOOL CANTEEN =====" << endl;
    cout << "1. Samosa     Rs 50" << endl;
    cout << "2. Shawarma   Rs 250" << endl;
    cout << "3. Juice      Rs 120" << endl;
    cout << "4. Tea        Rs 60" << endl;
    cout << "5. Biryani    Rs 300" << endl;
    cout << "==========================" << endl;
}
 
int priceOf(int code) {
    if (code == 1) {
        return 50;
    }
    else if (code == 2) {
        return 250;
    }
    else if (code == 3) {
        return 120;
    }
    else if (code == 4) {
        return 60;
    }
    else if (code == 5) {
        return 300;
    }
    else {
        return 0;
    }
}
 
void printName(int code) {
    if (code == 1) {
        cout << "Samosa";
    }
    else if (code == 2) {
        cout << "Shawarma";
    }
    else if (code == 3) {
        cout << "Juice";
    }
    else if (code == 4) {
        cout << "Tea";
    }
    else if (code == 5) {
        cout << "Biryani";
    }
}
 
int discountPercent(int subtotal) {
    if (subtotal >= 2000) {
        return 15;
    }
    else if (subtotal >= 1000) {
        return 10;
    }
    else {
        return 0;
    }
}
 
double finalBill(int subtotal) {
    return subtotal - subtotal * discountPercent(subtotal) / 100.0;
}
