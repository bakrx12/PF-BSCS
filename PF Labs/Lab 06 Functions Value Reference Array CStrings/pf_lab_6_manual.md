# WEEK 6: Functions: Value and Reference Parameters, Arrays and C-Strings as Parameters

---

> **Note:** This lab has 8 coding questions and is 2.5 hours long; a suggested time is given with each question.  
> **Note:** Use the Lecture 2 layout in every program: prototypes above `main()`, then `main()`, then the definitions below `main()`.  
> **Note:** Q2 and Q4 give no prototypes. Design every header yourself: name, parameters (value or `&`) and return type.  
> **Note:** Do not use `<string>` or `<cstring>` in Q7 and Q8. Work with the `char` array and its `'\0'` yourself.

---

### Quick Reminder: Four Ways to Pass Data

| Parameter | Example header | What the function gets |
| :--- | :--- | :--- |
| **Value** | `int square(int n)` | A copy. Changes stay inside the function. |
| **Reference** | `void reset(int &n)` | The original. Changes reach `main()`. |
| **Integer array** | `void fill(int arr[], int size)` | The original array (no `&` needed). Always pass its size too. |
| **C-string** | `int length(char s[])` | The original `char` array. No size needed: stop at `'\0'`. |

---

## Objectives
* Write value-returning functions that take value parameters and call each other.
* Use reference parameters to change `main()`'s variables and to send back more than one answer.
* Design complete function headers from a problem statement without given prototypes.
* Pass integer arrays to functions together with their size or occupied count.
* Process null-terminated `char` arrays (C-strings) inside functions using `'\0'`.

---

## Tasks

### Part A: Pass by Value

#### Q1. (Day of the Year) [Medium]
Read a date (day, month, year). If it is not a real date, print `Invalid date`. Otherwise print its day number in the year and how many days are left in that year.

* **Slide reference:** Functions Lecture 1, slide 17 (Return type); Functions Lecture 2, slide 9 (Program layout) and slide 13 (Three ways to call a function).
* **Prototypes:**
  ```cpp
  bool isLeap(int year);
  int  daysInMonth(int month, int year);
  bool isValidDate(int day, int month, int year);
  int  dayOfYear(int day, int month, int year);
  ```
* **Rules:** No arrays. `dayOfYear` must loop over the months and call `daysInMonth`; `isValidDate` must also use `daysInMonth`.

**Sample Runs:**
```text
Enter date (d m y): 1 3 2024
Day number: 61
Days left in 2024: 305
```
```text
Enter date (d m y): 29 2 2023
Invalid date.
```
```text
Enter date (d m y): 31 12 2023
Day number: 365
Days left in 2023: 0
```

> **Hint:** A year is leap if it is divisible by $400$, or divisible by $4$ but not by $100$.

---

#### Q2. (Base Converter) [Hard]
Read a number, its base and a new base (all bases from 2 to 10). Convert the number to the new base and print it. If a digit is not allowed in the given base, print `Invalid digit for base b`. Repeat until the number entered is 0.

* **Slide reference:** Functions Lecture 1, slide 20 (Design any function with 3 questions); Functions Lecture 2, slides 14–16 (Dry run, formal vs actual parameters, matching rule).
* **Rules:** No prototypes are given. Write at least three value-returning functions, all with value parameters only. `main()` must not contain any digit-processing loop: it only reads, calls and prints. All values fit in an `int`.

**Sample Run:**
```text
Enter number, its base, new base (0 to stop): 1011 2 8
1011 (base 2) = 13 (base 8)
Enter number, its base, new base (0 to stop): 255 10 2
255 (base 10) = 11111111 (base 2)
Enter number, its base, new base (0 to stop): 128 2 5
Invalid digit for base 2.
Enter number, its base, new base (0 to stop): 144 5 10
144 (base 5) = 49 (base 10)
Enter number, its base, new base (0 to stop): 0
Goodbye.
```

> **Hint:** Go through the decimal value: first convert from the old base to decimal, then from decimal to the new base. Build the answer as an `int` whose digits are the new-base digits.

---

### Part B: Pass by Reference

#### Q3. (Clock Forward) [Medium]
Read a time (hours 0–23, minutes, seconds) and a number of seconds to add. Move the clock forward, print the new time as `HH:MM:SS`, and print how many midnights were crossed.

* **Slide reference:** Functions Lecture 2, slides 20–22 (Reference parameter) and slide 25 (More than one answer).
* **Prototypes:**
  ```cpp
  void readTime(int &h, int &m, int &s);
  int  addSeconds(int &h, int &m, int &s, int extra); // midnights crossed
  void printTime(int h, int m, int s);                // prints HH:MM:SS
  ```

