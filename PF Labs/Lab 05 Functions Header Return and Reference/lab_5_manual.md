# WEEK 5: Functions: Designing Headers, Return vs void, and Reference Parameters

> **Note:** This lab includes a total of 6 questions. Every question is a problem to solve and build: you read the problem, design the functions, and write the complete program. The lab is 2.5 hours long; a suggested time is given with each question.  
> **Note:** Every question names the lecture slides it is based on, from *"Functions in C++ – Lecture 1"* and *"Functions in C++ – Lecture 2"*. Open that slide and read it before you start the question.  
> **Note:** Design first, then code. Before you write any code, copy the question's design table into your notebook and write the header of every function. The tables give you less help as you go: in Q6 you make the whole table yourself.  
> **Note:** From this lab onwards, use the layout from Lecture 2, slide 9: prototypes above `main()`, then `main()`, then the function definitions below `main()`. Every prototype ends with a semicolon, and every definition header must match its prototype.

---

## Before You Start: Choosing the Header

Every function header answers three questions (Lecture 1, slide 20): 
1. **What job does it do?** (gives the name)
2. **What does it need?** (gives the parameters)
3. **What does it give back?** (gives the return type)

Use this guide to decide the return type and the kind of each parameter:

| Ask yourself | If the answer is… | Then write… |
| :--- | :--- | :--- |
| **What does the function give back to `main()`?** | One answer that `main()` will store, print or test | The type of that answer as the return type (`int`, `double`, `char` or `bool`) and a `return` statement |
| | Nothing: it only shows something on the screen, or only does a job | `void` as the return type, no return value |
| **Must the function change a variable of `main()`, or send back two or more answers?** | Yes | A reference parameter for each of those variables: `int &x` |
| | No, it only reads the values it is given | Value parameters: `int x` |

> **Return it or print it?** `cout` only shows a value on the screen; `main()` cannot use it. `return` hands the value back to `main()` so it can be stored, printed or used in a calculation. If `main()` needs the answer for its next step, return it.

---

## Objectives

* Read a problem statement and turn every job in it into a function header by answering three questions: what job, what input, what output.
* Decide when a function should return a value and when it should be `void`, by checking whether `main()` needs the answer or only the screen does.
* Choose the right return type (`int`, `double`, `char` or `bool`) for each answer a function gives back.
* Write function prototypes above `main()` and definitions below it, using the layout from Lecture 2.
* Use value parameters when a function only reads its input, and reference parameters when it must change a variable of `main()` or send back more than one answer.
* Build complete programs in which `main()` reads like a short to-do list of function calls.

---

## Tasks

### Q1. Design Before You Code: The Student Help Desk

The college help desk wants a small program to help students at the counter. Before anyone writes code, the job list below must be turned into function headers. Your first task is the design: for each job, decide what the function needs, what it gives back, and write its prototype. Row 1 is done for you.

* **Slide reference:** Functions Lecture 1, slide 17 (Return type), slide 20 (Design any function with 3 questions) and slide 23 (Value-returning vs void); Functions Lecture 2, slide 8 (Function prototype) and slide 23 (Value vs reference parameter).
* **Suggested time:** 20 minutes

| Job | Input | Output | Return type | Prototype |
| :--- | :--- | :--- | :--- | :--- |
| `showBanner`: print the help-desk banner (a dashed line, the title, a dashed line) | nothing | nothing (only the screen) | `void` | `void showBanner();` |
| `printDashes`: print a line of $n$ dashes | | | | |
| `area`: find the area of a rectangular classroom from its length and width (in metres, may have decimals) | | | | |
| `canVote`: check whether a student is old enough to vote (18 or more) | | | | |
| `fullWeeks`: find how many complete weeks are in a number of days | | | | |
| `passOrFail`: give 'P' for pass or 'F' for fail from the marks (pass is 50 or more) | | | | |
| `addFine`: add a 10% late fine to a fee that is stored in `main()`, so that `main()`'s fee changes | | | | |
| `readStudent`: read a student's roll number and age from the keyboard into `main()`'s variables | | | | |

