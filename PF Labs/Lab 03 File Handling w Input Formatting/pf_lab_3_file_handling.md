# WEEK 3: File Handling with Mixed Data Formats (Separators, Names & Bad Data)

***

> **Note:** This lab includes a total of 8 questions.  
> **Note:** Create every input file using Notepad and save it in the same folder as your `.cpp` file. Copy the contents exactly as given, including every comma, slash, colon and space. In this lab the format of the file is the whole point, so one missing comma changes the result.  
> **Note:** Every program must follow the 4 steps from Lab 2 (**Open $\rightarrow$ Check $\rightarrow$ Read/Write $\rightarrow$ Close**) and must print a clear message if an input file cannot be opened.

---

## Objectives

* Apply the main rule of this lab: `>>` skips spaces, tabs and new lines, then reads only as long as the characters fit the variable’s type.
* Read values separated by commas, slashes, colons or operators, by reading the separator into a `char` or skipping it with `ignore()`.
* Read decimal values into `double` variables, and records that mix numbers, letters and words into parallel arrays.
* Read full names that contain spaces with `getline(name, size, ',')`, and use `ignore(100, '\n')` to skip the rest of a line or a header line.
* Handle files with a count on the first line, a sentinel value at the end, or junk mixed with numbers, using `clear()` and `eof()`.
* Open a file using a path typed by the user, and combine reading, writing and appending (`ios::app`) in one program.

---

## Tasks

### Q1. (Comma-separated Decimals)
A weather station saves one week of rainfall readings (in mm) as a single line in `rainfall.txt`, separated by commas. The file holds at most 31 readings, but you do not know how many in advance.

Write a C++ program that reads all the readings into a `double` array, displays the number of days, the readings, the total and the average, and writes every rainy day (more than 0 mm) to `rainy_days.txt`.

#### Contents of `rainfall.txt`:
```text
12.5,0,7.25,30,4.75,0,18.5
```

#### Sample Output:
```text
Days recorded: 7
Readings: 12.5 0 7.25 30 4.75 0 18.5
Total rainfall: 73 mm
Average: 10.4286 mm
```

#### Contents of `rainy_days.txt`:
```text
Day 1: 12.5 mm
Day 3: 7.25 mm
Day 4: 30 mm
Day 5: 4.75 mm
Day 7: 18.5 mm
```

#### Your task:
1. Write the program, reading each comma into a `char` variable: `inFile >> comma;`
2. Replace that line with `inFile.ignore(1, ',');` and confirm you get the same output.
3. Now put a space before every comma (`12.5 ,0 ,7.25 ...`) and run both versions. Which one still works, and why?

> **Hint:** `inFile >> comma;` first skips spaces and then reads one character, but `inFile.ignore(1, ',');` throws away exactly one character, whatever it is.

---

### Q2. (Scenario based: Dates and Times)
An office records an employee’s attendance in `attendance.txt`. Each line holds the date, the check-in time and the check-out time.

#### Contents of `attendance.txt`:
```text
06/10/2026 08:55 17:00
07/10/2026 09:20 17:30
08/10/2026 09:00 16:15
09/10/2026 09:45 18:00
10/10/2026 08:40 17:10
```

Write a C++ program that displays each date with the time worked in hours and minutes, adds `(LATE)` if the employee checked in after 09:00, and finally displays the total time worked and the number of late days. Read the slashes into a `char` variable, and skip the colons with `inFile.ignore(1, ':');`.

#### Sample Output:
```text
6/10/2026  worked 8 h 5 min
7/10/2026  worked 8 h 10 min  (LATE)
8/10/2026  worked 7 h 15 min
9/10/2026  worked 8 h 15 min  (LATE)
10/10/2026  worked 8 h 30 min
Total worked: 40 h 15 min
Days late: 2
```

> **Hint:** Turn every time into minutes: `09:20` becomes $9 \times 60 + 20 = 560$. $\text{Minutes worked} = \text{check-out} - \text{check-in}$, and $490\text{ minutes}$ is $490 / 60 = 8\text{ h}$ and $490 \pmod{60} = 10\text{ min}$. Notice that `06` is read as `6`: leading zeros are lost.

---

### Q3. (Scenario based: Expressions)
A student’s mental maths quiz is saved in `quiz.txt`. Each line holds a question and the student’s answer in the form `number operator number = answer`. Some lines were typed without spaces.

#### Contents of `quiz.txt`:
```text
12 + 7 = 19
20 * 3 = 60
15 - 4 = 12
18 / 6 = 3
8+5=13
45 / 0 = 0
9 * 8 = 63
7 - 10 = -3
```