**Sample Runs:**
```text
Enter time (h m s): 23 59 50
Seconds to add: 25
New time: 00:00:15
Midnights crossed: 1
```
```text
Enter time (h m s): 10 15 0
Seconds to add: 100000
New time: 14:01:40
Midnights crossed: 1
```

> **Hint:** Turn the time into total seconds, add extra, then split it back. One day has $86400$ seconds. For leading zeros use `setw(2)` and `setfill('0')` from `<iomanip>`.

---

#### Q4. (Fraction Calculator) [Hard]
Read an expression of two fractions and one operator (`+`, `-`, `*`, `/`), for example `3/4 + 5/6`. Print the result in lowest terms with a positive denominator. If the result is a whole number, print only the number; if it is improper, also print it as a mixed number. Dividing by a zero fraction prints `Cannot divide by zero.`

* **Slide reference:** Functions Lecture 2, slide 23 (Value vs reference), slide 24 (Swapping) and slide 25 (More than one answer).
* **Rules:** No prototypes are given. You must have:
  1. A function that reduces a fraction in place using reference parameters.
  2. A `calculate` function that sends back the result's numerator and denominator through reference parameters and returns whether the operation was possible. Denominators entered are never 0.

**Sample Runs:**
```text
Enter expression: 3/4 + 5/6
Result: 19/12 = 1 7/12
```
```text
Enter expression: 1/3 - 8/3
Result: -7/3 = -2 1/3
```
```text
Enter expression: 4/6 * 3/2
Result: 1
```
```text
Enter expression: 1/2 / 0/5
Cannot divide by zero.
```

> **Hint:** Read the slash into a `char`: `cin >> n1 >> slash >> d1 >> op >> n2 >> slash >> d2;` Divide numerator and denominator by their GCD (use absolute values). If the denominator is negative, flip both signs.

---

### Part C: Integer Arrays as Function Parameters

#### Q5. (Weekly Temperatures) [Easy]
Read 7 daily temperatures into an array. Print the average (2 decimal places), how many days were above the average, and which days they were.

* **Prototypes:**
  ```cpp
  void   readArray(int arr[], int size);
  double average(int arr[], int size);
  int    countAbove(int arr[], int size, double limit);
  void   printAbove(int arr[], int size, double limit);
  ```

**Sample Run:**
```text
Enter 7 temperatures: 31 34 29 36 33 30 39
Average: 33.14
Days above average: 3
Hot days: Day 2 (34) Day 4 (36) Day 7 (39)
```

---

#### Q6. (Reverse and Search) [Easy]
An array can hold up to 20 values. Read values until `-1` (or until it is full), print them, reverse the array, print it again, then search for a value.

* **Prototypes:**
  ```cpp
  int  readList(int arr[], int capacity);      // returns how many were stored
  void printList(int arr[], int used);
  void reverseList(int arr[], int used);
  int  findValue(int arr[], int used, int key); // index, or -1 if not found
  ```

**Sample Runs:**
```text
Enter values (-1 to stop): 4 8 15 16 23 42 -1
Stored 6 values: 4 8 15 16 23 42
Reversed: 42 23 16 15 8 4
Search for: 15
15 found at index 3.
```
```text
Enter values (-1 to stop): 7 3 9 -1
Stored 3 values: 7 3 9
Reversed: 9 3 7
Search for: 5
5 not found.
```

> **Hint:** `reverseList` has no `&`, yet `main()`'s array changes. Write one comment in your code explaining why.

---

### Part D: C-Strings (Null-Terminated char Arrays)

#### Q7. (Sentence Stats) [Easy]
Read a sentence (up to 99 characters) with `cin.getline`. Print its length, its number of vowels, and the sentence in upper case.

* **Prototypes:**
  ```cpp
  int  strLength(char s[]);
  int  countVowels(char s[]);    // a e i o u, small or capital
  void toUpperCase(char s[]);    // changes the sentence itself
  ```

**Sample Run:**
```text
Enter a sentence: Programming is fun
Length: 18
Vowels: 5
Upper case: PROGRAMMING IS FUN
```

> **Hint:** Loop until `s[i] == '\0'`. A small letter becomes capital by subtracting $32$ (`'a' - 'A' = 32`).

---

#### Q8. (Title Case and Slug) [Easy] *(Suggested time: 15 minutes)*
Read a sentence of small letters with single spaces between words. Print the number of words, the sentence with every word capitalized, and its slug (spaces replaced by dashes).

* **Prototypes:**
  ```cpp
  int  countWords(char s[]);
  void capitalizeWords(char s[]);
  void replaceChar(char s[], char from, char to);
  ```

**Sample Run:**
```text
Enter a sentence: lahore is the city of gardens
Words: 6
Capitalized: Lahore Is The City Of Gardens
Slug: Lahore-Is-The-City-Of-Gardens
```

> **Hint:** A letter starts a word if it is at index 0 or the character before it is a space.