#include <iostream>
using namespace std;

int countWords(char s[]);
void capitalizeWords(char s[]);
void replaceChar(char s[], char from, char to);

int main() {
    char sentence[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);

    cout << "Words: " << countWords(sentence) << endl;

    capitalizeWords(sentence);
    cout << "Capitalized: " << sentence << endl;

    replaceChar(sentence, ' ', '-');
    cout << "Slug: " << sentence << endl;

    return 0;
}

int countWords(char s[]) {
    int words = 0;
    bool inWord = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && !inWord) {
            inWord = true;
            words++;
        } else if (s[i] == ' ') {
            inWord = false;
        }
    }
    return words;
}

void capitalizeWords(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 32;
            }
        }
    }
}

void replaceChar(char s[], char from, char to) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == from) {
            s[i] = to;
        }
    }
}