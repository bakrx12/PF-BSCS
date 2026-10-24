# Programming Fundamentals
## Assignment 2 — File Handling

**Total Marks:** 30  
**CLO:** CLO-2  
**Due:** Thursday, 29th October 2026 | **Time:** 11:55 PM  

---

## Scenario
In Labs 2 and 3 you learned how a program can save data to a file and read it back, and how to read files that contain commas, dates, times, names, junk words and header lines. In this assignment you will write and fix five C++ programs that work with files exactly like the ones used by real shops, offices and devices, and you will submit them through GitHub as you did in Assignment 1.

All examples use the sample registration number `L1F24BSCS0081`; replace it with your own.

---

## Before You Start 
1. Use the same GitHub account you created in Assignment 1 (username = your registration number). Work in an Incognito / Private window on lab computers.
2. Download `Assignment02_Sample_Files.zip` from the course portal and extract it. It contains the dummy input files for every question and the starter code for Q1 and Q4.
3. Keep every `.txt` file in the same folder as your `.cpp` file. In Dev-C++ this is the folder where the `.cpp` is saved; in Visual Studio it is the project folder (the folder that contains the `.vcxproj` file).
4. If you create a `.txt` file yourself in Notepad, choose **Save as type: All Files** and type the name exactly (for example `parking.txt`). Otherwise Windows may save it as `parking.txt.txt`. Turn on **File Explorer → View → Show → File name extensions** to see the real name.
5. All data in this document is dummy data. Your programs will also be checked with other files in the same format: different values, more or fewer lines, a missing file and an empty file. A program that only works for the sample data, or that prints fixed answers, will lose marks.
6. **Using Visual Studio?** If it stops with error `C4996` when you use `strcpy`, add the line `#define _CRT_SECURE_NO_WARNINGS` after the header comment block and before the `#include` lines. This line is allowed and does not lose marks.
7. **Deadline:** Thursday, 29 October 2026 at 11:55 PM (Pakistan time). Your GitHub commits and your PDF on the portal must both be in before this time. Start early: anything committed after 11:55 PM is not marked.

---

## General Rules for All Programs (Read Carefully)
These rules apply to every question. Marks are lost when a rule is not followed, so check each one before you submit.

- **File names must be exactly as given** (capital and small letters included). A `.cpp` file with a different name is treated as not submitted.
- **Every `.cpp` file must start with this header comment block**, filled in with your own details:
```cpp
/*
 * Name       : Student Name
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */
```
- **Your output must match the sample output word for word:** the same spelling, capital letters, punctuation, spaces between words and order of lines. Extra spaces at the end of a line and empty lines are not counted.
- **Print nothing extra.** No welcome messages, no "Press any key", and do not use `system("pause")`, `getch()` or `<conio.h>`. Your program must end on its own.
- **In your code, open files by name only**, for example `ifstream inFile("parking.txt");`. You may keep your project anywhere on your computer, but do not write a path such as `"C:/Users/Ali/Desktop/parking.txt"` in the code: the file will not be found when your program is checked and every test of that question will fail and you will receive zero. (Q3 is different: there the user types the file name or path while the program runs.)
- **Print decimal numbers with plain `cout`.** Do not use `setprecision` or `fixed`. This means 3.50 is printed as 3.5 and 7507.470 as 7507.47, exactly as shown in the samples.
- **Use only these header files:** `<iostream>`, `<fstream>` and `<cstring>`.
- **Your program must compile without errors.** A program that does not compile receives 0 for that question.
- **Your program must not get stuck.** If it has not finished within 2 seconds for a test file (for example because of an endless loop), that test receives 0.
- **Follow the 4 steps from the labs in every program:** Open → Check → Read/Write → Close.
- **When one of the error situations listed in a question happens**, display exactly the message given and end the program.

---

## Part A — GitHub [5 Marks]

