# Programming Fundamentals
## Assignment 1 — Getting Started with GitHub

**Total Marks:** 10  
**Due:** 14th October 2026, 11:48 PM

## Scenario

Every program you write this semester will be stored and submitted through GitHub. In this first assignment you will set up your own GitHub account, create a repository, upload a C++ program, and build up a clean history of commits — exactly the way professional programmers keep track of their work.

Follow the Assignment 01 slides step by step. All examples use the sample registration number `L1F24BSCS0081`; replace it with your own.

## Before You Start

1. Use an Incognito / Private window. Press `Ctrl + Shift + N` (Chrome / Edge) or `Ctrl + Shift + P` (Firefox) so that no other student's GitHub login interferes with yours.
2. Keep an email account open that you can access right now — GitHub sends an 8-digit verification code.
3. Create only **ONE** GitHub account. You will use it for every lab and assignment this semester.

## Task 1 — Create Your GitHub Account [2 Marks]

Sign up at `github.com/signup`. Your username must be your UCP registration number, written exactly as on your student card.

**Example:**
- **Username:** `L1F24BSCS0081`
- **Profile:** `https://github.com/L1F24BSCS0081`

1. Do **NOT** add your name, extra hyphens, underscores or any other characters.
2. Complete the puzzle and the email verification code step.
3. If GitHub says your registration number is already taken, inform the instructor — do not invent a different username.

## Task 2 — Create a Repository [1 Mark]

Create a new repository with the following settings:

| Setting | Required value |
|---|---|
| Repository name | `Assignment01-GitHub-Basics` |
| Description | `Assignment 01 - Getting started with GitHub` |
| Visibility | **Public** |
| Add README | **ON** — this creates Commit #1 automatically |

## Task 3 — Upload Your C++ Program [2 Marks]

Write a C++ program that calculates the sum of the first 50 natural numbers, then upload it to your repository using **Add file → Upload files**.

**File name (must be exactly):**

`sum_of_first_50_natural_numbers.cpp`

1. The first version you upload should contain only the loop that calculates the sum and prints it.
2. The file must compile and run without errors.
3. Commit message for this upload:

`Add C++ program to find sum of first 50 natural numbers`

**Sample Run:**

```text
Sum of first 50 natural numbers (loop): 1275
```

## Task 4 — Make At Least 5 Meaningful Commits [3 Marks]

Improve your work in small steps. Each improvement must be saved as a separate commit using the **Edit** button and **Commit changes**. Your history must contain at least these 5 commits:

| Commit | Message / Change |
|---|---|
| 1 | **Initial commit** — README, automatic |
| 2 | **Add C++ program to find sum of first 50 natural numbers** |
| 3 | **Add header comments with name and reg no** |
| 4 | **Add formula-based verification n(n+1)/2** |
| 5 | **Update README with program description and output** |

### Commit 3

Add a comment block at the top of the `.cpp` file with:
- Program title
- Your name
- Your registration number
- Assignment number

### Commit 4

Add a second calculation using the formula `n(n+1)/2` and print it, so both methods show `1275`.

### Commit 5

Edit `README.md` to describe your program and paste its output.

Every commit message must clearly describe the change. Messages like `update`, `asdf` or `final` will lose marks.

## Final Sample Run

```text
Sum of first 50 natural numbers (loop): 1275
Sum using formula n(n+1)/2: 1275
```

## Task 5 — Share with Instructor and Submit on Portal [2 Marks]

### Step A — Invite the Instructor as a Collaborator

Go to:

**Settings → Collaborators → Add people**

**Instructor email:** `fareeha.iqbal@ucp.edu.pk`

1. Type the email exactly as written above and click **Add … to this repository**.
2. The collaborator will show as **Pending Invite** until the instructor accepts — this is fine.

### Step B — Prepare ONE PDF File

**File name:**

`L1F24BSCS0081_Assignment01.pdf`

Replace the sample registration number with your own.

The PDF must contain:

1. **Page 1:** Your repository link.
2. **Page 2:** Screenshot of your Commits page showing at least 5 commits.
3. **Page 3:** Screenshot of Settings → Collaborators showing the instructor invited.

**Example repository link:**

`https://github.com/L1F24BSCS0081/Assignment01-GitHub-Basics`

### Step C — Upload the PDF on the Course Portal

1. Submit only **ONE PDF file**.
2. Do not upload `.cpp` files, images or Word files separately on the portal.
3. Screenshots must be full-screen and clearly show your username and the address bar.
4. Check that the repository link opens in an Incognito window before you submit.

## Submission and Deadline Rules

1. The portal upload time is your official submission time. Your record of submission is taken from the portal only.
2. No PDF on the portal = not submitted, even if your GitHub work is complete.
3. Only commits made before the deadline will be marked. Commit times are visible on your Commits page and will be checked.
4. Late submissions are handled as per course policy.
5. A wrong file name, missing pages or unclear screenshots will lose marks.

## Rules

1. All commits must be made from **YOUR OWN account**. Work pushed from someone else's account will receive zero.
2. Do not delete or rename the repository after submission.
3. Copying another student's code or commit history will be treated as plagiarism.

## Marking Breakdown

| Task | Marks | What is Checked |
|---|---:|---|
| Task 1 — GitHub Account | 2 | Username exactly matches Reg No; account verified |
| Task 2 — Repository | 1 | Correct name, Public, README present |
| Task 3 — Upload .cpp File | 2 | Correct file name; program compiles and prints 1275 |
| Task 4 — Five Commits | 3 | At least 5 commits before the deadline; each change is real and clearly described |
| Task 5 — Share and Submit | 2 | Instructor invited as collaborator; correctly named PDF with all 3 pages uploaded on the portal on time |
| **Total** | **10** | |

