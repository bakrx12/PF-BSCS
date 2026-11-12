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

int main() {
    //array size to remain constant
    char arr[50] = "cXdaHklM";
    int length = strlen(arr);
    char temp[50];
    int tempidx = 0;

    //order loops in order it needs to be printed

    for (int i = 0; i < length; i++) {
        if (arr[i] >= 97 && arr[i] <= 122) {
            temp[tempidx] = arr[i]; 
            tempidx++;
        }}

        for (int i = 0; i < length; i++) {
        if (arr[i] >= 65 && arr[i] <= 90) {
            temp[tempidx] = arr[i]; 
            tempidx++;
        }

    }
        //do it before strcpy to avoid garbadge values
        temp[tempidx] = '\0';

    //strcpy(desitnation, source);
    strcpy(arr, temp);

    cout << arr;
}