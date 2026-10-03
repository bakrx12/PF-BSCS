#include <iostream>
using namespace std;

int main() {
    int SIZE = 10;
    int velocities[SIZE];

    cout << "Input ten vertical velocities: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> velocities[i];
    }

    //clean ahh
    for (int i = 0; i < SIZE; i++) {
        velocities[i] = -velocities[i];
    }

    cout << "Updated Velocities: ";
    for (int i = 0; i < SIZE; i++) {
        cout << velocities[i] << " ";
    }
    cout << endl;

    return 0;
}