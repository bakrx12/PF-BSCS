#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int values[5];
    int count = 0;

    ifstream inFile("values.txt");

    if (!inFile) {
        cout << "values.txt not found!" << endl;
        return 1;
    }

    while (count < 5 && inFile >> values[count]) {
        count++;
    }
    inFile.close();

    if (count < 5) {
        cout << "Warning: only " << count << " values could be read." << endl;
    }

    cout << "Count: " << count << endl;
    cout << "Values: ";
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}