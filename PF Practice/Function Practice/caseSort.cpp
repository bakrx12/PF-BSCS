//Mids 2022 Problem Question

/* PROBLEM:

Create a function that receives a CString of size 50, containing only
upper case and lower case alphabets. The function will sort the array
such that all the lower case alphabets appear before all the upper case
alphabets in the CString. (a = 97, A = 65 )

SAMPLE:
Input String: cXdaHklM
output: cdaklXHM

*/

#include<iostream>
#include<cstring>
using namespace std;

//commit history, solve with:
//1. two seperate arrays without functions
//2. original array and temp without functions
//3. original array without temp implemented in functions 

void sortCString(char arr[]) {
    int length = strlen(arr);
    int idx = 0; 

    for (int i = 0; i< length; i++) {
            if (arr[i] >= 'a' && arr[i] <= 'z') {
            char currentLower = arr[i]; 

            for (int j = i; j > idx; j--)
                {
                    arr[j] = arr[j - 1];
                }

        arr[idx] = currentLower;
        idx++;
    }
}}

int main()
{
    char arr[50] = "cXdaHklM";
    sortCString(arr);
    cout << arr;

    return 0;
}
