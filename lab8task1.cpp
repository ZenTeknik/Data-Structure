#include<iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

class queue {
private:
    node *head, *temp, *tail;

public:
    queue();
    ~queue();
    void option();
    void enqueue(int val);
    int dequeue();
    void necklace();
    void print();
};

// Constructor
queue::queue() {
    head = temp = tail = NULL;
}

// Destructor
queue::~queue() {
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Function for the option menu
void queue::option() {
    int choice, val;
    do {
        cout << "Available option :" << endl;
        cout << "1) Enqueue  : " << endl;
        cout << "2) Dequeue  : " << endl;
        cout << "3) Necklace : " << endl;
        cout << "4) Print : " << endl;
        cout << "0) exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value : " << endl;
            cin >> val;
            enqueue(val);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            necklace();
        }
        else if (choice == 4) {
            print();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice : " << endl;
        }
    } while (choice != 0);
}

// Function for adding an element
void queue::enqueue(int val) {
    node* newNode = new node;  
    newNode->info = val;
    newNode->next = NULL;

    if (head == NULL) {  
        head = tail = newNode;
    }
    else {  
        tail->next = newNode;
        tail = newNode;
    }
}

// Function for removing an element in the queue
int queue::dequeue() {
    if (head == NULL) {
        cout << "No element in the Queue : " << endl;
        return 0;
    }

    int dequeuedValue = head->info;  
    temp = head;
    head = head->next; 
    delete temp;  

    if (head == NULL) {  
        tail = NULL;
    }

    return dequeuedValue;  
}

void queue::print() {
    temp = head;
    if (temp == NULL) {
        cout << "No elements in the Queue : " << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function for modifying the necklace by rotating it k times
void queue::necklace() {
    temp = head;

    if (temp == NULL) {
        cout << "No element in the Queue : " << endl;
        return;
    }

    int k;
    cout << "Enter the value of K : " << endl;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int temp1 = dequeue();  // Dequeue the first element
        enqueue(temp1);  // Enqueue it back to the end
    }
    print();
}

int main() {
    queue obj;
    obj.option();
    return 0;
}

