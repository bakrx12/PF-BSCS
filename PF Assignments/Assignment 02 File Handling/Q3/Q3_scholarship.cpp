/*
 * Name       : AbuBakr Aslam
 * Reg No     : L1F24BSCS0052
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    char path[100];

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);


    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 0;
    }

    int n;
    inFile >> n;
    inFile.ignore(100, '\n');

    if (n > 30) {
        cout << "Too many students!" << endl;
        inFile.close();
        return 0;
    }

    ofstream scholarship("scholarship.txt");

    char name[30];
    char topName[30];

    int count = 0;
    int eligible = 0;

    double cgpa;
    double total = 0;
    double highest = -1;

    for (int i = 0; i < n; i++) {

        if (!inFile.getline(name, 30, ',')) {
            break;
        }

        if (!(inFile >> cgpa)) {
            break;
        }

        inFile.ignore(100, '\n');
        cout << "[" << name << "] CGPA: " << cgpa << endl;
        count++;
        total += cgpa;

        if (cgpa >= 3.50) {
            scholarship << name << "," << cgpa << endl;
            eligible++;
        }

        if (cgpa > highest) {
            highest = cgpa;
            strcpy(topName, name);
        }
    }

    if (count < n) {
        cout << "Warning: only " << count
             << " of " << n
             << " records found." << endl;
    }

    if (count == 0) {
        cout << "No students found!" << endl;
        inFile.close();
        scholarship.close();
        return 0;
    }

    cout << "Students: " << count << endl;
    cout << "Average CGPA: "
         << total / count << endl;
    cout << "Eligible for scholarship: "
         << eligible << endl;
    cout << "Top student: "
         << topName << " (" << highest << ")" << endl;

    inFile.close();
    scholarship.close();

    return 0;
}