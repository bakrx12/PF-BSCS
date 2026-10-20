/*
 * Name       : Student Name
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt");

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    int total = 0;

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
