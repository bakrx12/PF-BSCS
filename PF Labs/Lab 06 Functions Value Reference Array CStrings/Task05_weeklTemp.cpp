#include <iostream>
#include <iomanip>
using namespace std;

void readArray(int arr[], int size);
double average(int arr[], int size);
int countAbove(int arr[], int size, double limit);
void printAbove(int arr[], int size, double limit);

int main() {
    const int SIZE = 7;
    int temp[SIZE];

    cout << "Enter 7 temperatures: ";
    readArray(temp, SIZE);

    double avg = average(temp, SIZE);
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;

    int aboveCount = countAbove(temp, SIZE, avg);
    cout << "Days above average: " << aboveCount << endl;

    cout << "Hot days: ";
    printAbove(temp, SIZE, avg);
    cout << endl;

    return 0;
}

void readArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

double average(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int countAbove(int arr[], int size, double limit) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > limit) {
            count++;
        }
    }
    return count;
}

void printAbove(int arr[], int size, double limit) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > limit) {
            cout << "Day " << (i + 1) << " (" << arr[i] << ") ";
        }
    }
}