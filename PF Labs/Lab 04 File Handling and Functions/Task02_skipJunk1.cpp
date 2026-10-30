#include <iostream>
#include <fstream>

using namespace std;

//question 2 answers:
//replace ignore() with inFile >> junk
//ignore(1) skips ONLY one character at a time


int main() {
    ifstream inFile("meter.txt");
    if (!inFile) {
        cout << "Error opening meter.txt" << endl;
        return 1;
    }

    int readings[20];
    int count = 0;
    int skippedChars = 0;

    while (count < 20) {
        int val;
        if (inFile >> val) {
            readings[count] = val;
            count++;
        } 
        else if (inFile.eof()) {
            break; 
        } 
        else {
            inFile.clear();
            inFile.ignore(1);
            skippedChars++;
        }
    }
    inFile.close();

    cout << "Readings kept: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << readings[i] << " ";
    }
    cout << endl;

    cout << "Characters skipped: " << skippedChars << endl;

    if (count > 0) {
        int totalUnits = readings[count - 1] - readings[0];
        cout << "Total units used: " << totalUnits << endl;
    }

    ofstream outFile("usage.txt");
    for (int i = 1; i < count; i++) {
        outFile << "Day " << i << " => Day " << i + 1 << ": "  << (readings[i] - readings[i - 1]) << " units\n";
    }
    outFile.close();

    return 0;
}