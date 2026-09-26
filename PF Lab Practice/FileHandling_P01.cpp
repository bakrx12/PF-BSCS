// practice for inital week of pragramming fundamentals lab

/*
  preprocessor directives / library headers:
  used in standard c/c++ program to direct to actual library files of used header
  common c/c++ headers: iostream, fstream, string, set, map, vector, math, cstdio
  By including header (i.e, iostream) we can use it's pre-defined objects (cin/out) from it's classess
  header's objects are categorized by their stream type (i.e, input/output/log/error)
*/


#include<iostream> // contains 8 standard stream classess

//stream type           class                  objects (global / harcodded to c/c++)

//input                 istream                cin, wcin
//output                ostream                cout, wcout

#include<fstream> // contains 3 strem classes/objects file stream used for filehandling
//inherited from iostream, extraction (<<) /insertion (>>) operators can be used with it

//stream type           class                  objects (user defined identifiers)          actions
//input                 ifsteam               (common example: fin/read)                   .open("filename") , .is_open() , .close() , get() , .getline()
//output                ofstream              (common example: fout/write)                 .put() , .write() , tellp() , seekp()             

using namespace std;

int main()
{
  //to check if a file exist
      //if already present in program's directory, just write filename
      //to read file in another directory we have to provide file's path using escape sequence
      //Either directly, or store path in variable and then use it in action

      //METHOD 1: by using .open
      ifstream check;
      check.open("File1.txt");
    
      //METHOD 2: directly passing filename along with identifier of ifstream
      ifstream check("File1.txt");

  if (check.is_open)
  {
    cout << "\nFile1.txt exists";
  }

  check.close();

  //to write into a file
        //persuming already present in program's directory
  
  ofstream txt("Text1.txt");
  txt << "123";
  txt.close();

  //to read a file (only one line) into console
  int x;
  ifstream read("Text1.txt");
  read >> x;
  cout << x << endl;

  //to read file and write it into another file (only one line)
      //persuming both files already exist in directory albiet empty
  ifstream read("Text1.txt");
  int reader;
  ostream write("Text2.txt");
  read >> reader;
  write << reader << endl;

  
}
