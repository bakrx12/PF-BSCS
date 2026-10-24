// debug thjis code

#include <iostream>
using namespace std;
 
int main() {
    int marks[5];

    //ye initialize ni kiya huwa tha
    int sum =0;
    float average;
    int countAbove = 0;
 
    cout << "Enter marks of 5 students: ";
    for (int i = 0; i < 5; i++) {
        cin >> marks[i];
    }
 
    for (int i = 0; i < 5; i++) {
        /*sum = marks[i];                     son   */ 
        sum += marks[i];
    }
 
    /*average = sum / 5;  use float for ts*/
    average = sum / 5.0f;

 
    for (int i = 0; i < 5; i++) {
        if (marks[i] > average)
            countAbove++;
    }
 
    cout << "Average: " << average << endl;
    cout << "Students above average: " << countAbove << endl;
    return 0;
}
