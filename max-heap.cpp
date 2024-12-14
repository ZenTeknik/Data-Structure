#include <iostream>
using namespace std;

void insert(int A[], int n) {
    int i = n, temp;
    temp = A[i];

    while (i > 1 && temp > A[i / 2]) { // Compare with parent
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void display(int A[], int n) {
    for (int i = 1; i <= n; i++) { // Display the heap from index 1
        cout << A[i] << " ";
    }
    cout << endl;
}

int deleteNode(int A[], int &n) { // Pass n by reference to update size
    int i, j, temp, val;
    val = A[1];       // Extract the root value
    A[1] = A[n];      // Replace root with the last element
    n--;              // Reduce the size of the heap

    i = 1;
    j = 2 * i;

    while (j <= n) { // Ensure within bounds
        // Find the larger child
        if (j + 1 <= n && A[j + 1] > A[j]) {
            j = j + 1;
        }
        // Compare parent with the larger child
        if (A[i] < A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j; // Move down the heap
            j = 2 * i;
        } else {
            break;
        }
    }
    return val; // Return the deleted root value
}

int main() {
    int A[] = {0, 23, 12, 9, 6, 7, 5, 4, 3}; // Max-Heap array
    int n = 8; // Number of elements in the heap

    cout << "Before Insertion: ";
    display(A, n);

    insert(A, n); // Insert element at the last position (maintain heap property)
    cout << "After Insertion: ";
    display(A, n);

    cout << "Deleted Value: " << deleteNode(A, n) << endl; // Delete root node
    cout << "After Deletion: ";
    display(A, n);

    return 0;
}
