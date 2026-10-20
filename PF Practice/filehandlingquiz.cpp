#include<iostream>
#include<fstream>
int main() {
    ifstream readLib("library.txt");
    if (!readLib) {
        cout << "Cannot open library.txt";
    }

    //reading size of loop
    int limit = 0;
    for (int i = 0; i < 1; i++) {
        readLib >> limit;
    }

    for (int i = 0 )



    readLib.close();
}