Then write a program that uses `showBanner`, `printDashes`, `readStudent`, `canVote`, `passOrFail` and `addFine`. `showBanner` must print its dashed lines by calling `printDashes(30)`. `main()` shows the banner, reads the roll number and age, says whether the student can vote, reads the marks and shows P or F, reads the fee and shows it after the fine, and ends with a dashed line.

#### Sample Run 1:
```text
------------------------------
    STUDENT HELP DESK
------------------------------
Enter roll number and age: 21 19
Roll 21 can vote.
Enter marks: 45
Result: F
Enter fee: 5000
Fee after 10% fine: 5500
------------------------------
```

#### Sample Run 2:
```text
------------------------------
    STUDENT HELP DESK
------------------------------
Enter roll number and age: 34 17
Roll 34 cannot vote yet.
Enter marks: 50
Result: P
Enter fee: 2000
Fee after 10% fine: 2200
------------------------------
```

#### Your task:
1. Complete all eight rows of the design table in your notebook.
2. Write the program using the Lecture 2 layout (prototypes, `main()`, definitions) and confirm both sample runs.
3. Write the definitions of `area` and `fullWeeks` as well, and test them with one line each in `main()`: `area(7.5, 6)` must give 45 and `fullWeeks(30)` must give 4.

> **Hint:** Look at the Output column first. If the answer goes back to `main()`, its type is the return type. If there is no answer, or `main()`'s own variables are filled in or changed, the return type is `void` and those variables need `&`. A function can call another function: `showBanner` can call `printDashes(30)`; just as `main()` does.

---

### Q2. Return It or Print It? The School Canteen

The school canteen needs a billing program. The cashier sees the menu, then types an item code and the quantity for each item the student buys, and types 0 when the order is finished. For each valid item the program prints one receipt line; for a code that is not on the menu it prints `Invalid code, try again`. If the subtotal is Rs 1000 or more, the student gets a 10% discount. At the end the program shows the subtotal, the discount and the amount to pay.

* **Slide reference:** Functions Lecture 1, slide 24 (Why do we need void functions?) and slide 27 (Void vs value-returning: same caller, different destination); Functions Lecture 2, slide 13 (Three ways to call a function).
* **Suggested time:** 25 minutes

#### Menu:
1. Samosa — Rs 50  
2. Shawarma — Rs 250  
3. Juice — Rs 120  
4. Tea — Rs 60  
5. Biryani — Rs 300  

Write the program with exactly these four functions. The table gives the input, job and output of each; you write the header.

| Function | Input (what it needs) | Job (what it does) | Output (what it gives back) | Your header |
| :--- | :--- | :--- | :--- | :--- |
| `showMenu` | nothing | print the menu with codes and prices | nothing (only the screen) | |
| `priceOf` | an item code | find the price of that item; give 0 if the code is not on the menu | the price (a whole number), used by `main()` to work out the line total | |
| `printName` | an item code | print the item's name on the screen (no new line) | nothing (only the screen) | |
| `finalBill` | the subtotal | take off 10% if the subtotal is 1000 or more | the amount to pay (may have decimals) | |

#### Sample Run 1:
```text
===== SCHOOL CANTEEN =====
1. Samosa     Rs 50
2. Shawarma   Rs 250
3. Juice      Rs 120
4. Tea        Rs 60
5. Biryani    Rs 300
==========================
Enter item code (0 to finish): 1
Quantity: 4
  Samosa x 4 = Rs 200
Enter item code (0 to finish): 5
Quantity: 2
  Biryani x 2 = Rs 600
Enter item code (0 to finish): 7
Invalid code, try again.
Enter item code (0 to finish): 3
Quantity: 2
  Juice x 2 = Rs 240
Enter item code (0 to finish): 0
Subtotal: Rs 1040
Discount: Rs 104
Amount to pay: Rs 936
```

