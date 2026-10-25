# WEEK 4: More File Handling Practice & Introduction to Functions

---

> **Notes:**
> - This lab includes a total of 6 questions. **Q1 – Q3** practise file handling and **Q4 – Q6** practise writing functions.
> - Every question names the lecture slides it is based on. File questions refer to *"File Handling in C++ – Part 2"* and function questions refer to *"Functions in C++ – Lecture 1"*. Open that slide and read it before you start the question.
> - Create every input file using Notepad and save it in the same folder as your `.cpp` file. Copy the contents exactly as given. Every file program must follow the 4 steps (**Open → Check → Read/Write → Close**) and must print a clear message if an input file cannot be opened.
> - Write every function above `main()`. Moving a function below `main()` gives an error that we will learn to fix in the next lecture.

---

## Objectives

1. Find out why a reading loop stopped (array full, end of file, empty file or bad data) using `eof()` and `fail()` checked in the right order.
2. Skip junk one character at a time with `clear()` and `ignore()`, so that numbers stuck to junk are not lost.
3. Read values separated by semicolons, and read the same file a second time with `clear()` and `seekg(0)`, or by closing and reopening it.
4. Write `void` functions with and without parameters, and call them from `main()` and from other functions.
5. Design value-returning functions that return `int`, `double`, `char` and `bool` by answering three questions: *what job does it do, what does it need, and what does it give back?*
6. Use predefined functions from `<cmath>` inside your own functions, and trace how variables are created and destroyed during a function call.

---

## Tasks

### Q1. (Why Did the Loop Stop?)

A teacher’s marks files are not always clean: some are empty, some have typing mistakes, and some hold more marks than the program expects. Write a C++ program that asks for a file name, reads at most 5 marks into `int marks[5]`, and then reports why the reading loop stopped.

> **Slide reference:** File Handling Part 2, slide 30 (*Why did the loop stop?*) and slide 31 (*Empty file, or junk at the start?*).

Create these five files. For `test2.txt`, open Notepad and save the file without typing anything in it.

* **Contents of `test1.txt`:**
  ```text
  45 67 89
  ```
* **Contents of `test2.txt`:**
  ```text
  (empty: nothing typed)
  ```
* **Contents of `test3.txt`:**
  ```text
  56 72 abc 90
  ```
* **Contents of `test4.txt`:**
  ```text
  10 20 30 40 50 60 70
  ```
* **Contents of `test5.txt`:**
  ```text
  xyz 40 50
  ```

The program displays how many numbers were read and, if at least one was read, the values and their average. Then it displays one of these reasons:
* `Array is full (the file has more data)`
* `End of file (normal)`
* `The file is empty!`
* `Bad data found after N numbers`

Finally, it adds the file name and the result to the end of `check_log.txt` (`ios::app`).

#### Sample Runs:
```text
Enter file name: test1.txt
Numbers read: 3
Values: 45 67 89
Average: 67
Reason: End of file (normal)
```
```text
Enter file name: test2.txt
Numbers read: 0
Reason: The file is empty!
```
```text
Enter file name: test3.txt
Numbers read: 2
Values: 56 72
Average: 64
Reason: Bad data found after 2 numbers
```
```text
Enter file name: test4.txt
Numbers read: 5
Values: 10 20 30 40 50
Average: 30
Reason: Array is full (the file has more data)
```
```text
Enter file name: test5.txt
Numbers read: 0
Reason: Bad data found after 0 numbers
```

#### Contents of `check_log.txt` (after the five runs):
```text
test1.txt normal
test2.txt empty
test3.txt bad data after 2
test4.txt full
test5.txt bad data after 0
```

#### Your task:
1. Write the program and run it once for each file. Then type a file name that does not exist and check that your error message appears.
2. Swap the order of the `eof()` and `fail()` checks and run `test1.txt` again. Which reason is displayed now, and why is it wrong?
3. In `test3.txt` the `90` after `abc` is never read. Explain why in one sentence.

> **Hint:** Read the name with `char fileName[50]; cin >> fileName;`. Check in this order: `if (count == 5 && inFile)`, then `else if (inFile.eof())`, then `else if (inFile.fail())`. Reaching the end of the file also sets fail, so `fail()` alone cannot tell “finished” from “bad data”. `count == 0` alone cannot tell an empty file from junk at the start, but `eof()` can.

---

### Q2. (Scenario based: Skip Junk One Character at a Time)

A smart electricity meter saves one reading per day in `meter.txt`. The readings always go up. Because of a loose connection, junk characters sometimes get stuck to the numbers.

> **Slide reference:** File Handling Part 2, slide 32 (*Skip bad data and keep going*), slide 34 (*Why the skip loop can break*) and slide 35 (*Skip one character at a time*).

