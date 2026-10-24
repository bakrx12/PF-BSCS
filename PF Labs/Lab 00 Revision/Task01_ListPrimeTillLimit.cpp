//prime numbers

#include<iostream>
using namespace std;

int main()
{
    int limit = 0;
    cout << "Enter limit: ";
    cin >> limit;

    if (limit < 2) 
    {
        cout << "No prime numbers.";
    }
    else 
    {
        cout << "Prime numbers: ";
        for (int i = 2; i <= limit; i++) 
        {
            bool isPrime = true;
            
            for (int j = 2; j * j <= i; j++) 
            {
                if (i % j == 0) 
                {
                    isPrime = false;
                    break; 
                }
            }
            
            if (isPrime) 
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}
