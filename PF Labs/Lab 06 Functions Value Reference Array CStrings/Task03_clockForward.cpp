#include <iostream>
#include <iomanip>
using namespace std;

void readTime(int &h, int &m, int &s);
int addSeconds(int &h, int &m, int &s, int extra);
void printTime(int h, int m, int s);

int main() {
    int h, m, s, extra;

    readTime(h, m, s);
    cout << "Seconds to add: ";
    cin >> extra;

    int midnights = addSeconds(h, m, s, extra);

    cout << "New time: ";
    printTime(h, m, s);
    cout << "Midnights crossed: " << midnights << endl;

    return 0;
}

void readTime(int &h, int &m, int &s) {
    cout << "Enter time (h m s): ";
    cin >> h >> m >> s;
}

int addSeconds(int &h, int &m, int &s, int extra) {
    long long totalSeconds = (long long)h * 3600 + m * 60 + s + extra;
    int midnightsCrossed = totalSeconds / 86400;

    int remainingSeconds = totalSeconds % 86400;
    h = remainingSeconds / 3600;
    remainingSeconds %= 3600;
    m = remainingSeconds / 60;
    s = remainingSeconds % 60;

    return midnightsCrossed;
}

void printTime(int h, int m, int s) {
    cout << setfill('0') << setw(2) << h << ":"
         << setw(2) << m << ":"
         << setw(2) << s << endl;
}