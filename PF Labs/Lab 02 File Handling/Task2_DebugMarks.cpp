#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int marks[5];
    int total = 0;

    ifstream inFile("marks.txt");                   // Open the file for reading
        
    if (!inFile) {                    // Check
        cout << "File not found!" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        inFile >> marks[i];      // Read
    }

    inFile.close();                          // Close

    cout << "Marks: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
        total = total + marks[i];
    }
    cout << endl << "Total: " << total << endl;
    return 0;
}
