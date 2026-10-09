// statement

/* The program below should read any number of integers (at most 100)
from input.txt, and write them to a new file named reversed.txt in reverse order.
It should also handle two problems: input.txt does not exist, or input.txt is empty.
Six parts are missing. */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int nums[100];
    int count = 0;

    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "input.txt not found!" << endl;
        return 1;
    }

    while (count < 100 && inFile >> nums[count]) {
        count++;
    }
    inFile.close();

    if (count == 0) {
        cout << "The file is empty!" << endl;
        return 1;
    }

    ofstream outFile("reversed.txt");
    if (!outFile) {
        cout << "Could not create reversed.txt!" << endl;
        return 1;
    }

    for (int i = count - 1; i >= 0; i--) {
        outFile << nums[i] << endl;
    }
    outFile.close();

    cout << count << " numbers written to reversed.txt" << endl;
    return 0;
}