### Task A1 — Create the Repository [1 Mark]
Sign in to your Assignment 1 account and create a new repository with these settings:
- **Repository name:** `Assignment02-File-Handling`
- **Description:** `File Handling`
- **Visibility:** `Public`
- **Add README:** `ON` (this creates Commit #1 automatically)

Your repository link must look like this:  
`https://github.com/L1F24BSCS0081/Assignment02-File-Handling`

- The name must be exactly `Assignment02-File-Handling`: capital A, F and H, hyphens, no spaces.
- The repository must be Public, otherwise it cannot be opened for marking.

---

### Task A2 — Upload Your Program Files [1 Mark]
Upload your five programs to the main page of the repository (not inside a folder) using **Add file → Upload files**. The repository must contain these files:

| Question | File name (must be exactly this) | Program |
| :--- | :--- | :--- |
| Q1 | `Q1_stock_debug.cpp` | Stock Report (Debugging) |
| Q2 | `Q2_parking_report.cpp` | Parking Report |
| Q3 | `Q3_scholarship.cpp` | Scholarship List |
| Q4 | `Q4_heart_rate.cpp` | Heart Rate Cleaner |
| Q5 | `Q5_expense_tracker.cpp` | Expense Tracker |
| — | `README.md` | Created automatically in Task A1, edited in Task A3 |

- Each `.cpp` file must contain the header comment block with your name and registration number.
- You do not need to upload the `.txt` files. Do not upload `.exe` files or zipped folders.

---

### Task A3 — Make Meaningful Commits [2 Marks]
Upload each question separately so that each one becomes its own commit. Your history must contain at least these 7 commits, with these messages:

| Commit | Commit message (use exactly this) | What you do |
| :---: | :--- | :--- |
| 1 | `Initial commit` | Automatic (README) |
| 2 | `Add Q1 stock debug program` | Upload `Q1_stock_debug.cpp` |
| 3 | `Add Q2 parking report program` | Upload `Q2_parking_report.cpp` |
| 4 | `Add Q3 scholarship program` | Upload `Q3_scholarship.cpp` |
| 5 | `Add Q4 heart rate program` | Upload `Q4_heart_rate.cpp` |
| 6 | `Add Q5 expense tracker program` | Upload `Q5_expense_tracker.cpp` |
| 7 | `Update README with name, reg no and question list` | Edit `README.md` (see below) |

- `README.md` (commit 7) must contain your full name, your registration number and the five `.cpp` file names listed above.
- You may make extra commits if you correct a program later, for example `Fix fee calculation in Q2`. Every commit message must describe the change; messages like "update", "asdf" or "final" lose marks.
- If you upload a newer version of a file, use the same file name so that it replaces the old one.

---

### Task A4 — Share with Instructor and Submit on Portal [1 Mark]

**Step A — Invite the instructor as a collaborator**  
- **Settings → Collaborators → Add people**
- **Instructor email:** `fareeha.iqbal@ucp.edu.pk`
- Type the email exactly as written. "Pending Invite" is fine.

**Step B — Prepare ONE PDF file named with your registration number**  
- **File name:** `L1F24BSCS0081_Assignment02.pdf`
- **Page 1:** Your repository link (`https://github.com/L1F24BSCS0081/Assignment02-File-Handling`)
- **Page 2:** Screenshot of your Commits page showing at least 7 commits
- **Page 3:** Screenshot of **Settings → Collaborators** showing the instructor invited

**Step C — Upload the PDF on the course portal before the deadline**  
- Submit only **ONE PDF file**. Do not upload `.cpp` files, images or Word files separately on the portal.
- Screenshots must be full-screen and clearly show your username and the address bar.

---

## Part B — Programming Questions [25 Marks]

---

### Q1 — Stock Report (Debugging) [4 Marks]
- **File:** `Q1_stock_debug.cpp`
- **Concepts:** `<fstream>`, Open → Check → Read/Write → Close, skipping a header line, `double` vs `int`, `ios::app`, `endl` in files

A shop keeps its stock in `stock.txt`. The first line is a header. Every line after it holds an item code (one word), the quantity and the price of one piece. The program below should:
1. Skip the header line and read every item (at most 50 items),
2. Count the items and calculate the total stock value (quantity $\times$ price for every item, added up, with decimals),
3. For every item with a quantity less than 10, add a line `code quantity` to the end of `reorder.txt` (lines already in `reorder.txt` must be kept), one item per line,
4. Display the three result lines shown in the sample output.

The program contains six bugs, and it does not even compile. The starter file `Q1_stock_debug.cpp` is in the sample files ZIP.

#### Starter code (contains 6 bugs):
```cpp
/*
 * Name       : Student Name
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */
 
#include <iostream>
using namespace std;
 
int main() {
    ifstream inFile("stock.txt");
    if (inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }
 
    ofstream reorder("reorder.txt");
 
    char code[10];
    int qty, count = 0, low = 0;
    double price;
    int total = 0;
 
    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty;
            low++;
        }
    }
    inFile.close();
    reorder.close();
 
    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
```

#### Input file: `stock.txt` (dummy data)
```text
Code Qty Price
P101 25 120.5
P102 6 80
P103 40 15.25
P104 3 999.99
P105 9 45
```

#### `reorder.txt` before running (dummy data, already contains one old line)
```text
P099 2
```

#### Your task:
Find and fix all six bugs. Do not change the messages, the variable names or the way the program works — only correct the mistakes. Directly above each line you corrected (or added), write a comment that starts with `// FIX 1:` to `// FIX 6:` and explains the bug in your own words, for example:
```cpp
// FIX 1: <fstream> was missing, so ifstream and ofstream were unknown
#include <fstream>
```

#### Error message:
| Situation | Display exactly |
| :--- | :--- |
| `stock.txt` cannot be opened | `stock.txt not found!` |

#### Sample output (screen):
```text
Items: 5
Total stock value: 7507.47
Low stock items: 3
```

#### Output file: `reorder.txt` (after one run — the old line is kept)
```text
P099 2
P102 6
P104 3
P105 9
```

> **Hint:** Compile first and read the first error. Then check: is the stream for reading an `ifstream`? Does the Check step test the right condition? What happens to 120.5 when it is added to an `int`? Does a plain `ofstream` keep the old lines? Before you test again, put `reorder.txt` back to its single original line.

---

### Q2 — Parking Report [5 Marks]
- **File:** `Q2_parking_report.cpp`
- **Concepts:** date with `/`, skipping a header line, one-word names, `char`, times with `:`, unknown number of lines, writing a file

A parking plaza saves each day's entries in `parking.txt`. Write a program that reads the file, calculates the parking fee of every vehicle, writes receipts to a file and displays a report.

#### Format of `parking.txt`:
- Line 1: the date as `dd/mm/yyyy`.
- Line 2: a header line — skip it.
- Every line after that: `Plate Type In Out`, separated by spaces. `Plate` is one word (letters and digits, at most 14 characters). `Type` is `C` (car) or `B` (bike). `In` and `Out` are 24-hour times `HH:MM` on the same day, and `Out` is never earlier than `In`.
- There are at most 30 vehicles; the exact number is not known in advance.

#### Input file: `parking.txt` (dummy data)
```text
09/10/2026
Plate Type In Out
LEA1234 C 08:15 10:45
LHR552 B 09:00 09:40
RIK77 C 09:30 13:30
LEB908 B 10:05 12:20
MNA4410 C 11:50 12:35
LHR9001 C 13:00 17:10
```

#### What your program must do:
1. Read the date and display `Parking report for d/m/yyyy`. The day and month are read as integers, so leading zeros disappear: `09/10/2026` is displayed as `9/10/2026`.
2. For every vehicle, calculate $\text{minutes parked} = \text{Out} - \text{In}$ (turn both times into minutes first).
3. Calculate $\text{hours charged} = (\text{minutes} + 59) / 60$ using integer division, so every started hour is charged. If the result is 0 (`In` and `Out` are the same), charge 1 hour.
4. $\text{Fee} = \text{hours charged} \times 100$ for a car (C) or $\times 40$ for a bike (B).
5. Display one line per vehicle: `Plate Car|Bike H h M min Fee: fee` where `H` and `M` are the actual time parked ($\text{minutes} / 60$ and $\text{minutes} \% 60$), not the hours charged.
6. After all vehicles, display the four summary lines shown in the sample. For `Longest stay`, if two vehicles have the same time, show the one that comes first in the file.
7. Write `receipts.txt`: the first line is `Receipts for d/m/yyyy`, then one line `Plate Fee` per vehicle. `receipts.txt` is created fresh (overwritten) every time the program runs.

#### Error messages:
| Situation | Display exactly |
| :--- | :--- |
| `parking.txt` cannot be opened | `parking.txt not found!` |
| The file has the date and header but no vehicle lines | First `Parking report for d/m/yyyy`, then `No vehicles found!` |

#### Sample output (screen):
```text
Parking report for 9/10/2026
LEA1234 Car 2 h 30 min Fee: 300
LHR552 Bike 0 h 40 min Fee: 40
RIK77 Car 4 h 0 min Fee: 400
LEB908 Bike 2 h 15 min Fee: 120
MNA4410 Car 0 h 45 min Fee: 100
LHR9001 Car 4 h 10 min Fee: 500
Vehicles: 6
Cars: 4 Bikes: 2
Total collected: 1460
Longest stay: LHR9001 (4 h 10 min)
```

#### Output file: `receipts.txt`
```text
Receipts for 9/10/2026
LEA1234 300
LHR552 40
RIK77 400
LEB908 120
MNA4410 100
LHR9001 500
```

> **Hint:** Read the date with `inFile >> d >> slash >> m >> slash >> y;`, then call `inFile.ignore(100, '\n');` twice: once for the rest of line 1 and once for the header. A plate is read with `>>` into a char array such as `char plate[15];`. Copy the plate with the longest stay using `strcpy`. Check your fee rule by hand: 60 minutes is 1 hour, 61 minutes is 2 hours.

---

### Q3 — Scholarship List [5 Marks]
- **File:** `Q3_scholarship.cpp`
- **Concepts:** file name typed by the user, `is_open()`, count on the first line, full names with spaces using `getline(name, size, ',')`, decimals, writing a file

The department keeps each class list in a separate file. Write a program that asks which file to open, displays every student, writes the students eligible for a scholarship to a file and displays a summary.

#### Format of the class file:
- Line 1: $n$, the number of students in the file.
- Every line after that: `Full Name,CGPA`. The name may contain spaces (at most 29 characters) but never a comma. The CGPA is a decimal number from 0.00 to 4.00.
- The file name is not fixed: the user types it, and it may include a folder name with spaces, for example `my files/class2.txt`.

#### Input file 1: `class1.txt` (dummy data)
```text
6
Ali Khan,3.65
Sara Ahmed,3.92
Usman Tariq,2.80
Hina Malik,3.50
Bilal Raza,3.10
Ayesha Noor,3.92
```

#### Input file 2: `my files/class2.txt` (dummy data — a file inside a folder named "my files")
```text
4
Zara Ali,3.50
Omar Farooq,3.9
Nida Khan,3.90
Ali Raza,3.49
```

#### What your program must do:
1. Display `Enter the file name: ` and read the name with `cin.getline(path, 100);` (not with `cin >>`, because the name may contain spaces).
2. Open the file and check it with `is_open()`.
3. Read $n$. If $n$ is more than 30, display `Too many students!` and end the program.
4. Read the records one by one and display each as `[Full Name] CGPA: value`.
5. Write every student with a CGPA of 3.50 or more to `scholarship.txt` as `Full Name,CGPA` (one per line). `scholarship.txt` is created fresh every time the program runs.
6. If the file ends before $n$ records have been read, display `Warning: only X of N records found.` after the records and continue with the $X$ records that were read.
7. Display the four summary lines shown in the sample. For `Top student`, if two students have the same highest CGPA, show the one that comes first in the file.

#### Error messages:
| Situation | Display exactly |
| :--- | :--- |
| The file cannot be opened | `Could not open ` + the name typed + `!` <br> _e.g._ `Could not open class9.txt!` |
| $n$ is more than 30 | `Too many students!` |
| The file has fewer records than $n$ | `Warning: only X of N records found.` (then continue) |
| No record could be read at all | `No students found!` (after the warning, if there is one) |

#### Sample run 1:
```text
Enter the file name: class1.txt
[Ali Khan] CGPA: 3.65
[Sara Ahmed] CGPA: 3.92
[Usman Tariq] CGPA: 2.8
[Hina Malik] CGPA: 3.5
[Bilal Raza] CGPA: 3.1
[Ayesha Noor] CGPA: 3.92
Students: 6
Average CGPA: 3.48167
Eligible for scholarship: 4
Top student: Sara Ahmed (3.92)
```

#### Output file after run 1: `scholarship.txt`
```text
Ali Khan,3.65
Sara Ahmed,3.92
Hina Malik,3.5
Ayesha Noor,3.92
```

#### Sample run 2 (file inside a folder):
```text
Enter the file name: my files/class2.txt
[Zara Ali] CGPA: 3.5
[Omar Farooq] CGPA: 3.9
[Nida Khan] CGPA: 3.9
[Ali Raza] CGPA: 3.49
Students: 4
Average CGPA: 3.6975
Eligible for scholarship: 3
Top student: Omar Farooq (3.9)
```

#### Output file after run 2: `scholarship.txt`
```text
Zara Ali,3.5
Omar Farooq,3.9
Nida Khan,3.9
```

#### Sample run 3 (wrong file name):
```text
Enter the file name: class9.txt
Could not open class9.txt!
```

> **Hint:** After `inFile >> n;` call `inFile.ignore(100, '\n');`, otherwise the first name starts with a new line. Read each record with `inFile.getline(name, 30, ',')` and `inFile >> cgpa`, then `inFile.ignore(100, '\n');`. If either read fails, the file has ended early. Copy the top name with `strcpy`.

---

### Q4 — Heart Rate Cleaner (Complete the Code) [5 Marks]
- **File:** `Q4_heart_rate.cpp`
- **Concepts:** unknown number of values, junk data, `clear()`, `eof()`, sentinel value, array limit, finding why the reading stopped, writing a file

A fitness band saves heart-rate readings in `heart_rate.txt`. Sometimes it writes junk words instead of numbers, and the value `-1` marks the end of the useful data. Complete the program so that it keeps the valid readings, skips the junk, writes a clean file and reports the results.

#### Format of `heart_rate.txt`:
- Positive whole numbers (readings) and junk words, separated by spaces or new lines.
- A junk word always starts with a letter and has fewer than 50 characters (for example `err`, `x9`).
- `-1` marks the end of the useful data; anything after it is ignored. The file may also end without a `-1`.
- At most 100 valid readings are stored.

#### Input file: `heart_rate.txt` (dummy data)
```text
70 90 err 80
110 x9 60 100
-1 95
```

#### Starter code (also in the sample files ZIP):
```cpp
/*
 * Name       : Student Name
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q4 - Heart Rate Cleaner
 */
 
#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    ifstream inFile("heart_rate.txt");
    if (!inFile) {
        cout << "heart_rate.txt not found!" << endl;
        return 1;
    }
 
    int rate[100];
    int count = 0;      // number of valid readings stored in rate[]
    int bad = 0;        // number of junk words skipped
    int x;
    char junk[50];
    int reason = 0;     // 1 = sentinel found, 2 = end of file, 3 = array full
 
    while (true) {
        if (_______(1)_______) {           // the array is full
            reason = 3;
            break;
        }
        if (inFile >> x) {                 // a number was read
            if (_______(2)_______) {       // the sentinel value
                reason = 1;
                break;
            }
            rate[count] = x;
            _______(3)_______;
        }
        else if (_______(4)_______) {      // nothing left in the file
            reason = 2;
            break;
        }
        else {                             // a junk word
            _______(5)_______;
            inFile >> junk;
            bad++;
        }
    }
    inFile.close();
 
    // TODO 1: Write every valid reading to clean_heart_rate.txt (one per line).
 
    // TODO 2: Display "Valid readings: " and "Junk skipped: ".
 
    // TODO 3: If count is 0, display "No valid readings!".
    //         Otherwise display the Average, Highest, Above average
    //         and Alerts (above 100) lines.
 
    // TODO 4: Display "Stopped because: " followed by
    //         sentinel found, end of file or array full.
 
    return 0;
}
```

#### Your task:
1. Fill in blanks (1) to (5) so that the loop stops in the three situations below and skips junk words.
2. Complete TODO 1 to TODO 4 so that the program produces the output described below.

#### Rules:
| Item | Rule |
| :--- | :--- |
| **Stopped because** | `sentinel found` if `-1` was read; `end of file` if the file ended; `array full` if 100 valid readings were stored. The array-full check comes first, before the next value is read, so with 100 stored readings the reason is array full even if `-1` comes next. |
| **Junk skipped** | The number of junk words skipped (each word counts once). |
| **clean_heart_rate.txt** | Every valid reading in the same order, one per line. Created fresh every run (empty if there are no valid readings). |
| **Average** | Total $\div$ number of valid readings, with decimals (plain `cout`). |
| **Highest** | The largest valid reading. |
| **Above average** | How many readings are greater than the average. |
| **Alerts (above 100)** | How many readings are greater than 100. |

#### Error / special messages:
| Situation | Display exactly |
| :--- | :--- |
| `heart_rate.txt` cannot be opened | `heart_rate.txt not found!` |
| No valid reading at all (empty file or only junk) | Display the `Valid readings` and `Junk skipped` lines, then `No valid readings!` instead of the Average, Highest, Above average and Alerts lines, then the `Stopped because` line. |

#### Sample output (screen):
```text
Valid readings: 6
Junk skipped: 2
Average: 85
Highest: 110
Above average: 3
Alerts (above 100): 1
Stopped because: sentinel found
```

#### Output file: `clean_heart_rate.txt`
```text
70
90
80
110
60
100
```

#### More examples (dummy data) to test your program:
| `heart_rate.txt` contains | Screen output |
| :--- | :--- |
| `abc 70 80 xyz` | `Valid readings: 2`<br>`Junk skipped: 2`<br>`Average: 75`<br>`Highest: 80`<br>`Above average: 1`<br>`Alerts (above 100): 0`<br>`Stopped because: end of file` |
| `err junk` | `Valid readings: 0`<br>`Junk skipped: 2`<br>`No valid readings!`<br>`Stopped because: end of file` |
| _(empty file)_ | `Valid readings: 0`<br>`Junk skipped: 0`<br>`No valid readings!`<br>`Stopped because: end of file` |

> **Hint:** A failed read stays failed until `inFile.clear();` is called — without it the loop never ends. Reaching the end of the file also makes a read fail, so ask `eof()` before treating it as junk. Store the average in a `double` and avoid integer division: `(double)total / count`.

---

### Q5 — Expense Tracker (Menu-Driven) [6 Marks]
- **File:** `Q5_expense_tracker.cpp`
- **Concepts:** menu with a loop, `ios::app` vs plain `ofstream`, reading a file again each time, data that stays after the program is closed, `strcmp`

Write a menu-driven program that keeps a record of a student's expenses in `expenses.txt`. Because the expenses are kept in a file, they must still be there after the program is closed and opened again. No input file is given for this question: your program creates `expenses.txt` itself.

#### Format of `expenses.txt` (written by your program):
```text
Food 450
Transport 1200
Food 300
```
One expense per line: `Category Amount`. The category is one word (at most 19 characters) and is case-sensitive (`Food` and `food` are different). The amount is a whole number.

#### The menu (display it exactly like this, again and again, until the user chooses 5):
```text
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 
```

#### What each option must do:
| Option | What happens (messages must be exactly as shown) |
| :---: | :--- |
| **1** | Display `Enter category: ` and read one word, then `Enter amount: ` and read a whole number. If the amount is 0 or less, display `Invalid amount!` and do not save it. Otherwise add the line `Category Amount` to the end of `expenses.txt` and display `Expense saved.`. |
| **2** | Open `expenses.txt` again and read all expenses (at most 100). Display each as `n. Category Amount` ($n$ starts at 1), then `Total spent: X` and `Largest expense: Category (Amount)`. If two expenses have the same largest amount, show the first one. If `expenses.txt` does not exist or is empty, display `No expenses yet.`. |
| **3** | Display `Enter category: ` and read one word. Display `Expenses in Category: count` and `Total for Category: total`. If there is no expense in that category (or no file), display `No expenses found for Category`. |
| **4** | Erase everything in `expenses.txt` and display `All expenses cleared.`. |
| **5** | Display `Goodbye!` and end the program. |
| **Any other number** | Display `Invalid choice!` and show the menu again. (The user always types a whole number for the choice.) |

#### Sample run 1 (`expenses.txt` does not exist yet):
```text
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 2
No expenses yet.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 1
Enter category: Food
Enter amount: 450
Expense saved.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 1
Enter category: Transport
Enter amount: 1200
Expense saved.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 1
Enter category: Food
Enter amount: 0
Invalid amount!
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 1
Enter category: Food
Enter amount: 300
Expense saved.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 7
Invalid choice!
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 5
Goodbye!
```

#### Output file after run 1: `expenses.txt`
```text
Food 450
Transport 1200
Food 300
```

#### Sample run 2 (run the program again — the expenses from run 1 are still there):
```text
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 2
1. Food 450
2. Transport 1200
3. Food 300
Total spent: 1950
Largest expense: Transport (1200)
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 3
Enter category: Food
Expenses in Food: 2
Total for Food: 750
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 3
Enter category: Books
No expenses found for Books
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 4
All expenses cleared.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 2
No expenses yet.
===== Expense Tracker =====
1. Add an expense
2. Show all expenses
3. Show total of a category
4. Clear all expenses
5. Exit
Enter your choice: 5
Goodbye!
```

> **Hint:** Use a `do … while (choice != 5)` loop. Option 1 opens the file with `ios::app`; Option 4 opens it with a plain `ofstream` and closes it straight away. Options 2 and 3 must open the file every time they are chosen, so they always see the latest data. Compare two words with `strcmp(category, wanted) == 0` (needs `#include <cstring>`).

---

## Submission and Deadline Rules
- The portal upload time is your official submission time. Your record of submission is taken from the portal only.
- **No PDF on the portal = not submitted**, even if your GitHub work is complete.
- Only the version of your repository at the deadline (Thursday, 29 October 2026, 11:55 PM Pakistan time) is marked. Commits made after 11:55 PM are ignored, even if they fix a mistake. Commit times are shown on your Commits page.
- Late submissions are handled as per course policy.
- A wrong file name, missing pages or unclear screenshots will lose marks.

### Rules
- All commits must be made from **YOUR OWN account**. Work pushed from someone else's account will receive zero.
- Do not delete or rename the repository after submission.
- Copying another student's code will be treated as plagiarism; both students receive zero for the assignment.
- Programs that print fixed answers instead of reading the file receive zero for that question.

---

## Marking Rubric
Every check below is marked by running your program with the sample file or with another file of the same format. A check receives its marks only if the screen output (and the output file, where listed) matches exactly; otherwise it receives 0.

| Item | What is checked | Marks |
| :--- | :--- | :---: |
| **Part A — GitHub** | | **5** |
| A1 Repository | Name exactly `Assignment02-File-Handling`; Public; description `File Handling`; README present | 1 |
| A2 Files | All 5 `.cpp` files with exact names on the main page (0.1 each); header comment with your Reg No in each file (0.1 each) | 1 |
| A3 Commits | At least 7 commits made before the deadline (29 Oct 2026, 11:55 PM) | 1 |
| | Commit messages from Task A3 present (`Add Q1` … `Add Q5`, `README update`); README contains name, Reg No and the 5 file names | 1 |
| A4 Share & Submit | Instructor invited; correctly named PDF with all 3 pages uploaded on time | 1 |
| **Q1 — Stock Report (Debugging)** | | **4** |
| | Program compiles | 0.5 |
| | Six `// FIX n:` comments present (FIX 1 to FIX 6) | 0.5 |
| | Sample `stock.txt`: screen output exactly as shown | 1 |
| | A different `stock.txt` of the same format: screen output correct | 0.5 |
| | `reorder.txt`: old lines kept, new low-stock items added one per line | 1 |
| | `stock.txt` missing: correct message | 0.5 |
| **Q2 — Parking Report** | | **5** |
| | Program compiles | 0.5 |
| | Sample `parking.txt`: screen output exactly as shown | 1 |
| | Sample `parking.txt`: `receipts.txt` exactly as shown | 0.5 |
| | A different `parking.txt` (other date, plates and times, including exactly 60 and 61 minutes): screen output correct | 1 |
| | The same different file: `receipts.txt` correct | 0.5 |
| | A file with only one type of vehicle (all cars or all bikes): counts and totals correct | 0.5 |
| | `parking.txt` missing: correct message | 0.5 |
| | Date and header only, no vehicles: correct messages | 0.5 |
| **Q3 — Scholarship List** | | **5** |
| | Program compiles | 0.5 |
| | `class1.txt`: screen output exactly as shown | 1 |
| | `class1.txt`: `scholarship.txt` exactly as shown | 0.5 |
| | A file inside a folder whose name contains a space: opened and processed correctly | 0.5 |
| | A different class file (including a tie for top CGPA and a CGPA of exactly 3.50): output and `scholarship.txt` correct | 0.5 |
| | A file with fewer records than $n$: warning and summary correct | 0.5 |
| | $n$ more than 30: correct message | 0.5 |
| | A file name that does not exist: correct message | 0.5 |
| | A file with no records: correct message | 0.5 |
| **Q4 — Heart Rate Cleaner** | | **5** |
| | Program compiles | 0.5 |
| | Sample `heart_rate.txt`: screen output exactly as shown | 1 |
| | Sample `heart_rate.txt`: `clean_heart_rate.txt` exactly as shown | 0.5 |
| | A file without `-1`: stops with end of file, results correct | 0.5 |
| | A file with more than 100 readings: stops with array full, results correct | 0.5 |
| | A file with junk at the start and at the end: junk count and results correct | 0.5 |
| | An empty file: correct messages | 0.5 |
| | A file with only junk words: correct messages | 0.5 |
| | `heart_rate.txt` missing: correct message | 0.5 |
| **Q5 — Expense Tracker** | | **6** |
| | Program compiles | 0.5 |
| | Menu displayed exactly; Exit ends the program with `Goodbye!` | 0.5 |
| | Adding expenses: `expenses.txt` has the correct lines; Option 2 shows the list, total and largest correctly | 1 |
| | Run the program a second time: expenses from the first run are still shown and added to | 1 |
| | Option 3: category found (count and total) and category not found | 1 |
| | Option 4: file emptied; Option 2 then shows `No expenses yet.` | 0.5 |
| | Invalid choice and invalid amount (not saved) handled | 0.5 |
| | Option 2 and Option 3 when `expenses.txt` does not exist yet | 0.5 |
| | After clearing, newly added expenses are shown alone (no old data) | 0.5 |
| **Total** | | **30** |

---

### Marks are lost in these situations:
| Situation | Result |
| :--- | :--- |
| Program does not compile | 0 for that question |
| `.cpp` file has a different name or is inside a folder | Treated as not submitted: 0 for that question |
| Path such as `C:/...` written in the code | Input files are not found: the checks of that question fail |
| Extra text printed (welcome message, "Press any key", etc.) | Output does not match: those checks fail |
| Program runs longer than 2 seconds on a check (endless loop) | 0 for that check |
| Fixed answers printed instead of reading the file | 0 for that question |
| Commits after the deadline | Ignored: the version at the deadline is marked |

---

## For Queries
- **Email:** `fareeha.iqbal@ucp.edu.pk`
- **Office Hours:** Wednesday 11:00 AM – 1:00 PM, Friday 10:00 AM – 12:30 PM
- **Office Venue:** A Building F301 – Cabin 4