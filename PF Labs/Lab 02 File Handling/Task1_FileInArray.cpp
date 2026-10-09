#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int num[5];

	cout << "Enter 5 numbers: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}

	ofstream writeNum("numbers.txt");
	
		for (int i = 0; i < 5; i++)
		{
			writeNum << num[i] << endl;
		}

		writeNum.close();

		cout << "Numbers saved to numbers.txt";
}