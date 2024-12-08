#include <iostream>
using namespace std;

void add(int *arr, int size, int &current);
void display(int *arr, int current);
void maxsize(int size);
void curr(int current);
void search(int *arr, int current);
void isFull(int size, int current);
void isEmpty(int current);
void remove(int *arr, int &size, int &current);
void option(int *arr, int &size, int &current);

// Option function
void option(int *arr, int &size, int &current) {
    int choice;
    do {
        cout << "Available Options: " << endl;
        cout << "1) ADD " << endl;
        cout << "2) Display " << endl;
        cout << "3) Size " << endl;
        cout << "4) Current " << endl;
        cout << "5) Search " << endl;
        cout << "6) isFull " << endl;
        cout << "7) isEmpty " << endl;
        cout << "8) Remove " << endl;
        cout << "0) Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(arr, size, current);
                break;
            case 2:
                display(arr, current);
                break;
            case 3:
                maxsize(size);
                break;
            case 4:
                curr(current);
                break;
            case 5:
                search(arr, current);
                break;
            case 6:
                isFull(size, current);
                break;
            case 7:
                isEmpty(current);
                break;
            case 8:
                remove(arr, size, current);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

// Check if array is full
void isFull(int size, int current) {
    if (size == current) {
        cout << "Array is Full." << endl;
    } else {
        cout << "Array is not Full." << endl;
    }
}

// Check if array is empty
void isEmpty(int current) {
    if (current == 0) {
        cout << "Array is Empty." << endl;
    } else {
        cout << "Array is not Empty." << endl;
    }
}

// Add elements to the array
void add(int *arr, int size, int &current) {
    if (current >= size) {
        cout << "Array is Full." << endl;
        return;
    }
    cout << "Enter an element to add: ";
    cin >> arr[current];
    current++;
}

// Search for an element
void search(int *arr, int current) {
    if (current == 0) {
        cout << "Array is Empty." << endl;
        return;
    }
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    for (int i = 0; i < current; i++) {
        if (arr[i] == key) {
            cout << "Key exists at index " << i << "." << endl;
            return;
        }
    }
    cout << "Key does not exist." << endl;
}

// Display elements in the array
void display(int *arr, int current) {
    if (current == 0) {
        cout << "Array is Empty." << endl;
        return;
    }
    cout << "Elements in the array: ";
    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Find current size
void curr(int current) {
    cout << "Current size of the array: " << current << endl;
}

// Find maximum size
void maxsize(int size) {
    cout << "Maximum size of the array: " << size << endl;
}

// Remove an element from the array
void remove(int *arr, int &size, int &current) {
    if (current == 0) {
        cout << "Array is Empty." << endl;
        return;
    }
    int key;
    cout << "Enter the key to remove: ";
    cin >> key;

    int index = -1;
    for (int i = 0; i < current; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Key not found." << endl;
        return;
    }

    for (int i = index; i < current - 1; i++) {
        arr[i] = arr[i + 1];
    }
    current--;
    cout << "Key removed successfully." << endl;
}

// Main function
int main() {
    int current = 0;
    int size;
    int *arr;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Size is not valid!" << endl;
        return 0;
    }

    arr = new int[size];
    option(arr, size, current);
    delete[] arr;

    return 0;
}
