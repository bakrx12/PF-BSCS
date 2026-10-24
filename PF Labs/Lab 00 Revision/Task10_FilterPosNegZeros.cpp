#include <iostream>
using namespace std;

int main() {
    int SIZE = 10;
    int nums[SIZE];
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    cout << "Enter 10 numbers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> nums[i];
    }

    int largest = nums[0];

    for (int i = 0; i < SIZE; i++) {

        if (nums[i] > 0) {
            positiveCount++;
        } else if (nums[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }

        //largest
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    cout << "\nPositive: " << positiveCount 
         << "\nNegative: " << negativeCount 
         << "\nZero: " << zeroCount 
         << "\nLargest: " << largest << endl;

    return 0;
}