#### Sample Run 2 (menu not shown):
```text
Enter item code (0 to finish): 4
Quantity: 2
  Tea x 2 = Rs 120
Enter item code (0 to finish): 1
Quantity: 3
  Samosa x 3 = Rs 150
Enter item code (0 to finish): 0
Subtotal: Rs 270
Discount: Rs 0
Amount to pay: Rs 270
```

#### Your task:
1. Write the four headers in the design table. Then explain in one sentence why `priceOf` returns a value but `printName` is `void`.
2. Write the program and confirm both sample runs.
3. The canteen changes its discount rule: 0% below Rs 1000, 10% from Rs 1000 to Rs 1999, and 15% for Rs 2000 or more. Add a new function `discountPercent` that gives back the percentage for a subtotal, and use it inside `finalBill`. Test it with a subtotal of 2400: the amount to pay must be Rs 2040.

> **Hint:** Ask where each answer goes. The price is needed in a calculation, `priceOf(code) * qty`, so it must come back to `main()` with `return`. The name only has to appear on the screen, so `printName` can print it itself and give nothing back (Lecture 1, slide 27). The same `while` loop that reads the code handles 0 and invalid codes.

---

### Q3. Value-returning Functions: The Number Explorer

The college maths club wants a program that explores any positive number. The user types numbers one at a time and types 0 to stop. For each number the program displays how many digits it has, the sum of its digits, the number reversed, whether it is a palindrome (the same forwards and backwards, like 12321) and whether it is a Harshad number (a number that divides exactly by the sum of its digits, like 156: $1 + 5 + 6 = 12$ and $156 \div 12 = 13$).

* **Slide reference:** Functions Lecture 1, slide 17 (Return type) and slide 25 (Value-returning function); Functions Lecture 2, slide 10 (Functions can call each other freely) and slide 13 (Calling a function inside an expression).
* **Suggested time:** 20 minutes

| Function | Input (what it needs) | Job (what it does) | Output (what it gives back) | Your header |
| :--- | :--- | :--- | :--- | :--- |
| `countDigits` | a positive whole number | count its digits | the number of digits | |
| `sumDigits` | a positive whole number | add up its digits | the sum | |
| `reverseNumber` | a positive whole number | write its digits in reverse order ($156 \to 651$) | the reversed number | |
| `isPalindrome` | a positive whole number | check whether it reads the same both ways; it must call `reverseNumber` | yes or no | |
| `isHarshad` | a positive whole number | check whether it divides exactly by the sum of its digits; it must call `sumDigits` | yes or no | |

#### Sample Run:
```text
Enter a positive number (0 to stop): 12321
Digits: 5
Sum of digits: 9
Reverse: 12321
Palindrome: Yes
Harshad number: Yes

Enter a positive number (0 to stop): 156
Digits: 3
Sum of digits: 12
Reverse: 651
Palindrome: No
Harshad number: Yes

Enter a positive number (0 to stop): 0
Goodbye!
```

#### Your task:
1. Write the five headers in the design table.
2. Write the program and confirm the sample run. `main()` must use `isPalindrome` and `isHarshad` inside `if` conditions.
3. Add a few lines at the end of `main()` that use `isPalindrome` in a loop to print every palindrome from 100 to 200. You should get 10 numbers, starting with 101, 111, 121...

> **Hint:** `n % 10` gives the last digit and `n / 10` removes it. Each function gets its own copy of the number (a value parameter), so it can change `n` inside the loop without changing `main()`'s number (Lecture 2, slide 18). A yes or no answer is a `bool`, and a `bool` function can return the comparison itself: `return reverseNumber(n) == n;`

---

### Q4. Reference Parameters: The PocketWallet App

A mobile wallet app starts with a balance of Rs 1000. It shows a menu again and again until the user chooses Exit. Deposit adds money to the balance. Withdraw takes money out only if the balance is enough; otherwise it takes nothing out and tells the user. Balance shows the current balance. The balance is kept in one variable inside `main()`, and the functions must work on that variable.

