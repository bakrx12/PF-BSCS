#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int marks[40];
    int count = 0;

    ifstream inFile("classmarks.txt");

    if (!inFile) {
        cout << "classmarks.txt not found" << endl;
        return 1;
    }

    while (count < 40 && inFile >> marks[count]) {
        count++;
    }
    inFile.close();

    if (count == 0) {
        cout << "No marks found!" << endl;
        return 1;
    }

    int total = 0;
    int highest = marks[0];
    int lowest = marks[0];

    for (int i = 0; i < count; i++) {
        total = total + marks[i];
        if (marks[i] > highest) {
            highest = marks[i];
        }
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    float average = (total) / count;

    int aboveAverageCount = 0;
    for (int i = 0; i < count; i++) {
        if (marks[i] > average) {
            aboveAverageCount++;
        }
    }

    ofstream reportFile("report.txt");
    if (!reportFile) {
        cout << "Could not create report.txt!" << endl;
        return 1;
    }

    reportFile << "Total students: " << count << endl;
    reportFile << "Average: " << average << endl;
    reportFile << "Highest: " << highest << endl;
    reportFile << "Lowest: " << lowest << endl;
    reportFile << "Above average: " << aboveAverageCount << endl;
    reportFile.close();

    ofstream toppersFile("toppers.txt");
    if (!toppersFile) {
        cout << "Could not create toppers.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (marks[i] > average) {
            toppersFile << marks[i] << endl;
        }
    }
    toppersFile.close();

    cout << "Report saved to report.txt" << endl;

    return 0;
}