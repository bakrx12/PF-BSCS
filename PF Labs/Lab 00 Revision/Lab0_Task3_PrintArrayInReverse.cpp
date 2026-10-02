#include<iostream> 
using namespace std; 

//almost forgot the note 

//array should be atleast 7 in size lol
//without using an extra array

    int main() { 

    int nums[3] = {0}; 
    for (int iNum = 0; iNum < 3; iNum++) { 
        cout << "Enter number at index " << iNum << ": "; 
        cin >> nums[iNum];  }
        

    cout << "\nNumber in reverse order: ";

    //method 1: W/O using another array



    //method 2: using decrement
        for (int i = 6; i >= 0; i--) {
        cout <<  nums[i] << " ";
    }

    return 0;
}