Write a C++ program that reads each line as `int`, `char`, `int`, `char`, `int`, displays `Correct`, `Wrong` or `Invalid question (division by zero)` for each line, and displays the score out of the valid questions. Write every wrong question with its correct answer to `corrections.txt`.

#### Sample Output:
```text
Q1: 12 + 7 = 19  Correct
Q2: 20 * 3 = 60  Correct
Q3: 15 - 4 = 12  Wrong
Q4: 18 / 6 = 3  Correct
Q5: 8 + 5 = 13  Correct
Q6: 45 / 0 = 0  Invalid question
Q7: 9 * 8 = 63  Wrong
Q8: 7 - 10 = -3  Correct
Score: 5 / 7
```

#### Contents of `corrections.txt`:
```text
15 - 4 = 11 (you wrote 12)
9 * 8 = 72 (you wrote 63)
```

> **Hint:** The `=` sign is just another separator: read it into a `char`. Use `switch (op)` to work out the correct answer.

---

### Q4. (Header Line and Number, Letter, Number)
A class result sheet is saved in `results.txt`. The first line is a header, and each line after it holds a roll number, a grade and marks. Some lines were typed without spaces. The class has at most 30 students.

#### Contents of `results.txt`:
```text
Roll Grade Marks
101 A 85
102 B 72
103 A 91
104C58
105 B 77
106 F 32
107A88
```

Write a C++ program that skips the header, reads the records into three parallel arrays, displays them as a table with the count of each grade and the topper, and writes the roll number and marks of every A student to `gradeA.txt`.

#### Sample Output:
```text
Roll  Grade  Marks
101    A      85
102    B      72
103    A      91
104    C      58
105    B      77
106    F      32
107    A      88
Students: 7
A: 3  B: 2  C: 1  F: 1
Topper: Roll 103 (91)
```

#### Contents of `gradeA.txt`:
```text
101 85
103 91
107 88
```

* **Follow-up:** Remove the line that skips the header and run it again. Why is no record read?

> **Hint:** Skip the header with `inFile.ignore(100, '\n');`. A line like `104C58` still works, because an `int` read stops at the first non-digit, leaving the `C` for the `char`.

---

### Q5. (Scenario based: Letters and One-word Names)
Build an MCQ checker. `key.txt` holds the 10 correct answers. `responses.txt` holds one line per student: a one-word name followed by 10 answers written without spaces. The number of students is not known.

#### Contents of `key.txt`:
```text
A C B D A
B B D C A
```

#### Contents of `responses.txt`:
```text
Ali ACBDABBDCA
Sara ACBDBBBDCC
Usman BCBDABADCA
Hina ACBDABBDCB
Bilal DCADCBAACB
```

Write a C++ program that reads the key into `char key[10]`, then checks every student, displays each score, writes the name and score to `scores.txt`, and displays how many passed (5 or more) and the topper’s name.

#### Sample Output:
```text
Ali: 10/10
Sara: 8/10
Usman: 8/10
Hina: 9/10
Bilal: 4/10
Passed: 4  Failed: 1
Topper: Ali (10/10)
```

#### Contents of `scores.txt`:
```text
Ali 10
Sara 8
Usman 8
Hina 9
Bilal 4
```

> **Hint:** `>>` into a `char` skips spaces and new lines, so the layout of `key.txt` does not matter. `inFile >> name` reads one word. Copy the topper’s name with `strcpy(topName, name);` (`#include <cstring>`).

---

### Q6. (Complete the Missing Code)
In `donations.txt` the first line says how many donors there are. Each line after it holds a full name and an amount, separated by a comma. Five parts of the program below are missing.

#### Contents of `donations.txt`:
```text
5
Ali Khan,5000
Sara Ahmed,12000
Usman Tariq,2500
Hina Malik,15000
Bilal Raza,8000
```

```cpp
#include <iostream>
#include <fstream>
_______(1)_______
using namespace std;
 
int main() {
    ifstream inFile("donations.txt");
    if (!inFile) {
        cout << "donations.txt not found!" << endl;
        return 1;
    }
 
    int n;
    inFile >> n;                                // count on the first line
    _______(2)_______;                          // skip the rest of line 1
 
    char name[30], topName[30];
    int amount, total = 0, best = -1;
 
    for (int i = 0; i < n; i++) {
        inFile.getline(name, 30, _______(3)_______);   // full name
        inFile >> amount;
        _______(4)_______;                      // skip the new line
        cout << "[" << name << "] gave " << amount << endl;
        total = total + amount;
        if (amount > best) {
            best = amount;
            _______(5)_______;                  // remember the name
        }
    }
    inFile.close();
 
    cout << "Donors: " << n << endl;
    cout << "Total collected: " << total << endl;
    cout << "Top donor: " << topName << " (" << best << ")" << endl;
    return 0;
}
```

