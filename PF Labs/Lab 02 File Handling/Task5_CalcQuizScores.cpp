#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int scores[50]; //since we know scores are 50
    int count = 0;

    ifstream inFile("scores.txt");

    if (!inFile) {
        cout << "File not found!" << endl;
        return 1;
    }

    //unknown values
    while (count < 50 && inFile >> scores[count]) {
        count++;
    }

    inFile.close();

    int passed = 0;
    int failed = 0;

    //showiung the count 
    cout << "Scores loaded: " << count << endl << endl;

    cout << "Scores: ";
    for (int i = 0; i < count; i++) {
        cout << scores[i] << " ";
        if (scores[i] >= 10) {
            passed++;
        }
        else {
            failed++;
        }
    }
    cout << endl << endl;

    cout << "Passed: " << passed << endl << endl;
    cout << "Failed: " << failed << endl;

    return 0;
}