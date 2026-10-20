/*
 * Name       : Student Name
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q4 - Heart Rate Cleaner
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("heart_rate.txt");
    if (!inFile) {
        cout << "heart_rate.txt not found!" << endl;
        return 1;
    }

    int rate[100];
    int count = 0;      // number of valid readings stored in rate[]
    int bad = 0;        // number of junk words skipped
    int x;
    char junk[50];
    int reason = 0;     // 1 = sentinel found, 2 = end of file, 3 = array full

    while (true) {
        if (_______(1)_______) {           // the array is full
            reason = 3;
            break;
        }
        if (inFile >> x) {                 // a number was read
            if (_______(2)_______) {       // the sentinel value
                reason = 1;
                break;
            }
            rate[count] = x;
            _______(3)_______;
        }
        else if (_______(4)_______) {      // nothing left in the file
            reason = 2;
            break;
        }
        else {                             // a junk word
            _______(5)_______;
            inFile >> junk;
            bad++;
        }
    }
    inFile.close();

    // TODO 1: Write every valid reading to clean_heart_rate.txt (one per line).

    // TODO 2: Display "Valid readings: " and "Junk skipped: ".

    // TODO 3: If count is 0, display "No valid readings!".
    //         Otherwise display the Average, Highest, Above average
    //         and Alerts (above 100) lines.

    // TODO 4: Display "Stopped because: " followed by
    //         sentinel found, end of file or array full.

    return 0;
}
