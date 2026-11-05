/* Problem:
Asks the user for 5 numbers and stores them in an array
Saves them to numbers.txt
On a second run, reads them back and prints their sum */

#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream inNum("numbers.txt");

    if (inNum) {
        int num[5];
        int sum = 0;

        for (int i = 0; i < 5; i++) {
            inNum >> num[i];
            sum += num[i]; }

        inNum.close();
        cout << "Numbers.txt file already exists!" << sum << endl;
        cout << "Sum: " << sum << endl;
    }

    else {    
        int num[5];
        cout << "Enter five values: ";
        
        for (int i = 0; i < 5; i++) {
            cin >> num[i];
        }

        ofstream outNum("numbers.txt");

        if (!outNum) {
            cout << "File not created!";
            return 1;
        }

        if (inNum) {
            int num[5];
            int sum = 0;

            for (int i = 0; i < 5; i++) {
                inNum >> num[i];
                sum += num[i];
            }
            inNum.close();

            cout << "File found! Reading values...\n";
            cout << "Sum: " << sum << endl;
        }
    }
}