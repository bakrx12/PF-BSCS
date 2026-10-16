#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream forecast("rainfall.txt");
    ofstream render("rainy_days.txt");

    if (!forecast) {
        cout << "rainfall.txt doesn't exist\n";
        return 1;
    }

    double readings[31];
    int count = 0;
    double total = 0.0;
    char comma;


    while (count < 31 && (forecast >> readings[count])) {
        total += readings[count];
        count++;


        if (!(forecast >> comma)) {
            break; 
        }
    }

    forecast.close();


    cout << "Total Days: " << count << "\n\n";


    cout << "Readings: ";
    for (int i = 0; i < count; i++) {
        cout << readings[i] << " ";
    }
    cout << "\n\n";


    cout << "Total rainfall: " << total << " mm\n\n";


    double average = (count > 0) ? (total / count) : 0.0;
    cout << "Average: " << average << " mm\n\n";

    for (int i = 0; i < count; i++) {
        if (readings[i] > 0) {
            render << "Day " << (i + 1) << ": " << readings[i] << " mm\n";
        }
    }
    render.close();

    return 0;
}
