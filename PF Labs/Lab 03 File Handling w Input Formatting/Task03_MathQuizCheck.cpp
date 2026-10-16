#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream quizCheck("quiz.txt");
    ofstream corrections("corrections.txt");

    if (!quizCheck) {
        cout << "quiz.txt doesn't exist\n";
        return 1;
    }

    if (!corrections) {
        cout << "Error opening corrections.txt for writing\n";
        return 1;
    }

    int num1 = 0, num2 = 0, studentAns = 0;
    char op = ' ', eq = ' ';
    
    int qNum = 1;
    int score = 0;
    int validQuestions = 0;

    while (quizCheck >> num1 >> op >> num2 >> eq >> studentAns) {
        cout << "Q" << qNum << ": " << num1 << " " << op << " " << num2 << " " << eq << " " << studentAns << " ";


        if (op == '/' && num2 == 0) {
            cout << "Invalid question\n";
        } else {
            validQuestions++;
            int correctAnswer = 0;

            switch (op) {
                case '+':
                    correctAnswer = num1 + num2;
                    break;
                case '-':
                    correctAnswer = num1 - num2;
                    break;
                case '*':
                    correctAnswer = num1 * num2;
                    break;
                case '/':
                    correctAnswer = num1 / num2;
                    break;
            }


            if (studentAns == correctAnswer) {
                cout << "Correct\n";
                score++;
            } else {
                cout << "Wrong\n";

                corrections << num1 << " " << op << " " << num2 << " = " << correctAnswer << " (you wrote " << studentAns << ")\n";
            }
        }
        qNum++;
    }


    cout << "\nScore: " << score << " / " << validQuestions << "\n";


    quizCheck.close();
    corrections.close();

    return 0;
}