* **Slide reference:** Functions Lecture 2, slides 20–22 (Reference parameter), slide 23 (Value vs reference: side by side) and slide 26 (Rules for reference parameters).
* **Suggested time:** 25 minutes

| Function | Input (what it needs) | Job (what it does) | Output (what it gives back) | Your header |
| :--- | :--- | :--- | :--- | :--- |
| `showMenu` | nothing | print the four choices | nothing (only the screen) | |
| `deposit` | the balance and the amount | add the amount to the balance | nothing comes back, but `main()`'s balance must change | |
| `withdraw` | the balance and the amount | take the amount out only if the balance is enough | `main()`'s balance changes, and `main()` must also be told yes or no: did it work? | |
| `showBalance` | the balance | print the current balance | nothing (it only reads the balance) | |

#### Sample Run:
```text
Welcome to PocketWallet. Starting balance: Rs 1000
1. Deposit  2. Withdraw  3. Balance  4. Exit
Choice: 1
Amount to deposit: 500
Deposit successful.

1. Deposit  2. Withdraw  3. Balance  4. Exit
Choice: 2
Amount to withdraw: 2000
Not enough balance. Nothing was taken out.

1. Deposit  2. Withdraw  3. Balance  4. Exit
Choice: 2
Amount to withdraw: 700
Withdrawal successful.

1. Deposit  2. Withdraw  3. Balance  4. Exit
Choice: 3
Current balance: Rs 800

1. Deposit  2. Withdraw  3. Balance  4. Exit
Choice: 4
Thank you for using PocketWallet.
```

#### Your task:
1. Write the four headers in the design table. Mark every parameter that needs `&` and give the reason in one sentence.
2. Write the program and confirm the sample run.
3. The bank adds a new rule: one withdrawal cannot be more than Rs 25,000. Change only the `withdraw` function so that it refuses such amounts; `main()` must not change at all. Deposit Rs 30,000, then try to withdraw Rs 26,000 (refused) and Rs 25,000 (allowed).

> **Hint:** The `&` goes in the prototype and the definition header, never in the call: `deposit(balance, amount);`. `withdraw` can do two things at once: change the balance through `&` and return a `bool`, so `main()` can write `if (withdraw(balance, amount))`. `showBalance` only reads the balance, so a value parameter is enough (Lecture 2, slide 23: "Use it when").

---

### Q5. More Than One Answer: The T20 Chase Scoreboard

In a T20 cricket match the chasing team can face 120 balls (20 overs). Write a scoreboard program that reads the target, the runs scored, the wickets lost and the number of balls bowled so far. It displays the score with the overs written as `overs.balls` (98 balls is 16.2 overs: 16 complete overs and 2 balls), the current run rate ($\text{runs} \times 6 \div \text{balls bowled}$), how many runs are needed from how many balls, and the required run rate ($\text{runs needed} \times 6 \div \text{balls left}$).

* **Slide reference:** Functions Lecture 2, slide 16 (The matching rule: same number, same order, same type) and slide 25 (More than one answer: return gives one value, references give more).
* **Suggested time:** 25 minutes

| Function | Input (what it needs) | Job (what it does) | Output (what it gives back) | Your header |
| :--- | :--- | :--- | :--- | :--- |
| `ballsToOvers` | the number of balls bowled | split them into complete overs and the balls left over ($98 \to 16\text{ and }2$) | two answers: the overs and the extra balls | |
| `runRate` | the runs and the balls bowled | work out the runs per over | the run rate (may have decimals) | |
| `runsNeeded` | the target and the runs | work out how many more runs are needed | the runs needed | |
| `requiredRate` | the runs needed and the balls left | work out the runs per over needed from now on | the required rate (may have decimals) | |
| `showScore` | the runs, wickets, overs and extra balls | print the score line | nothing (only the screen) | |

#### Sample Run 1:
```text
Target: 191
Runs, wickets and balls bowled: 147 4 98
Score: 147/4 in 16.2 overs
Current run rate: 9
Need 44 runs from 22 balls
Required run rate: 12
```

