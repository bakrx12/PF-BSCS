#include<iostream>
using namespace std;

// statement:
// program that calculates the sum of the first 50 natural numbers

int main() {
    int sum = 0;

    // first version
    for (int i = 1; i <= 50; ++i) {
        sum += i; // Add the current number to the sum
    }

    // Output the result
    cout << "The sum of the first 50 natural numbers is: " << sum << endl;

    return 0;
}