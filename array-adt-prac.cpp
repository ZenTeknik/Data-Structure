




#include<iostream>
using namespace std;




// fucntion prototypes 
void option(int &size,int *arr);
void  add(int size,int *arr);
int search(int size,int *arr);
void length(int size);
int  max(int size,int *arr);
int  min(int size,int *arr);
void insert(int &size,int *&arr);
int  remove(int &size,int *&arr);


int main(){

int size;
int *arr;
arr=new int[size];
 
cout<<"Enter the size of an array : "<<endl;
cin>>size;
if(size<=0){
cout<<"U enter invalid size : "<<endl;
return 0;
}

add(size,arr);

option(size,arr);


delete[] arr;

return 0;
}


                            // function for options 
void option(int &size,int *arr){
int choice;

do{
cout<<"Avalible Options : "<<endl;
cout<<"1) search  : "<<endl;
cout<<"2) remove   : "<<endl;
cout<<"3) maximum  : "<<endl;
cout<<"4) minimum  : "<<endl;
cout<<"5) length   : "<<endl;
cout<<"6) insert  : "<<endl; 
cout<<"0) Exit   : "<<endl;

cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
search(size,arr);
}


else if(choice==2){
remove(size,arr);
}

else if(choice==3){
max(size,arr);
}

else if(choice==4){
min(size,arr);
}

else if(choice==5){
length(size);
}


else if(choice==6){
insert(size,arr);
}


else if(choice==0){
break;
}

else {
cout<<"Invalid choice : "<<endl;
}
}while(choice!=0);
}



// fucntion for adding element in the array 
void  add(int size,int *arr){

cout<<"Enter element in the array : "<<endl;
for(int i=0;i<size;i++){
cin>>arr[i];
}
}



 
 
                      // fucntion for searching element 
int  search(int size,int *arr){
int key;

if(size==0){
cout<<"No element in the array : "<<endl;
}

cout<<"Enter the key u wanna find : "<<endl;
cin>>key;

for(int i=0;i<size;i++){
 if(key==arr[i]){
 cout<<"Key Found : "<<endl;
return i;
}
}
cout<<"Not  Found : "<<endl;
return -1;


}





// function for the finding the length 
void length(int size){
cout<<"Length  : "<<size<<endl;
}





                    // function for finding the maximum  
int  max(int size,int *arr){

if(size==0){
cout<<"No elements to find the maximum : "<<endl;
return 0;
}


int max=arr[0];

for(int i=1;i<size;i++){
if(arr[i]>max){
max=arr[i];
}
}
cout<<"Maximum Number  : "<<max<<endl;
return 0;
}


                    // fucntion for finding the minimum
int min(int size,int *arr){
int min=arr[0];

for(int i=1;i<size;i++){
if(arr[i]<min){
min=arr[i];
}
}
cout<<"Minimum Number : "<<min<<endl;

return 0;
}




// function for adding element 
void insert(int &size,int *&arr){
int key;
cout<<"Elements in the array : "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}

cout<<"Enter the elemet  u wanna insert : "<<endl;
cin>>key;

int *newArr;
newArr=new int[size+1];

for(int i=0;i<size;i++){
newArr[i]=arr[i];
}

newArr[size]=key;
size++;
delete[] arr;
arr=newArr;

cout<<"Array with the new insert  element : "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}




// fucntion for removing element  
int  remove(int &size,int *&arr){

if(size==0){
cout<<"No elements to find the maximum : "<<endl;
return 0;
}


cout<<"Elements in the array : "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
cout<<endl;

int key;
cout<<"Enter the element you wanna remove : "<<endl;
cin>>key;

int i;
int *newArr;
newArr=new int[size-1];

for( i=0;i<size;i++){
newArr[i]=arr[i];
}

newArr[i]=key;
size--;
delete[] arr;
arr=newArr;

cout<<"Elements in the array after removing : "<<endl;
for(int i=0;i<size;i++){
cout<<newArr[i]<<" ";
}
cout<<endl;

return 0;
}




