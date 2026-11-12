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

int main() {
    char arr[50] = "cXdaHklM";
    int length = strlen(arr);

    int lower = 0, upper = 0;
    char sortedUpper[50];
    char sortedLower[50];

    for (int i = 0; i < length; i++) {
        if (arr[i] >= 65 && arr[i] <= 90) {
            sortedUpper[upper] = arr[i]; 
            upper++;
        }}

    for (int i = 0; i < length; i++) {
        if (arr[i] >= 97 && arr[i] <= 122) {
            sortedLower[lower] = arr[i]; 
            lower++;
        }

    }

    sortedLower[lower] = '\0';
    sortedUpper[upper] = '\0';
        cout << sortedLower;
        cout << sortedUpper;


}