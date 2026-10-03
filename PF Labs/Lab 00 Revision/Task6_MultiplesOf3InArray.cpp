#include<iostream>
using namespace std;

int main() {

    int arr[10] = {0};
    cout << "Enter 10 numbers: ";
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    //finding multiples

    for (int i = 0; i < 10; i++) {
        if(arr[i] % 3 == 0) {
            cout << arr[i] << " is a multiple of 3" << endl;
        }
    }

    return 0;

}