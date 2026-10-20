/*
 * Name       : AbuBakr Aslam
 * Reg No     : L1F24BSCS0052
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ifstream inFile("parking.txt");

    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream receipt("receipts.txt");
    //FOR CONSOLE
    cout << "Parking report for "
         << d << "/" << m << "/" << y << endl;

         //FOR TXT FILE
    receipt << "Receipts for "
            << d << "/" << m << "/" << y << endl;

    char plate[15];
    char type;

    int inHour, inMin;
    int outHour, outMin;

    int vehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;

    int longestMinutes = -1;
    char longestPlate[15];

    while (inFile >> plate >> type >> inHour >> slash >> inMin >> outHour >> slash >> outMin)
    {
        int inTl = inHour * 60 + inMin;
        int outTotal = outHour * 60 + outMin;
        int minutes = outTotal - inTl;
        int hrCharge = (minutes + 59) / 60;

        if (hrCharge == 0) {
            hrCharge = 1;
        }

        int fee;

        if (type == 'C') {
            fee = hrCharge * 100;
            cars++;
        }
        
        else

        {
            fee = hrCharge * 40;
            bikes++;
        }

        int actualHours = minutes / 60;
        int actualMinutes = minutes % 60;

        cout << plate << " "
             << (type == 'C' ? "Car" : "Bike")  //tunary operator used
             << " " << actualHours              //to save time
            << " h " << actualMinutes << " min Fee: " << fee << endl;

        receipt << plate << " " << fee << endl;
        vehicles++;
        totalCollected += fee;

        if (minutes > longestMinutes)
        {
            longestMinutes = minutes;
            strcpy(longestPlate, plate);
        }
    }

    inFile.close();
    receipt.close();

    if (vehicles == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << vehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalCollected << endl;
    cout << "Longest stay: "
         << longestPlate << " (" << longestMinutes / 60 << " h "
         << longestMinutes % 60 << " min)" << endl;

    return 0;
}