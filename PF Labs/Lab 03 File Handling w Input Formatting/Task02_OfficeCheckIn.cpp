#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream checkIn("attendance.txt");    

    if (!checkIn) {
        cout << "attendance.txt doesn't exist\n";
        return 1;
    }

    int readDay[20];
    int readMonth[20];
    int readYear[20];
    int readWorkedHr[20];
    int readWorkedMin[20];
    bool isLate[20];
    
    int count = 0;
    int totalMinutes = 0;
    int lateCount = 0;
    
    char slash;
    int inH, inM, outH, outM;


    while (count < 20 && (checkIn >> readDay[count] >> slash >> readMonth[count] >> slash >> readYear[count])) {
        

        checkIn >> inH;
        checkIn.ignore(1, ':');
        checkIn >> inM;
        

        checkIn >> outH;
        checkIn.ignore(1, ':');
        checkIn >> outM;


        int inTotalMins = inH * 60 + inM;
        int outTotalMins = outH * 60 + outM;
        int workedMins = outTotalMins - inTotalMins;

        readWorkedHr[count] = workedMins / 60;
        readWorkedMin[count] = workedMins % 60;


        totalMinutes += workedMins;


        if (inTotalMins > 540) {
            isLate[count] = true;
            lateCount++;
        } else {
            isLate[count] = false;
        }

        count++;
    }


    for (int i = 0; i < count; i++) {
        cout << readDay[i] << "/" << readMonth[i] << "/" << readYear[i] 
             << "  worked " << readWorkedHr[i] << " h " << readWorkedMin[i] << " min";
        if (isLate[i]) {
            cout << "  (LATE)";
        }
        cout << "\n";
    }

    int totalhr = totalMinutes / 60;
    int totalmins = totalMinutes % 60;

    cout << "\nTotal worked: " << totalhr << " h " << totalmins << " min\n";
    cout << "Days late: " << lateCount << "\n";

    checkIn.close();
    return 0;
}
