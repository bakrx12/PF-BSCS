
#include <iostream>
using namespace std;
 
void showBanner();
void printDashes(int n);
double area(double length, double width);
void canVote(int roll, int age);
int fullWeeks(int days);
void passOrFail(int marks);
void addFine(double &fee);
void readStudent(int &roll, int &age);
 
int main() {
    int roll, age, marks;
    double fee;
 
    showBanner();
    readStudent(roll, age);
    canVote(roll, age);
 
    cout << "Enter marks: ";
    cin >> marks;
    cout << "Result: ";
    passOrFail(marks);
 
    cout << "Enter fee: ";
    cin >> fee;
    addFine(fee);
    cout << "Fee after 10% fine: " << fee << endl;
 
    printDashes(30);
 
    cout << area(7.5, 6) << endl;
    cout << fullWeeks(30) << endl;
    return 0;
}
 
void showBanner() {
    printDashes(30);
    cout << "    STUDENT HELP DESK" << endl;
    printDashes(30);
}
 
void printDashes(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "-";
    }
    cout << endl;
}
 
double area(double length, double width) {
    return length * width;
}
 
void canVote(int roll, int age) {
    if (age >= 18) {
        cout << "Roll " << roll << " can vote." << endl;
    }
    else {
        cout << "Roll " << roll << " cannot vote yet." << endl;
    }
}
 
int fullWeeks(int days) {
    return days / 7;
}
 
void passOrFail(int marks) {
    if (marks >= 50) {
        cout << "P" << endl;
    }
    else {
        cout << "F" << endl;
    }
}
 
void addFine(double &fee) {
    fee = fee + fee * 10 / 100;
}
 
void readStudent(int &roll, int &age) {
    cout << "Enter roll number and age: ";
    cin >> roll >> age;
}
