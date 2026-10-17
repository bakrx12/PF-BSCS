#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream readKey("key.txt");
    ifstream response("responses.txt");
    ofstream renderScores("scores.txt");

    char key[10], name[50], answers[11], topName[50];
    int score, passed = 0, failed = 0, highest = -1;

    for (int i = 0; i < 10; i++)
        readKey >> key[i];

    while (response >> name >> answers)
    {
        score = 0;

        for (int i = 0; i < 10; i++)
        {
            if (answers[i] == key[i])
                score++;
        }

        cout << name << ": " << score << "/10" << endl; 
        renderScores << name << " " << score << endl;

        if (score >= 5)
            passed++;
        else
            failed++;

        if (score > highest)
        {
            highest = score;

            int i = 0;
            while (name[i] != '\0')
            {
                topName[i] = name[i];
                i++;
            }
            topName[i] = '\0';
        }
    }

    cout << "Passed: " << passed << "  Failed: " << failed << endl;
    cout << "Topper: " << topName << " (" << highest << "/10)" << endl;

    readKey.close();
    response.close();
    renderScores.close();

    return 0;
}