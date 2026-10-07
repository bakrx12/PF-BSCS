#include<iostream>
using namespace std;

// assignment statement:
// program that calculates the sum of the first 50 natural numbers

int main() {
    int sum = 0;

    // first version
    for (int i = 1; i <= 50; ++i) {
        sum += i; // Add the current number to the sum
    }

    //second version

    int n = 50;
    int formula_sum = n * (n + 1) / 2; // using formula based verification

    // result
    cout << "The sum of the first 50 natural numbers is: " << sum << endl;

    return 0;
}