#include<iostream>
using namespace std;

int main() {

    int arr[10] = {0};
    cout << "Enter 10 numbers: ";
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Multiples of 3 in the array are: ";
    for(int i = 0; i < 10; i++) {
        if(arr[i] % 3 == 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;

}