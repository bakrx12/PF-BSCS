// debug boundary error wtvr that is

#include <iostream>
using namespace std;
 
int main() {
    int nums[8];
 
    cout << "Enter 8 numbers: ";
    // changed = cuz index goes from 0 to 7
    for (int i = 0; i < 8; i++) {
        cin >> nums[i];
    }
 
    int smallest = nums[0]; //changed ts aswel, array wasnt used
    for (int i = 1; i < 8; i++) { //changed ts aswel
        if (nums[i] < smallest)
            smallest = nums[i];
    }
    cout << "Smallest value: " << smallest << endl;
 
    cout << "Numbers in reverse order: ";
    for (int i = 7; i > 0; i--) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
