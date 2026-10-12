#include<iostream>
using namespace std;
int main()
{
  /*stream object          operator used            usecase                                  
  cin                    >> (extraction)          takes input from user
  cout                   << (insertion)           displays output to user
  getline()                                       reads an entire line, including spaces
  cin.clear()                                     clears error state of cin
  cin.ignore()                                    discard character from input buffer         returns remaining used datatype values
  cin.fail()                                      checks weather stream failed                returns bool
  cin.good()                                      checks weather stream is in good state      returns bool
  cin.eof                                         checks weather end-of-input reached         returns bool 
  new / delete[]                                  create / delete allocated memory                              */

//EXAMPLE USECASES
  //user enters data like "10,20,30,40,50" instead of space / new line which automatically seperates

  int arr[5];

  for (int i = 0; i < 5; i++)
  {
      cin >> arr[i];
  
      if (i < 4)
          cin.ignore(1, ',');
  }

  //Letting the user specify the array size

  int size;

cout << "array size: ";
cin >> size;

int* arr = new int[size];
  for (int i = 0; i < size; i++)
{
    cin >> arr[i];
}

  
  
}
