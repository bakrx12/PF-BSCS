#include <iostream>
#include <fstream>
using namespace std;

//question 1 answer:
//because fail() is used befre eof(), it incorrectly read bad data
//reading int values so char / string values can't be passed here

int main() {
    char fileName[50];
    cout << "Enter file name: ";
    cin >> fileName;

    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error: Could not open file " << fileName << endl;
        return 1; }

    int marks[5];
    int count = 0;
    int val;

    while (count < 5 && inFile >> val) {
        marks[count] = val;
        count++;
    }

    cout << "Numbers read: " << count << endl;

    if (count > 0) {
        int sum = 0;
        cout << "Values: ";
        for (int i = 0; i < count; i++) {
            cout << marks[i] << " ";
            sum += marks[i];
        }
        cout << endl;
        cout << "Average: " << sum / count << endl;
    }

    ofstream logFile("check_log.txt", ios::app);

    if (count == 5 && inFile) {
        cout << "Reason: Array is full (the file has more data)" << endl;
        logFile << fileName << " full\n";
    } 
    else if (inFile.eof()) {
        if (count == 0) {
            cout << "Reason: The file is empty!" << endl;
            logFile << fileName << " empty\n";
        } else {
            cout << "Reason: End of file (normal)" << endl;
            logFile << fileName << " normal\n";
        }
    } 
    else if (inFile.fail()) {
        cout << "Reason: Bad data found after " << count << " numbers" << endl;
        logFile << fileName << " bad data after " << count << "\n";
    }

    inFile.close();
    logFile.close();

    return 0;
}