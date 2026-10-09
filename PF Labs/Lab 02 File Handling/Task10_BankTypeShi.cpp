#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice = 0;

    while (choice != 4) {
        cout << "Savings Tracker" << endl;
        cout << "1. Add a deposit" << endl;
        cout << "2. Show all deposits" << endl;
        cout << "3. Start a new month (clear all)" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            int amount;
            cout << "Enter deposit amount: ";
            cin >> amount;

            ofstream outFile("savings.txt", ios::app);
            if (outFile) {
                outFile << amount << endl;
                outFile.close();
                cout << "Deposit added successfully!" << endl;
            }
            else {
                cout << "Error opening file!" << endl;
            }
            cout << endl;

        }
        else if (choice == 2) {
            int deposits[100];
            int count = 0;

            ifstream inFile("savings.txt");

            if (inFile) {
                while (count < 100 && inFile >> deposits[count]) {
                    count++;
                }
                inFile.close();
            }

            if (count == 0) {
                cout << "No deposits yet." << endl;
            }
            else {
                int total = 0;
                int largest = deposits[0];

                for (int i = 0; i < count; i++) {
                    cout << "Deposit " << (i + 1) << ": " << deposits[i] << endl << endl;
                    total = total + deposits[i];
                    if (deposits[i] > largest) {
                        largest = deposits[i];
                    }
                }

                cout << "Total saved: " << total << endl << endl;
                cout << "Largest deposit: " << largest << endl;
            }
            cout << endl;

        }
        else if (choice == 3) {
            ofstream clearFile("savings.txt");
            clearFile.close();
            cout << "All deposits cleared for the new month!" << endl << endl;

        }
        else if (choice == 4) {
            cout << "Exiting Savings Tracker." << endl;
        }
        else {
            cout << "Invalid choice! Please try again." << endl << endl;
        }
    }

    return 0;
}