* **Contents of `meter.txt`:**
  ```text
  120 kw135 140 x
  155abc 160 ##170
  ```

Write a C++ program that reads the readings into an `int` array (at most 20), skips junk one character at a time with `inFile.clear();` and `inFile.ignore();`, and counts the skipped characters. Display the readings kept, the number of characters skipped and the total units used ($\text{last reading} - \text{first reading}$). Write the units used each day to `usage.txt`.

#### Sample Output:
```text
Readings kept: 6
120 135 140 155 160 170
Characters skipped: 8
Total units used: 50
```

#### Contents of `usage.txt`:
```text
Day 1 -> Day 2: 15 units
Day 2 -> Day 3: 5 units
Day 3 -> Day 4: 15 units
Day 4 -> Day 5: 5 units
Day 5 -> Day 6: 10 units
```

#### Your task:
1. Write the program and confirm the output and `usage.txt`.
2. Now replace `inFile.ignore();` with the slide 32 version: `inFile >> junk;` (with `char junk[50];`). Run it again and write down the readings kept and the total units used. Which readings are lost?
3. Explain in one sentence why `ignore()` keeps the 135 in `kw135` but `inFile >> junk;` loses it.

> **Hint:** Each pass of the loop asks only three questions: a number? the end of the file? or junk? A failed read stays failed, so call `inFile.clear();` before skipping. The units used from day $i$ to day $i + 1$ are $r[i] - r[i - 1]$ in a loop that starts at $i = 1$.

---

### Q3. (Semicolons, and Reading a File Twice)

A batsman’s runs for one season are saved on one line of `innings.txt`, separated by semicolons. You must find the average first, and then list every innings above the average. In this question you may not use an array: read the file once to find the average, then go back to the start and read it again.

> **Slide reference:** File Handling Part 2, slide 5 (*Comma-separated numbers: “For ; or | write that symbol”*) and slide 36 (*Reading again after a failure*).

* **Contents of `innings.txt`:**
  ```text
  45;78;12;90;33;67;5;102
  ```

Display the number of innings, the total runs and the average, then every innings above the average. Write the innings number and runs of each of them to `good_innings.txt`.

#### Sample Output:
```text
Innings played: 8
Total runs: 432
Average: 54
Innings above average:
Innings 2: 78
Innings 4: 90
Innings 6: 67
Innings 8: 102
```

#### Contents of `good_innings.txt`:
```text
2 78
4 90
6 67
8 102
```

#### Your task:
1. Write the program, going back to the start of the file with `inFile.clear();` followed by `inFile.seekg(0);`.
2. Replace those two lines with `inFile.close();` and `inFile.open("innings.txt");`. Do you get the same output?
3. Put the `seekg` version back, delete only `inFile.clear();`, and run it again. What is missing from the output, and why?

> **Hint:** Skip each semicolon with `inFile.ignore(1, ';');` right after reading a score. After the first loop the stream has failed at the end of the file. A failed stream stays failed until `clear()` is called; `seekg(0)` only moves back to the start.

---

### Q4. (Void Functions: The Lab Printer)

Write a C++ program with the following four `void` functions, all written above `main()`.

> **Slide reference:** Functions Lecture 1, slide 11 (*Write once, call many times*), slide 15 (*Our very first function*), slide 18 (*Parameters*), slide 25 (*Void function with a parameter*) and slide 26 (*Common beginner mistakes*).

* `void printWelcome()` takes no parameters and prints `Welcome to the Lab 4 Printer`.
* `void printLine(char symbol, int length)` prints `symbol` `length` times, then moves to a new line.
* `void printTable(int n)` prints the multiplication table of `n`, from $n \times 1$ to $n \times 10$.
* `void printTriangle(int rows)` prints a triangle of stars. It must not print stars with its own inner loop: for $i = 1$ to `rows` it calls `printLine('*', i);`.

`main()` prints a banner using `printLine('=', 30);` and `printWelcome();`, reads a number and calls `printTable`, prints a dashed line, then reads the number of rows, calls `printTriangle` and prints a closing line.

#### Sample Run:
```text
==============================
Welcome to the Lab 4 Printer
==============================
Enter a number for its table: 7
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
------------------------------
Enter the number of rows: 4
*
**
***
****
==============================
```

#### Your task:
1. Write the program and confirm the sample run (all 10 rows of the table must appear).
2. Make each of these mistakes from slide 26 one at a time, compile, and write down what happens:
   * (a) `cout << printLine('-', 10);`
   * (b) `printWelcome;` without the brackets
   * (c) a semicolon after the header: `void printWelcome(); { ... }`
3. Call `printTriangle(0);` from `main()`. What is printed, and why?

> **Hint:** A `void` function gives nothing back, so it is called on its own line as a statement: `printLine('=', 30);`. There is nothing for `cout` to print. `printTriangle` is a function calling another function: just like `main()`, any function can call a helper.

