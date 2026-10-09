#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int temp;
    cout << "Enter today's temperature: ";
    cin >> temp;

    ofstream outFile("temperature.txt", ios::app);

    if (!outFile) {
        cout << "File not opened" << endl;
        return 1;
    }

    outFile << temp << endl;
    outFile.close();

    cout << endl << "Saved! Reading added to temperature.txt" << endl;

    return 0;
}