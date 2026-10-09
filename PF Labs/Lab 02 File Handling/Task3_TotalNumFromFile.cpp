#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int num[5];
    int total = 0;

    ifstream inFile("num.txt");

    if (!inFile) {
        cout << "File not found" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        inFile >> num[i];
    }

    inFile.close();

    int largest = num[0];
    int smallest = num[0];

    for (int i = 0; i < 5; i++) {
        if (num[i] > largest) {
            largest = num[i];
        }
        if (num[i] < smallest) {
            smallest = num[i];
        }
        total = total + num[i];
    }

    float average = total / 5.0;

    cout << "Largest: " << largest << endl << endl;
    cout << "Smallest: " << smallest << endl << endl;
    cout << "Average: " << average << endl;

    return 0;
}