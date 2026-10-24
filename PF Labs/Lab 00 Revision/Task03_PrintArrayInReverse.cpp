#include <iostream> 
using namespace std; 

int main() { 

    int nums[7]; 
    
    for (int iNum = 0; iNum < 7; iNum++) { 
        cout << "Enter number at index " << iNum << ": "; 
        cin >> nums[iNum];  
    }
        
    cout << "\nNumber in reverse order: ";

    for (int i = 0; i < 7; i++) {
        cout << nums[6 - i] << " ";
    }

    return 0;
}