---

### Q5. (Value-returning Functions: int, bool, double and char)

Before writing any code, copy this table into your notebook and complete it by answering the three design questions for each function.

> **Slide reference:** Functions Lecture 1, slide 16 (*The four parts of every function*), slide 17 (*Return type*), slide 19 (*Value in, answer out*), slide 20 (*Design any function with 3 questions*) and slide 24 (*Value-returning function*).

| What job does it do? | Name | What does it need? | What does it give back? | Header |
| :--- | :--- | :--- | :--- | :--- |
| Find the largest of three whole numbers | `largest` | | | |
| Check if a year is a leap year | `isLeapYear` | | | |
| Convert Celsius to Fahrenheit | `toFahrenheit` | | | |
| Turn marks into a letter grade | `letterGrade` | | | |

Then write the four functions and a `main()` that reads values from the user and uses each answer. **Rules:**
* `letterGrade`: **A** for 80 and above, **B** for 70 – 79, **C** for 60 – 69, **D** for 50 – 59, and **F** below 50.
* `isLeapYear`: a year is a leap year if it is divisible by 4 but not by 100, or if it is divisible by 400.
* `toFahrenheit`: $F = C \times \frac{9}{5} + 32$.
* `main()` must use a returned value in all three ways from slide 24: store it (`int big = largest(a, b, c);`), test it in a condition (`if (isLeapYear(year))`) and print it directly (`cout << letterGrade(marks);`).

#### Sample Run:
```text
Enter three numbers: 14 52 37
Largest: 52
Enter a year: 2024
2024 is a leap year
Enter temperature in Celsius: 36.6
36.6 C = 97.88 F
Enter marks: 73
Grade: B
```

#### Your task:
1. Complete the design table, write the program and confirm the sample run.
2. Test `isLeapYear` with 1900, 2000 and 2026. Which of them are leap years?
3. Change the formula to return `9 / 5 * celsius + 32;` and run it with 36.6 again. The answer becomes 68.6. Why?

> **Hint:** A `bool` function can return the condition itself: `return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;`. A `char` function returns one character in single quotes: `return 'A';`. `return` also ends the function at once, so after a grade is returned the rest of the if-else chain does not run.

---

### Q6. (Predefined Functions inside Your Own Functions, and Tracing Memory)

A builder needs to know how long a ladder must be to reach the top of a wall, and a map app needs the straight-line distance between two points. Both are the same calculation: the longest side of a right triangle, $c = \sqrt{a^2 + b^2}$.

> **Slide reference:** Functions Lecture 1, slides 12 – 14 (*Predefined functions and the live demo*), slide 19 (*Value in, answer out*) and slides 21 – 22 (*Variables are born and destroyed*).

#### Part A: Write these functions
* `double hypotenuse(double a, double b)` returns $\sqrt{a^2 + b^2}$ using `sqrt()` and `pow()` from `<cmath>`.
* `double pointDistance(double x1, double y1, double x2, double y2)` returns the distance between two points. It must not call `sqrt()` itself: it returns `hypotenuse(x2 - x1, y2 - y1)`.

##### Sample Run 1:
```text
Enter wall height and distance from the wall: 8 6
Ladder length needed: 10
Enter point 1 (x y): 1 2
Enter point 2 (x y): 4 6
Distance: 5
```

##### Sample Run 2:
```text
Enter wall height and distance from the wall: 5 12
Ladder length needed: 13
Enter point 1 (x y): -2 3
Enter point 2 (x y): 1 -1
Distance: 5
```

#### Part B: Trace this program without running it

```cpp
1   int cube(int n) {
2       int result = n * n * n;
3       return result;
4   }
5
6   int main() {
7       int a = 3;
8       int b = cube(a);
9       int c = cube(b - 25);
10      cout << b << " " << c;
11      return 0;
12  }
```

Copy this table into your notebook and complete it in the style of slide 22. The first row is done for you.

| Line | What happens | Memory now |
| :--- | :--- | :--- |
| 6 – 7 | main starts; a created = 3 | main: a=3 |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |

#### Your task:
1. Write Part A and confirm both sample runs.
2. Delete `#include <cmath>` and compile. Write down the error, then put the line back (slide 14).
3. In Run 2, $x_2 - x_1 = 3$ but $y_2 - y_1 = -4$. Why does the answer still come out right without using `abs()`?
4. Complete the Part B table. What does the program print? When `cube(b - 25)` is called, what value goes into `n`? Can `main()` print `result`? Why not?

> **Hint:** `pow(a, 2)` means $a^2$. The parameter is the door in and return is the door out (slide 19). Every call to `cube` creates a new `n` and a new `result`, and destroys them when it returns.

---

$$\text{Great Job, Rest Time } \smiley{}$$