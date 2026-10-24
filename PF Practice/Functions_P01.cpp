#include <iostream>
using namespace std;

// Sample of Standard Function
    // return datatype, variable name (return variable) 
    // int addNumbers(int a, int b);


/* Function defination outside of main function
    MUST be declared above main() since compiler reads 
    from top to bottom. function can be DEFINED below the main() */


    // Sample of Function with parameters
    // return datatype, variable name (return parameters) 
    int addNumbers(int a, int b) {
        return a + b; }

    /*
    // 1. Function Prototype (above main)
    int square(int n); 

    // Main Function
    int main() {
        cout << square(5); 
        return 0; }

    // 2. Function Definition (below main)
    int square(int n) {
        return n * n; } */

// Parameter passing modes

    //1. Pass by Value
    // Modifications inside the function do not affect/modify the original variable
    void modifyValue(int num) {
        num = 100; // Changes local copy only
    }

    //2. Pass by Reference (&)
    //The function receives an alias/reference to the original variable
    //Modifications directly alter the original argument
    //ADVANTAGE: Saves memory by avoiding copying large objects

    void modifyReference(int &num) {
        num = 100; // Modifies the original variable
    }

    //3. Pass by Pointer (*)
    //The function receives a memory address
    //for accessing the variable at pointer-level

    //Requires explicit dereferencing (*) inside the function
    //body and passing addresses (&) during function calls

    void modifyPointer(int *ptr) {
        if (ptr != nullptr) {
            *ptr = 100; // Modifies the variable at memory address
        }
    }

// Default Arguments
//You can specify default values for parameters 
//in the function prototype/declaration

    //setting default values for functions
    // Correct placement: default argument is at the end
    void displayGrid(int rows, int cols = 5);

    void displayGrid(int rows, int cols) {
        cout << rows << "x" << cols << endl;
    }

    // Calls:
    displayGrid(3);    // Outputs: 3x5
    displayGrid(3, 8); // Outputs: 3x8

    //TO CONCLUDE:
    //If arguments are omitted during a call,
    //the default values are applied

// Function overloading

//You can specify default values for parameters
//in the function prototype/declaration

    // Default parameters must be placed at the end of the parameter list
    //If arguments are omitted during a call, the default values are applied

    int multiply(int a, int b) {
    return a * b; }

    double multiplyd(double a, double b) {
        return a * b; }

    int multiplyi(int a, int b, int c) {
        return a * b * c; }


// Scope and Storage Duration

    /*
    Local Variables:
        Defined inside a function block.
        Created upon entering the function
        and destroyed upon exiting (stack memory)

    Global Variables:
        Defined outside all functions.
        Accessible throughout the file,
        but prone to unintended side effects

    Static Local Variables:
        Declared with static. Initialized once and retain
        their value across multiple function calls until execution ends
    */

    void countCalls() {
    static int callCount = 0; // Retains value between function invocations
    callCount++;
    cout << "Call count: " << callCount << endl;

// Arrays and Functions

//Arrays are passed to functions as pointers
//(decaying to a pointer to the first element)
//Affect/changes to array elements inside function

//NOTE:When passing arrays, always pass the array size separately
//(unless using C++11 std::array or std::vector)

    void printArray(const int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

// Recursion
// A function that calls itself to solve a smaller

    // Instance of the same problem. Every recursive function must have
        //1. Base Case: A stopping condition to prevent infinite stack overflow
        //2. Recursive Step: Modifies state towards the base case

    int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive step
    }

//common quiz pitfalls

    /*
    
    - Missing Prototype:
        Calling a function before declaring or defining it
        leads to a compiler error (identifier not found)
    - Ambiguous Function Calls:
        Creating overloaded functions where type conversion
        makes the compiler unsure which version to execute
    - Array Decay Loss:
        Trying to calculate sizeof(arr) inside a function
        expecting a raw array returns pointer size
        (4 or 8 bytes), not the total array size
    - Returning References to Local Variables:
        Returning a reference or pointer to a non-static local
        variable results in undefined behavior because the
        variable is destroyed when the function returns

    */

int main() {
    int sum = addNumbers(5, 10); // Function call
    cout << "Sum: " << sum << endl;
    return 0;
}


}