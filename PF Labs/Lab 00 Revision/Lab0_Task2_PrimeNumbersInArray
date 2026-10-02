#include<iostream> 
using namespace std; 

//used same bool isPrime logic from previous task, and reconfigured it for arrays
int main() { 

    int nums[20] = {0}; 

    for (int iNum = 0; iNum < 20; iNum++) { 
        cout << "Enter number at index " << iNum << ": "; 
        cin >> nums[iNum]; 
    }

    cout << "\nPrime Numbers: ";


    for (int iNum = 0; iNum < 20; iNum++) {
        int currentNum = nums[iNum];


        if (currentNum <= 1) {
            continue; 
        }

        bool isPrime = true; 
        for (int j = 2; j * j <= currentNum; j++) { 
            if (currentNum % j == 0) { 
                isPrime = false; 
                break; 
            } 
        } 

        if (isPrime) { 
            cout << currentNum << " "; 
        } 
    }

    
    return 0;
}
