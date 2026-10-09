# WEEK 1: Logic Building, Arrays (Numeric Types Only)

Note: This lab includes a total of 10 questions.

### Objectives
* Explore logic building using loops and conditional statements.
* Understand array operations including input, access, update, and reversal.
* Identify and work with prime numbers, multiples, and maximum values in arrays.
* Apply array manipulation in practical scenarios like top scores and velocity reversal.
* Revision of concepts related to numeric arrays and problem-solving in C++.
* Debug partially correct programs, fix boundary (off-by-one) errors, and test programs with multiple inputs.

---

### Tasks

**Q1.** Write a C++ program which will print prime numbers up to a given value. 

* **Sample Input:**
  ```text
  Enter Limit: 40
  ```
* **Sample Output:**
  ```text
  Prime Numbers: 2,3,5,7,11,13,17,19,23,29,31,37
  ```
* **Hint (Prime Number Logic):** A prime number is greater than 1 and is divisible only by 1 and itself. Numbers less than 2 (0, 1 and negative numbers) are not prime. To check a number n, try dividing it by every number d from 2 up to n − 1. (Faster: stop when d * d > n.) If n % d == 0 for any d, then n is not prime, so you can stop checking with break. If no such d is found, n is prime.
* **Tip:** set a variable `bool isPrime = true;` before the checking loop, and change it to `false` when a divisor is found. Example: 15 is not prime because 15 % 3 == 0. 13 is prime because no number from 2 to 12 divides it exactly. Use the same logic in Q2 to check each element of the array.

**Q2.** Write a C++ program which inputs 20 numbers in an array. Your program should only display all the prime numbers found in the array. 

**Q3.** Write a C++ program to read 5 elements in an array and reverse the array and print it.

* **Example:** 
  If the elements of the array are: `10, 5, 16, 35, 500` 
  Then its reverse would be: `500, 35, 16, 5, 10` 
  That is if:
  * `array[0] = 10` 
  * `array[1] = 5`                                             
  * `array[2] = 16` 
  * `array[3] = 35` 
  * `array[4] = 500` 
  
  Then after reversing array elements should be:
  * `array[0] = 500` 
  * `array[1] = 35` 
  * `array[2] = 16` 
  * `array[3] = 5` 
  * `array[4] = 10` 

* **Note:** You can only use one array, and its size should be 7 at least. You need to take the values of array from the user. Also, you need to swap the value in a loop.

**Q4.** Write a C++ program that finds the highest value in an array of 5 elements.

**Q5.** An array records total marks (out of 100) of 10 students in a class. Write a C++ program that stores marks of 10 students in an array. Determines the top three highest marks and displays the marks of the top three students on the screen.

**Q6.** Write a C++ program that finds and prints all the multiples of 3 from an array of 10 integers.

**Q7.** (Scenario based) You are developing a small physics-based game. The player enters a gravity reversal zone, which instantly flips all vertical velocity values of nearby objects.
* Positive velocity → object moving upward
* Negative velocity → object moving downward
* Zero → object is stationary

When gravity reverses:
* Upward motion becomes downward
* Downward motion becomes upward
* Stationery remains unchanged

Your task is to write a C++ program that:
* Stores the vertical velocities of 10 objects in an integer array.
* Reverse (inverts) each velocity.
* Prints the updated velocities after gravity reversal.

* **Sample Input:** 
  ```text
  Input ten vertical velocities: 5 -3 0 7 -8 2 -1 4 -6 9
  ```
* **Sample Output:** 
  ```text
  Velocities after gravity reversals are: -5 3 0 -7 8 -2 1 -4 6 -9
  ```

**Q8.** (Debugging a Partially Correct Program) The program below should read the marks of 5 students into an array, calculate the average, and count how many students scored above the average. It compiles without any errors, but its output is wrong.

