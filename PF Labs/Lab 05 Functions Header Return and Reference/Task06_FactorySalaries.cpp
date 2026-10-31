#include <iostream>
using namespace std;
 
void readWorker(double &hours, double &rate);
double grossPay(double hours, double rate);
double taxOn(double gross);
void payGrade(double net);
void printSlip(int workerNo, double hours, double gross, double tax, double net);
 
int main() {
    int workers, i = 1;
    double hours, rate, gross, tax;
    double total = 0;
 
    cout << "How many workers? ";
    cin >> workers;
 
    while (i <= workers) {
        cout << endl;
        cout << "Worker " << i << endl;
        readWorker(hours, rate);
        gross = grossPay(hours, rate);
        tax = taxOn(gross);
        printSlip(i, hours, gross, tax, gross - tax);
        total = total + gross - tax;
        i = i + 1;
    }
 
    cout << endl;
    cout << "Total paid to all workers: Rs " << total << endl;
    return 0;
}
 
void readWorker(double &hours, double &rate) {
    cout << "Hours worked and rate per hour: ";
    cin >> hours >> rate;
}
 
double grossPay(double hours, double rate) {
    if (hours > 160) {
        return 160 * rate + (hours - 160) * rate * 1.5;
    }
    else {
        return hours * rate;
    }
}
 
double taxOn(double gross) {
    if (gross <= 50000) {
        return 0;
    }
    else if (gross <= 100000) {
        return gross * 5 / 100;
    }
    else {
        return gross * 10 / 100;
    }
}
 
void payGrade(double net) {
    if (net >= 100000) {
        cout << "A";
    }
    else if (net >= 40000) {
        cout << "B";
    }
    else {
        cout << "C";
    }
}
 
void printSlip(int workerNo, double hours, double gross, double tax, double net) {
    cout << "---- Salary Slip: Worker " << workerNo << " ----" << endl;
    cout << "Hours: " << hours << endl;
    cout << "Gross pay: Rs " << gross << endl;
    cout << "Tax: Rs " << tax << endl;
    cout << "Net pay: Rs " << net << endl;
    cout << "Grade: ";
    payGrade(net);
    cout << endl;
}
