#include <iostream>
#include <fstream> //ts wasnt there
using namespace std;

int main() {
    int marks[6];
    int passCount = 0;

    ifstream inFile("results.txt"); //this was incorrectly used before for reading
    ofstream outFile("passed.txt"); //this was incorrectly used before for writing

    if (!inFile || !outFile) {
        cout << "Error opening file!" << endl; //this check was not present, so i added it
        return 1;
    }


    //if i <= 6 it would try to access 6th index
    //problem only needs to run till 5th index
    
    for (int i = 0; i < 6; i++) {
        inFile >> marks[i];
    }
    inFile.close(); // added close 

    for (int i = 0; i < 6; i++) {
        if (marks[i] >= 50) {
            outFile << marks[i] << endl;
            passCount++;
        }
    }
    outFile.close(); // added close 

    cout << "Students passed: " << passCount << endl;

    return 0;
}