```cpp
#include <iostream>
using namespace std;
 
int main() {
    int marks[5];
    int sum;
    float average;
    int countAbove = 0;
 
    cout << "Enter marks of 5 students: ";
    for (int i = 0; i < 5; i++) {
        cin >> marks[i];
    }
 
    for (int i = 0; i < 5; i++) {
        sum = marks[i];
    }
 
    average = sum / 5;
 
    for (int i = 0; i < 5; i++) {
        if (marks[i] > average)
            countAbove++;
    }
 
    cout << "Average: " << average << endl;
    cout << "Students above average: " << countAbove << endl;
    return 0;
}
```

* **Sample Input:**
  ```text
  Enter marks of 5 students: 70 85 90 60 78
  ```
* **Expected Output:**
  ```text
  Average: 76.6
  Students above average: 3
  ```
* **Your task:**
  1. Run the program with the sample input and write down the output you actually get.
  2. Find the three logical errors. For each one, write the incorrect line, what is wrong with it, and how it affects the output.
  3. Correct the program and run it again to confirm that it gives the expected output.
  4. *Hint:* The loops that read and compare the marks are correct. Look closely at how sum and average are calculated.

**Q9.** (Correcting Boundary Errors) The program below should read 8 integers into an array, find the smallest value, and print the array in reverse order. It contains five boundary errors: some loops go one step past the last index or stop one step early, and one variable starts from the wrong value.

```cpp
#include <iostream>
using namespace std;
 
int main() {
    int nums[8];
 
    cout << "Enter 8 numbers: ";
    for (int i = 0; i <= 8; i++) {
        cin >> nums[i];
    }
 
    int smallest = 0;
    for (int i = 1; i <= 8; i++) {
        if (nums[i] < smallest)
            smallest = nums[i];
    }
    cout << "Smallest value: " << smallest << endl;
 
    cout << "Numbers in reverse order: ";
    for (int i = 8; i > 0; i--) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
```

* **Sample Input:**
  ```text
  Enter 8 numbers: 12 45 7 23 56 9 31 18
  ```
* **Expected Output:**
  ```text
  Smallest value: 7
  Numbers in reverse order: 18 31 9 56 23 7 45 12
  ```
* **Your task:**
  1. The valid indexes of nums are 0 to 7. Mark every loop condition and starting value that goes outside this range.
  2. Explain why reading or printing nums[8] is an error even if the program does not crash.
  3. Explain why starting smallest at 0 gives a wrong answer when all the numbers are positive, and state what it should start from instead.
  4. Correct all five errors. Test your program with the sample input, then with: `-3 -8 -1 -15 -6 -2 -9 -4` (the smallest value should be -15).

**Q10.** (Testing with Multiple Inputs) Write a C++ program that stores 10 integers in an array and displays:
* the number of positive values
* the number of negative values
* the number of zeros
* the largest value in the array

* **Sample Input:**
  ```text
  Enter 10 numbers: 4 -2 0 7 -9 3 0 11 -5 6
  ```
* **Sample Output:**
  ```text
  Positive: 5  Negative: 3  Zero: 2  Largest: 11
  ```

A program that works for one input can still fail for another. Test your program with every input in the table below. First work out the expected output by hand, then run your program and record the actual output. If any test fails, fix the program and run all the tests again.

| Test # | Input (10 numbers) | What it checks | Expected Output | Actual Output | Pass / Fail |
| :---: | :--- | :--- | :--- | :--- | :---: |
| 1 | 4 -2 0 7 -9 3 0 11 -5 6 | Mixed values (sample) | Pos: 5, Neg: 3, Zero: 2, Largest: 11 | | |
| 2 | -8 -3 -15 -1 -20 -7 -4 -11 -2 -9 | All negative | | | |
| 3 | 0 0 0 0 0 0 0 0 0 0 | All zeros | | | |
| 4 | 1 2 3 4 5 6 7 8 9 10 | Largest at the last index | | | |
| 5 | 50 50 12 -3 50 0 7 -3 12 1 | Largest at index 0, repeated values | | | |

* **Answer:** Which test would fail if largest started at 0 instead of the first element of the array? Explain why.

---
*Great Job, Rest Time* 😊
