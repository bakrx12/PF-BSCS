#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char path[100];
    char date[30];
    char item[30];
    char comma;

    int qty, items = 0;
    double price, subtotal = 0, discount = 0, total;

    cout << "Enter the path of the order file: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open())
    {
        cout << "Error: Cannot open order file!" << endl;
        return 1;
    }

    inFile.getline(date, 30);
    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream bill("bill.txt");

    if (!bill.is_open())
    {
        cout << "Error: Cannot create bill.txt!" << endl;
        return 1;
    }

    bill << "Bill for " << date << endl;

    while (items < 20 && inFile.getline(item, 30, ',') && inFile >> qty >> comma >> price)
    {
        double amount = qty * price;
        subtotal += amount;
        items++;

        // Calculate dollars and cents using basic int math
        int amountCents = (int)(amount * 100 + 0.5);
        int amountDollars = amountCents / 100;
        int amountRemCents = amountCents % 100;

        bill << item << " x " << qty << " = " << amountDollars << '.';
        if (amountRemCents < 10)
        {
            bill << '0';
        }
        bill << amountRemCents << endl;

        inFile.ignore(100, '\n');
    }

    if (items == 0)
    {
        cout << "No items found in the order file." << endl;
        return 1;
    }

    if (subtotal > 2000)
        discount = subtotal * 0.10;

    total = subtotal - discount;

    int subCents = (int)(subtotal * 100 + 0.5);
    int subDollars = subCents / 100;
    int subRemCents = subCents % 100;

    bill << "Subtotal: " << subDollars << '.';
    if (subRemCents < 10) bill << '0';
    bill << subRemCents << endl;

    int discCents = (int)(discount * 100 + 0.5);
    int discDollars = discCents / 100;
    int discRemCents = discCents % 100;

    bill << "Discount: " << discDollars << '.';
    if (discRemCents < 10) bill << '0';
    bill << discRemCents << endl;

    int totCents = (int)(total * 100 + 0.5);
    int totDollars = totCents / 100;
    int totRemCents = totCents % 100;

    bill << "Total: " << totDollars << '.';
    if (totRemCents < 10) bill << '0';
    bill << totRemCents << endl;

    bill.close();
    inFile.close();

    ofstream sales("daily_sales.txt", ios::app);

    if (!sales.is_open())
    {
        cout << "Error: Cannot open daily_sales.txt!" << endl;
        return 1;
    }

    sales << date << " " << totDollars << '.';
    if (totRemCents < 10) sales << '0';
    sales << totRemCents << endl;
    sales.close();

    cout << "Items: " << items << endl;
    
    cout << "Total to pay: " << totDollars << '.';
    if (totRemCents < 10) cout << '0';
    cout << totRemCents << endl;

    cout << "Bill saved to bill.txt" << endl;

    return 0;
}