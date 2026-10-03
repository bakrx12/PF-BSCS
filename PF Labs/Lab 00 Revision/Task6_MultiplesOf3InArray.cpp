#include<iostream>
using namespace std;

int main() {

    int arr[10] = {0};
    cout << "Enter 10 numbers: ";
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
<<<<<<< HEAD

    //finding multiples

    for (int i = 0; i < 10; i++) {
        if(arr[i] % 3 == 0) {
            cout << arr[i] << " is a multiple of 3" << endl;
        }
    }
=======
>>>>>>> 28391fe8d538e8c2e978735c0e8edf875eb674b0

    return 0;

}