#### Sample Run 2:
```text
Target: 171
Runs, wickets and balls bowled: 120 2 90
Score: 120/2 in 15.0 overs
Current run rate: 8
Need 51 runs from 30 balls
Required run rate: 10.2
```

#### Your task:
1. Write the five headers in the design table. Which function is the only one that needs reference parameters, and why?
2. Write the program and confirm both sample runs.
3. Write a new function that does the opposite of `ballsToOvers`: it takes the complete overs and the extra balls (16 and 2) and gives back the total number of balls (98). Design its header with the three questions first. Then change `main()` so that the user types the overs as two numbers (`16 2`) instead of typing the balls.

> **Hint:** `return` can give back only one value, so a function with two answers is `void` and fills in two reference parameters (Lecture 2, slide 25). `balls / 6` gives the complete overs and `balls % 6` gives the rest. Use `6.0` instead of `6` in the rate formulas, otherwise the decimal part is lost. In every call, send the values in the same order as the header.

---

## PRACTICE AT HOME

### Q6. Everything Together: Factory Salary Slips

A factory pays its workers by the hour. Write a program that asks how many workers there are and then, for each worker, reads the hours worked and the rate per hour, works out the pay and prints a salary slip. At the end it shows the total net pay for all workers. This time there is no design table: you make it yourself.

* **Slide reference:** Functions Lecture 2, slide 9 (Program layout), slide 16 (The matching rule), slide 23 (Value vs reference) and slides 29–30 (The Student Result program: `main()` reads like a to-do list).
* **Suggested time:** 30 minutes

#### Pay rules:
* **Gross pay:** The first 160 hours are paid at the normal rate. Each hour above 160 is overtime and is paid at $1.5 \times \text{rate}$.
* **Tax:** 
  * No tax if the gross pay is Rs 50,000 or less
  * 5% of the gross pay if it is up to Rs 100,000
  * 10% if it is more than Rs 100,000
* **Net pay:** $\text{Gross pay} - \text{Tax}$

The program must use these four functions. Only their jobs are given:
1. Read one worker's hours and rate from the keyboard into `main()`'s variables.
2. Work out the gross pay from the hours and the rate.
3. Work out the tax on a gross pay.
4. Print one salary slip, given the worker number, hours, gross pay, tax and net pay.

#### Sample Run:
```text
How many workers? 3

Worker 1
Hours worked and rate per hour: 170 300
---- Salary Slip: Worker 1 ----
Hours: 170
Gross pay: Rs 52500
Tax: Rs 2625
Net pay: Rs 49875

Worker 2
Hours worked and rate per hour: 150 250
---- Salary Slip: Worker 2 ----
Hours: 150
Gross pay: Rs 37500
Tax: Rs 0
Net pay: Rs 37500

Worker 3
Hours worked and rate per hour: 200 600
---- Salary Slip: Worker 3 ----
Hours: 200
Gross pay: Rs 132000
Tax: Rs 13200
Net pay: Rs 118800

Total paid to all workers: Rs 206175
```

#### Your task:
1. Draw your own design table with the columns **Function**, **Input**, **Job**, **Output** and **Your header**, and fill it in for the four functions. Show it to your instructor before you start coding.
2. Write the program and confirm the sample run. `main()` should read like a to-do list: read, work out, print, add to the total.
3. Add a fifth function that gives each worker a pay grade from the net pay: **A** for Rs 100,000 or more, **B** for Rs 40,000 or more, and **C** below that. Show the grade on the slip. For the sample run the grades are B, C and A.

> **Hint:** Worker 1: $160 \times 300 = 48,000$ plus 10 overtime hours $\times 450 = 4,500$, so the gross pay is 52,500 and the tax is 5%. Only the reading function must fill in `main()`'s variables, so it is the only one that needs `&`. The total must be added up in `main()`, because only `main()` sees every worker.

---

*Great Job, Rest Time😊*