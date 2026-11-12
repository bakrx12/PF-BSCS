#include <iostream>
using namespace std;

int strLength(char s[]);
int countVowels(char s[]);
void toUpperCase(char s[]);

int main() {
    char sentence[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);

    cout << "Length: " << strLength(sentence) << endl;
    cout << "Vowels: " << countVowels(sentence) << endl;

    toUpperCase(sentence);
    cout << "Upper case: " << sentence << endl;

    return 0;
}

int strLength(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int countVowels(char s[]) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}

void toUpperCase(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
}