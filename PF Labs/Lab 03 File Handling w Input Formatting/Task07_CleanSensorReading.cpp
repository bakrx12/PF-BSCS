#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream readSensor("sensor.txt");
    if (!readSensor)
    {
        cout << "sensor.txt not found!" << endl;
        return 1;
    }

    int count = 0, bad = 0, x;
    int total = 0;
    char junk[50];
    ofstream writeSensor("clean.txt");

    while (count < 20) 
    {
        if (readSensor >> x)
        {         
            if (x == -1)  // sentinel value pakri gyi
                break;
            writeSensor << x << endl;
            total = total + x;

            count++;
        }
        else if (readSensor.eof())
            break;
        else 
        {                             
            readSensor.clear();
            readSensor >> junk;
            bad++;
        }
    }
    readSensor.close();
    writeSensor.close();

    cout << "Valid readings: " << count << endl;
    cout << "Skipped: " << bad << endl;
    cout << "Average: " << (float) total / count << endl;
    return 0;
}