#### Expected Output:
```text
[Ali Khan] gave 5000
[Sara Ahmed] gave 12000
[Usman Tariq] gave 2500
[Hina Malik] gave 15000
[Bilal Raza] gave 8000
Donors: 5
Total collected: 42500
Top donor: Hina Malik (15000)
```

#### Your task:
1. Fill in blanks (1) to (5), run the program, and confirm the expected output.
2. Delete blank (2) and run it again. What changes in the first line of output, and why?

> **Hint:** After `inFile >> n;` the new line at the end of line 1 is still waiting, and `getline(name, 30, ',')` reads everything up to the comma, new line included.

---

### Q7. (Debugging: Sentinel Value and Junk Data)
A sensor writes readings to `sensor.txt`. Sometimes it writes junk words, and `-1` marks the end of the useful data. The program below should skip and count the junk, stop at `-1`, write the valid readings to `clean.txt` (one per line) and display the average with decimals. It contains five bugs.

#### Contents of `sensor.txt`:
```text
23 25 err 27
x9 26 -1 30 31
```

```cpp
#include <iostream>
using namespace std;
 
int main() {
    ifstream inFile("sensor.txt");
    if (inFile) {
        cout << "sensor.txt not found!" << endl;
        return 1;
    }
 
    int count = 0, bad = 0, x;
    int total = 0;
    char junk[50];
    ofstream outFile("clean.txt");
 
    while (count < 20) {
        if (inFile >> x) {                 // a number
            if (x == -1)                   // sentinel: stop
                break;
            outFile << x << endl;
            total = total + x;
        }
        else if (inFile.eof())             // end of the file
            break;
        else {                             // junk
            inFile >> junk;
            bad++;
        }
    }
    inFile.close();
    outFile.close();
 
    cout << "Valid readings: " << count << endl;
    cout << "Skipped: " << bad << endl;
    cout << "Average: " << total / count << endl;
    return 0;
}
```

#### Expected Output:
```text
Valid readings: 4
Skipped: 2
Average: 25.25
```

#### Contents of `clean.txt` (expected):
```text
23
25
27
26
```

#### Your task:
1. Find all five bugs. For each one, write the incorrect (or missing) line and your correction.
2. Correct the program, run it, and confirm the expected output and `clean.txt`.

> **Hint:** If the program never finishes, press `Ctrl + C`. A failed read stays failed until `inFile.clear();` is called. Also check: does `count` ever change, and what does `int / int` give?

---

### Q8. (Scenario based: Grocery Bill)
A shop saves every order as a text file: the date on line 1, a header on line 2, then one item per line (name, quantity, price). Item names may contain spaces.

#### Contents of `order1.txt`:
```text
14/10/2026
Item,Qty,Price
Basmati Rice,2,350.50
Cooking Oil,1,560
Sugar,3,145
Green Tea Box,2,300
```

Write a C++ program that:
1. Asks for the path of the order file, reads it with `cin.getline(path, 100);`, and checks it with `is_open()`.
2. Reads the date, skips the header, and reads all the items (at most 20).
3. Writes the bill to `bill.txt`. Give a 10% discount if the subtotal is more than 2000.
4. Adds the date and total to the end of `daily_sales.txt` (`ios::app`).

#### Sample Run:
```text
Enter the path of the order file: order1.txt
Items: 4
Total to pay: 2066.4
Bill saved to bill.txt
```

#### Contents of `bill.txt`:
```text
Bill for 14/10/2026
Basmati Rice x 2 = 701
Cooking Oil x 1 = 560
Sugar x 3 = 435
Green Tea Box x 2 = 600
Subtotal: 2296
Discount: 229.6
Total: 2066.4
```

Now save `order2.txt` in a new folder named `my orders`, and run the program again, typing `my orders/order2.txt`. `daily_sales.txt` should now contain two lines. Finally, type a wrong file name and check that your error message appears.

#### Contents of `order2.txt`:
```text
15/10/2026
Item,Qty,Price
Milk Pack,4,280
Brown Bread,2,190.5
```

#### Contents of `daily_sales.txt` (after both runs):
```text
14/10/2026 2066.4
15/10/2026 1501
```

> **Hint:** Call `inFile.ignore(100, '\n');` twice after reading the date: once for the rest of line 1 and once for the header.  
> **Reading loop:** `while (items < 20 && inFile.getline(item, 30, ',') && inFile >> qty >> comma >> price)` with `inFile.ignore(100, '\n');` inside.  
> *Why must the path be read with `getline` and not with `cin >>`?*

---

<div align="center">

**Great Job, Rest Time😊**

</div>