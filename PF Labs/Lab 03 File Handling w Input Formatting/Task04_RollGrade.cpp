#include <iostream>
#include <fstream>
using namespace std;
int main()
{
        ifstream readResult("results.txt");
        ofstream renderGrades("gradeA.txt");

        int roll[30], marks[30];
        char grade[30];
        int n = 0, A = 0, B = 0, C = 0, F = 0;

        readResult.ignore(69, '\n');

        while (n < 30 &&
            readResult >> roll[n] >> grade[n] >> marks[n])
        {
            n++;
        }

        cout << "Roll  Grade  Marks\n";

        int top = 0;

        for (int i = 0; i < n; i++)
        {
            cout << roll[i] << "    "
                << grade[i] << "      "
                << marks[i] << endl;

            if (grade[i] == 'A')
            {
                A++;
                renderGrades << roll[i] << " "
                    << marks[i] << endl;
            }
            else if (grade[i] == 'B')
                B++;
            else if (grade[i] == 'C')
                C++;
            else if (grade[i] == 'F')
                F++;

            if (marks[i] > marks[top])
                top = i;
        }

        cout << "Students: " << n << endl;
        cout << "A: " << A << "  B: " << B
            << "  C: " << C << "  F: " << F << endl;

        if (n > 0)
            cout << "Topper: Roll " << roll[top]
            << " (" << marks[top] << ")" << endl;

        readResult.close();
        renderGrades.close();

        return 0;
    }

