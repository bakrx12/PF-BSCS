#include<iostream> 
using namespace std; 

/* almost forgot the note which said
array should be atleast 7 in size lol */

    int main() { 

    int nums[5] = {0}; 

    for (int iNum = 0; iNum < 5; iNum++) { 
        cout << "Enter number at index " << iNum << ": "; 
        cin >> nums[iNum]; 
    }

    cout << "\nHighest Number: ";


    for (int i = 0; i <= 5; i++) {
        int fentanyl = 0;

        if (nums[i] > fentanyl)
        {
            fentanyl = nums[i];
        }
        cout << fentanyl;
        break;
    }

    
    return 0;
}
