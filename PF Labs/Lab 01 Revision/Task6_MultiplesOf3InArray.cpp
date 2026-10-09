#include<iostream>
using namespace std;

/* Statement:
An array that finds all the multiples of 3 in an array of 10 integers */

int main() {

    int arr[10] = {0};
    for(int i = 0; i < 10; i++) {
        cout << "Enter number at index " << i << ": ";
        cin >> arr[i]; }

    cout << "\nMultiples of 3 in the array are: ";
    for(int i = 0; i < 10; i++) {
        if(arr[i] % 3 == 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;

}