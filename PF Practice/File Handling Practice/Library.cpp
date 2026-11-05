#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //create a file, open and read
    //get data from user

    char[20];
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


    //append file with new data from user


    //lab tasks practice
    return 0;


}