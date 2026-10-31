#include <iostream>
using namespace std;
 
void showMenu();
void deposit(int &balance, int amount);
bool withdraw(int &balance, int amount);
void showBalance(int balance);
 
int main() {
    int balance = 1000;
    int choice = 0;
    int amount;
 
    cout << "Welcome to PocketWallet. Starting balance: Rs " << balance << endl;
 
    while (choice != 4) {
        showMenu();
        cin >> choice;
 
        if (choice == 1) {
            cout << "Amount to deposit: ";
            cin >> amount;
            deposit(balance, amount);
            cout << "Deposit successful." << endl;
        }
        if (choice == 2) {
            cout << "Amount to withdraw: ";
            cin >> amount;
            if (withdraw(balance, amount)) {
                cout << "Withdrawal successful." << endl;
            }
        }
        if (choice == 3) {
            showBalance(balance);
        }
        if (choice == 4) {
            cout << "Thank you for using PocketWallet." << endl;
        }
    }
    return 0;
}
 
void showMenu() {
    cout << endl;
    cout << "1. Deposit  2. Withdraw  3. Balance  4. Exit" << endl;
    cout << "Choice: ";
}
 
void deposit(int &balance, int amount) {
    balance = balance + amount;
}
 
bool withdraw(int &balance, int amount) {
    if (amount > 25000) {
        cout << "Limit is Rs 25000 per withdrawal. Nothing was taken out." << endl;
        return false;
    }
    else if (amount > balance) {
        cout << "Not enough balance. Nothing was taken out." << endl;
        return false;
    }
    else {
        balance = balance - amount;
        return true;
    }
}
 
void showBalance(int balance) {
    cout << "Current balance: Rs " << balance << endl;
}
