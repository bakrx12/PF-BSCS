#include <iostream>
using namespace std;

int readList(int arr[], int capacity);
void printList(int arr[], int used);
void reverseList(int arr[], int used);
int findValue(int arr[], int used, int key);

int main() {
    const int CAPACITY = 20;
    int arr[CAPACITY];

    int used = readList(arr, CAPACITY);
    cout << "Stored " << used << " values: ";
    printList(arr, used);
    cout << endl;
    reverseList(arr, used);
    cout << "Reversed: ";
    printList(arr, used);
    cout << endl;

    int key;
    cout << "Search for: ";
    cin >> key;

    int index = findValue(arr, used, key);
    if (index != -1) {
        cout << key << " found at index " << index << "." << endl;
    } else {
        cout << key << " not found." << endl;
    }

    return 0;
}

int readList(int arr[], int capacity) {
    cout << "Enter values (-1 to stop): ";
    int count = 0;
    int val;
    while (count < capacity && cin >> val && val != -1) {
        arr[count] = val;
        count++;
    }
    return count;
}

void printList(int arr[], int used) {
    for (int i = 0; i < used; i++) {
        cout << arr[i] << " ";
    }
}

void reverseList(int arr[], int used) {
    int start = 0;
    int end = used - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int findValue(int arr[], int used, int key) {
    for (int i = 0; i < used; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}