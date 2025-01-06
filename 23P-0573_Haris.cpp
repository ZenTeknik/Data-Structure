......<<<<<<< HEAD
#include<iostream>
=======
.#include<iostream>
>>>>>>> origin/main
using namespace std;


class list {
private:
int *arr;
int maxsize;
int currentSize;
int *currentpos;


public: 

// function prototypes
list(int size=100);     // Constructor with default parameter
~list();                 // Destructor
list(const list &other); // Copy constructor
list& operator=(const list &other);
void option(int *&arr);
void add(int key, int pos);
void remove(int key);
void option();
bool isFull();
bool isEmpty();
int listsize();
int maxlistSize();
int get();
void update(int pos, int val);
int length();
int back();
int next();
int start();
int end();
void clearlist();
};


// constructer
 list :: list(int size) : maxsize(size) ,currentSize(0) {
arr=new int[maxsize];
currentpos=arr;
}


// destructer
list :: ~list(){
delete[] arr;
}

// copy constructer
list :: list (const list & other){
maxsize=other.maxsize;
currentSize=other.currentSize;
arr=new int[maxsize];
currentpos=arr;


for(int i=0;i<currentSize;i++){
arr[i]=other.arr[i];
}
}


// assignment operator overload 
 list& list ::  operator=(const list &other){
   if(this==&other){
return *this;
}

delete[] arr;

maxsize=other.maxsize;
currentSize=other.currentSize;
arr=new int[maxsize];
currentpos=arr;

for(int i=0;i<currentSize;i++){
arr[i]=other.arr[i];
}
return *this;
}






// function for the option 
void  list :: option() {
    int choice, pos, val,key;
    do {
        cout << "Available Choices : " << endl;
        cout << "1)  IsFull       : " << endl;
        cout << "2)  IsEmpty      : " << endl;
        cout << "3)  List-size    : " << endl;
        cout << "4)  Max-list-size: " << endl;
        cout << "5)  Get          : " << endl;
        cout << "6)  Update       : " << endl;
        cout << "7)  Length       : " << endl;
        cout << "8)  Back         : " << endl;
        cout << "9)  Next         : " << endl;
        cout << "10) Start        : " << endl;
        cout << "11) End          : " << endl;
        cout << "12) Remove       : " << endl;
        cout << "13) Clear List   : " << endl;
        cout << "14) Add          : " << endl;
        cout << "0)  Exit         : " << endl;
        cout << "Enter Your choice: " << endl;
        cin >> choice;

        switch (choice) {
          case 1: 
                 if(isFull()){
          cout<<"Array is Full : "<<endl;
              }
          else{
           cout<<"Array is not Full :"<<endl;
           }
          break;
          
          case 2: 
             if(isEmpty()){
          cout<<"Array is Empty : "<<endl;
          }
          else {
        cout<<"Array is not Empty : "<<endl;
        }
          break;
          
          case 3: 
          cout<<"List size : "<<listsize()<<endl;
          
          break;
          
          case 4: 
           cout<<"Max list size is : "<<maxlistSize()<<endl;
          break;
          
          case 5: 
          cout<<"Current position : "<<get()<<endl;
          break;
          
          case 6: 
          cout<<"Enter the position  : "<<endl;
          cin>>pos;
          cout<<"Enter the value : "<<endl;
          cin>>val;
          update(pos, val);
          break;

         case 7: 
          cout<<"The current length of Array : "<<length()<<endl;
          break;
          
          case 8: 
           cout<<" Current key after  moving  Back : "<<back()<<endl;
          break;

          case 9: 
          cout<<" Current key after  moving  Next  : "<<next()<<endl;
          break;
          
          
          case 10: 
          cout<<" First element in the list : "<<start()<<endl;
          break;
          
         case 11: 
          cout<<" Last element in the list : "<<end()<<endl;
          break;

         case 12:
                cout << "Enter the value to remove: " << endl;
                cin >> key;
                remove( key);
        break;
        
        case 13:
                 clearlist();
        break;
        
       case 14:
                cout << "Enter the position: " << endl;
                cin >> pos;
                cout << "Enter the key: " << endl;
                cin >> key;
                add(key, pos);
      break;
      
      case 0:
      break;
      default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 0);
}

// Function for adding the element
void  list :: add( int key, int pos) {
    if (currentSize >= maxsize) {
        cout << "Array is full. Cannot add more elements." << endl;
        return;
    }

    if (pos < 0 || pos > currentSize) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = currentSize; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = key;
    currentSize++;

    cout << "Array after adding the element: " << endl;
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function for removing the element
void   list :: remove( int key) {
    if (currentSize <= 0) {
        cout << "Array list is empty." << endl;
        return;
    }

    int pos = -1;
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Element not found." << endl;
        return;
    }

    for (int i=pos;i<currentSize-1;i++) {
        arr[i]=arr[i+1];
    }

    currentSize--;

    cout<<"Array after removing the element: " << endl;
    for (int i=0;i<currentSize;i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}


// function for checking isFull or not
bool   list :: isFull() {
    return currentSize>=maxsize;
    }



// function for checking isEmpty or not 
bool  list ::  isEmpty(){
return currentSize==0;
}



// function for finding the list size
int  list :: listsize(){
return currentSize;
}



// function for finding the maxlist size
int  list :: maxlistSize(){
return maxsize;
}

// function for finding the current position 
int  list :: get(){
  if(currentpos==NULL || currentpos<arr  || currentpos>=arr+currentSize){
cout<<"Invalid positoin : "<<endl;
return -1;
}

return *currentpos;
}


// function for updating the value 
void  list ::  update(int pos, int val){
   if(pos<0 || pos>=currentSize ){
   cout<<"Invalid Position : "<<endl;
   return;
}
arr[pos]=val;

cout<<"Array-list after update new element :  "<<endl;
for(int i=0;i<currentSize;i++){
  cout<<arr[i]<<" ";
  }
cout<<endl;
}


// fucntion for finding the lenght 
int  list :: length(){
return currentSize;
}



// function for implemeting the back pointer 
int  list :: back(){
   if(currentpos>arr){
 currentpos--;
 }
else{
cout<<"U are at the start of the array : "<<endl;
}
return *currentpos;
}


// function for the next 
int  list :: next(){
   if(currentpos< arr+currentSize-1){
currentpos++;
}
else{
cout<<"You are at the end of list : "<<endl;
}
return  *currentpos;
}



// function for the start 
int  list :: start(){
  if(currentSize>0){
 currentpos=arr;
}
else{
cout<<" Empty List : "<<endl;
}
return 0;
}



// function for the end
int  list :: end() {
    if (currentSize>0) {
        currentpos=arr+currentSize-1;
        return *currentpos;
    } else {
        cout << "Empty List. "<<endl;
        return -1;
    }
  }



// function for clear all the list 
void  list :: clearlist(){
currentSize=0;
currentpos=NULL;

delete[] arr;

// create the new array after deleting the previous one 
arr=new int[maxsize];
}






// main function 
int main(){
list obj;
obj.option();

return 0;
}
