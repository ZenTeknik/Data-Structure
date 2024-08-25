#include<iostream>
using namespace std;

// prototypes 
void create(int &size,int *&arr);
void add(int &size,int *arr);
void insert(int &size,int *&arr);
void remove(int &size,int *&arr);
void min(int &size,int *arr);
void max(int &size,int *arr);
void search(int &size,int *arr);
void option(int &size,int *&arr);
void next(int *&current, int *arr, int size);

int main(){
int size;
int *arr;

option(size,arr);

delete[] arr;
return 0;
}


// fucntion for creating the array 
void create(int &size,int *&arr){

cout<<"Enter the size of an array : "<<endl;
cin>>size;
if(size<=0){
cout<<"Not valid : "<<endl;
return;
}


arr=new int(size);
}

// fucntion for adding elements in the array 
void add(int &size,int *arr){
cout<<"Enter elements in the array :"<<endl;
for(int i=0;i<size;i++){
cin>>arr[i];
}

}

// fucntion for searching the elements in the array
void search(int &size,int *arr){
if(size<=0){
cout<<"Array is empty : "<<endl;
return;
}

int key;
cout<<"Enter the elements to search : "<<endl;
cin>>key;
int i;
for( i=0;i<size;i++){
if(arr[i]==key){
cout<<"Key Found at index : "<<i+1<<endl;
return ;
}
}
cout<<"Not Found : "<<endl;
}


// function for insert values 
void insert(int &size,int *&arr){

cout<<"Avalible elements in the array : "<<endl;
for(int i=0;i<size;i++){
 cout<<arr[i]<<" ";
 }
 
 int key;
 cout<<"Enter the element to insert : "<<endl;
 cin>>key;
 
 int *newArr;
 newArr=new int(size+1);
 
 for(int i=0;i<size;i++){
 newArr[i]=arr[i];
 }

newArr[size]=key;
size++;
delete[] arr;
arr=newArr;

cout<<"Array with insert element : "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" "<<endl;
}

}


// function for removing values from the array 
void remove(int &size,int *&arr){

cout<<"Avalible elements in the array : "<<endl;
for(int i=0;i<size;i++){
 cout<<arr[i]<<" ";
 }
 
 int key;
cout<<"Enter the key to remove : "<<endl;
cin>>key;
 
 int *newArr;
 newArr=new int(size-1);
 
 for(int i=0;i<size;i++){
 newArr[i]=arr[i];
 }

newArr[size]=key;
size--;
delete[] arr;
arr=newArr;

cout<<"Array with after removing the element  element : "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" "<<endl;
}

}

// function for the maximum element in the array 
void max(int &size,int *arr){
int max=arr[0];
for(int i=0;i<size;i++){
 if(arr[i]>max){
max=arr[i];
}
}
cout<<"Max element in the array : "<<max<<endl;
}


// function for the minimum energy 
void min(int &size,int *arr){
int min=arr[0];
for(int i=0;i<size;i++){
 if(arr[i]<min){
min=arr[i];
}
}
cout<<"Minimum element in the array : "<<min<<endl;
}

// fucntion for the next 
void next(int *&current, int *arr, int size) {
    if (current == nullptr) {
        // If the pointer hasn't been initialized or if the array is empty
        cout << "Array is empty or not initialized." << endl;
        return;
    }

    if (current < arr + size - 1) {
        current++;  // Move to the next element
        cout << "Current element: " << *current << endl;
    } else {
        cout << "Already at the last element of the array." << endl;
    }
}


// function for the option 
void option(int &size,int *&arr){

int choice;
int *current=NULL;  
do{
cout<<"1) create array : "<<endl;
cout<<"2) Add element : "<<endl;
cout<<"3) Insert :"<<endl;
cout<<"4) Remove : "<<endl;
cout<<"5) Minimum :"<<endl;
cout<<"6) Maximum :"<<endl;
cout<<"7) Search : "<<endl;
cout<<"8) Next : "<<endl;
cout<<"0) Exit  :"<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;
if(choice==1){
create(size,arr);
}

else if(choice==2){
add(size,arr);
}

else if(choice==3){
insert(size,arr);
}

else if(choice==4){
remove(size,arr);
}

else if(choice==5){
min(size,arr);
}

else if(choice==6){
max(size,arr);
}

else if(choice==7){
search(size,arr);
}

else if(choice==8){
next(current,arr,size);
}

else if(choice==0){
break;
}
else {
cout<<"Invalid choice : "<<endl;
}



}while(choice!=0);

}

