#include<iostream> 
using namespace std; 

/* Statement:
An array records total marks (out of 100) of 10 students in a class.
Write a C++ program  that stores marks of 10 students in an array.
Determines the top 3 highest marks and displays the marks of the top 3.
 */

    int main() {

        int st[10] = {0}; //index = size - 1

        for (int marks = 0; marks < 10; marks++)
        {
            if (marks < 0 || marks > 100)
            {
                cout << "Invalid marks. Please enter marks between 0 and 100." << endl;
                marks--;
                continue; 
            }

            cout << "Enter marks of student " << marks + 1 << ": ";
            cin >> st[marks];

            //check highest marks of students after all input are done

            for (int highest = 0; highest < 10; highest++)
            {
                for (int next = highest + 1; next < 10; next++)
                {
                    if (st[highest] < st[next])
                    {
                        int high = st[highest];
                        st[highest] = st[next];
                        st[next] = high;
                    }
                }

                //print top 3 highest marksafter each
                if (highest < 3)
                {
                    cout << "Top " << highest + 1 << " highest marks: " << st[highest] << endl;
                }
            }
        }
    
    return 0;
}
