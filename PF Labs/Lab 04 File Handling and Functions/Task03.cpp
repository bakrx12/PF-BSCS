#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("innings.txt");
    if (!inFile) {
        cout << "Error: innings.txt doesnt exists" << endl;
        return 1;
    }

    int score;
    int count = 0;
    int totalRuns = 0;

    while (inFile >> score) {
        count++;
        totalRuns += score;
        inFile.ignore(1, ';');
    }

    if (count == 0) {
        cout << "No innings found." << endl;
        inFile.close();
        return 0;
    }

    int average = totalRuns / count;

    cout << "Innings played: " << count << endl;
    cout << "Total runs: " << totalRuns << endl;
    cout << "Average: " << average << endl;
    cout << "Innings above average:" << endl;

    inFile.clear();
    inFile.seekg(0);

    ofstream outFile("good_innings.txt");
    int currentInnings = 1;

    while (inFile >> score) {
        if (score > average) {
            cout << "Innings " << currentInnings << ": " << score << endl;
            outFile << currentInnings << " " << score << "\n";
        }
        currentInnings++;
        inFile.ignore(1, ';');
    }

    inFile.close();
    outFile.close();

    return 0;
}