#include<iostream>
using namespace std;

int getConsumerID();
void getConsumedUnit(int &units);
double finalBill(int units);
void printBill(int consumerID, int units);


int main() {
    int consumerID, units;
    consumerID = getConsumerID();
    getConsumedUnit(units);
    printBill(consumerID, units);
}

int getConsumerID() {
    int consumerID;
    cout << "Enter Consumer ID: ";
    cin >> consumerID;
    return consumerID;
}

void getConsumedUnit(int &units) {
    cout << "Enter consumed units: ";
    cin >> units;
}

double finalBill(int units) {
    if (units < 100) {
        return units*10;
    }
    else if (units < 200) {
        return ((100*10) + (units-100)*15);
    }
    else {
        return ((100*10) + (100*15) + (units - 200)*20);
    }
}

void printBill(int consumerID, int units) {
    cout << endl << "Consumer ID: " << consumerID;
    cout << endl << "Consumed Units: " << units;
    cout << endl << "PAYABLE BILL: " << finalBill(units);
}