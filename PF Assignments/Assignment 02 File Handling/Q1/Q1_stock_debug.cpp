/*
 * Name       : AbuBakr Aslam
 * Reg No     : L1F24BSCS0052
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream> //Fix 1: missing fstream header file
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (!inFile) {   //Fix 2: incorrectly prints error message when file is actually present 
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    //fix 3:
    //data is required to be kept so appending it
        ofstream reorder("reorder.txt", ios::app);

        // Fix 4: to skip the first line (not neededd)
        inFile.ignore(67, '\n');

        
    char code[10];
    int qty, count = 0, low = 0;
    double price; //since price is double here thatswhy 
    double total = 0; //Fix 5: using double if we need to print exact prices


    while (count < 50 && inFile >> code >> qty >> price) {

        count++;
        total = total + qty * price; 
        if (qty < 10) {
            reorder << code << " " << qty << endl; //Fix 6: adding endl
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
