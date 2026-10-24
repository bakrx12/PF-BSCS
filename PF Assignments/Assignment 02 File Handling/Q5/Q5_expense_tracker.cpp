/*
 * Name       : AbuBakr Aslam
 * Reg No     : L1F24BSCS0052
 * Assignment : 02 - File Handling
 * Question   : Q5 - Expense Tracker
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

    int choice;
    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            char category[20];
            int amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount!" << endl;
            } else {
                ofstream outFile("expenses.txt", ios::app);
                outFile << category << " " << amount << endl;
                outFile.close();
                cout << "Expense saved." << endl;
            }
        }

        else if (choice == 2) {
            ifstream inFile("expenses.txt");
            char category[20];
            int amount;
            int count = 0;
            int total = 0;
            char largestCategory[20];
            int largestAmount = 0;
            bool found = false;

            while (inFile >> category >> amount) {
                found = true;
                count++;
                total += amount;
                cout << count << ". " << category << " " << amount << endl;
                if (count == 1 || amount > largestAmount) {
                    largestAmount = amount;
                    strcpy(largestCategory, category);
                }
            }

            inFile.close();

            if (!found) {
                cout << "No expenses yet." << endl;
            } else {
                cout << "Total spent: " << total << endl;
                cout << "Largest expense: " << largestCategory
                     << " (" << largestAmount << ")" << endl;
            }
        }

        else if (choice == 3) {
            char ctg[20];
            cout << "Enter category: ";
            cin >> ctg;
            ifstream inFile("expenses.txt");
            char category[20];
            int amount;
            int count = 0;
            int total = 0;

            while (inFile >> category >> amount) {

                if (strcmp(category, ctg) == 0) {
                    count++;
                    total += amount;
                }
            }
            inFile.close();
            if (count == 0) {
                cout << "No expenses found for " << ctg << endl;
            } else {
                cout << "Expenses in " << ctg << ": " << count << endl;
                cout << "Total for " << ctg << ": " << total << endl;
            }
        }

        else if (choice == 4) {

            ofstream outFile("expenses.txt");
            outFile.close();
            cout << "All expenses cleared." << endl;
        }

        else if (choice == 5) { cout << "Goodbye!" << endl; }
        else { cout << "Invalid choice!" << endl; }
    }
    while (choice != 5);
    return 0;
}