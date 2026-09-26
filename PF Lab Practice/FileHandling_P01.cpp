// practice for inital week of pragramming fundamentals lab

/*
  preprocessor directives / library headers:
  used in standard c/c++ program to include header files.
  Common c/c++ headers: iostream, fstream, string, set, map, vector, cmath, cstdio
  By including a header (i.e, iostream) we can use its pre-defined objects (cin/cout) from its classes
  header's objects are categorized by their stream type (i.e, input/output/log/error)
*/

#include<iostream> // contains 8 standard stream objects / templates for console input/output

//stream type           class                  objects (global / hardcoded to c/c++)
//input                 istream                cin, wcin
//output                ostream                cout, wcout

#include<fstream> // contains 3 stream classes for file handling
//inherited from iostream, extraction (>>) / insertion (<<) operators can be used with it

//stream type           class                  objects (user defined identifiers)          actions
//input                 ifstream              (common example: fin/read)                   .open("filename") , .is_open() , .close() , .get() , .getline()
//output                ofstream              (common example: fout/write)                 .put() , .write() , .tellp() , .seekp()             


using namespace std;

int main()
{
  //to check if a file exists
      //if already present in program's directory, just write filename
      //to read file in another directory we have to provide file's path using double backslashes or forward slashes
      //Either directly, or store path in variable and then use it in action

      // NOTE: You cannot declare 'check' twice in the same scope. 
      // Pick one method and comment out the other.

      //METHOD 1: by using .open
      // ifstream check;
      // check.open("File1.txt");
 
      //METHOD 2: directly passing filename along with identifier of ifstream
      ifstream check("File1.txt");

      if (check.is_open())
      {
        cout << "\nFile1.txt exists\n";
      }     

  //to write into a file
        //presuming already present in program's directory
  
  ofstream txt("Text1.txt");
  txt << "123";
  txt.close();

  //to read a file (only one line) into console
  int x;
  ifstream readFile1("Text1.txt"); //dont use read, as it's keyword as identifier, can use Read instead
  readFile1 >> x;
  cout << x << endl;
  readFile1.close(); // good practice to close before reusing

  //to read file and write it into another file (only one line)
      //persuming both files already exist in directory albiet empty
  ifstream readFile2("Text1.txt");
  int reader;
  ofstream write("Text2.txt"); 
  readFile2 >> reader;
  write << reader << endl;
  readFile2.close();  // good practice to close before reusing
  write.close();      // good practice to close before reusing

  //by default, ofstream wipes a file clean (truncates it) every time you open it.
  //reason for only getting one line previously when reading, no modes were used
  //Using ios::app allows you to append text to the very end of an existing file.

  //this is how we use modes:
  ofstream appendFile("Logbook.txt", ios::app);
    
    if (appendFile.is_open())
    {
        appendFile << "User logged in at 09:00 AM\n";
        appendFile << "User modified Profile Settings\n";
        appendFile.close(); // Always close to flush the buffer to disk
        cout << "Data appended successfully to Logbook.txt\n";
    }

  
}
