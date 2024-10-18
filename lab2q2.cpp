#include <iostream>
using namespace std;

// function prototypes
bool palindrome(char *ptr, int size);
void frequency(char *ptr, int size);

int main() {
    int size=6;
    char arr[size];
    char *ptr=arr;

    cout<<"Enter the characters in the array: "<<endl;
    for(int i=0;i<size;i++) {
        cin>>*ptr;
        ptr++;
    }

    ptr=arr;  

    cout<<"String: ";
    for (int i = 0; i < size; i++) {
        cout << *ptr;
        ptr++;
    }
    cout << endl;

    int choice;
    do {
        cout <<"1)Check palindrome"<<endl;
        cout << "2) Frequency"<<endl;
        cout << "0) Exit" <<endl;
        cout <<"Enter your choice: ";
        cin >>choice;

        ptr=arr;  // Reset pointer before each operation

        if (choice==1) {
            if (palindrome(ptr, size)) {
                cout<< "Palindrome" <<endl;
            } else {
                cout << "Not a palindrome" << endl;
            }
        } else if(choice==2) {
            frequency(ptr, size);
        } else if(choice==0) {
            break;
        } else {
            cout<<"Invalid Choice"<< endl;
        }
    } while (choice!=0);

    return 0;
}

// Function for checking if the string is a palindrome
bool palindrome(char *ptr, int size) {
    char *start=ptr;
    char *end=ptr+size-1;

    while (start<end) {
        if (*start!=*end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}



// Function for finding the frequency of a character
void frequency(char *ptr, int size) {
    int count=0;
    char key;

    cout<<"Enter the character to check the frequency: ";
    cin>>key;

    for (int i =0;i< size;i++){
        if (*ptr==key){
            count++;
            }
        ptr++;
    }

    if (count>0) {
        cout<<"The frequency of '"<< key<< " is:"<<count<<endl;
    } else {
        cout<<"Character not found"<<endl;
    }
}

