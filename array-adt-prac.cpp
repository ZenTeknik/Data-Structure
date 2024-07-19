#include<iostream>
using namespace std;

// fucntion prototypes 
void option();
void  add(int size,int *arr);
void search(int size,int *arr);
void length(int size);
void max(int size,int *arr);
void min(int size,int *arr);
void insert(int size,int *arr);
void remove(int size,int *arr);


int main(){

int size;
int *arr;
arr=new int[size];

cout<<"Enter the size of an array : "<<endl;
cin>>size;

option();


delete[] arr;

return 0;
}


                            // function for options 
void option(){
int choice;

do{
cout<<"Avalible Options : "<<endl;
cout<<"1) search  : "<<endl;
cout<<"2) add   : "<<endl;
cout<<"3) remove   : "<<endl;
cout<<"4) maximum  : "<<endl;
cout<<"5) minimum  : "<<endl;
cout<<"6) length   : "<<endl;
cout<<"7) insert  : "<<endl; 
cout<<"0) Exit   : "<<endl;

cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
search(size,arr);
}

else if(choice==2){
add(size,arr);
}

else if(choice==3){
remove(size,arr);
}

else if(choice==4){
max(size,arr);
}

else if(choice==5){
min(size,arr);
}

else if(choice==6){
length(size);
}


else if(choice==7){
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
void search(int size,int *arr){
int key;
if(size==0){
cout<<"No element in  the array to seach : "<<endl;
return 0;
}

cout<<"Enter the key to search : "<<endl;
cin>>key;


for(int i=0;i<size;i++){
if(arr[i]==key){
return true;
 }
}

if(true){
cout<<"Element found : "<<endl;
}
else {
cout<<"Not found : "<<endl;
}

}


// function for the finding the length 
void length(int size){
cout<<"Length  : "<<size<<endl;
}





                    // function for finding the maximum  
void max(int size,int *arr){

if(size==0){
cout<<"No elements to find the maximum : "<<endl;
return 0;
}


int max=arr[0];

for(int i=0;i<size;i++){
if(arr[i]>max){
max=arr[i];
}
}
cout<<"Maximum Number  : "<<max<<endl;
}


                    // fucntion for finding the minimum
void min(int size,int *arr){
int min=arr[0];

for(int i=0;i<size;i++){
if(arr[i]<min){
min=arr[i];
}
}
cout<<"Minimum Number : "<<min<<endl;
}




// function for adding element 
void insert(int size,int *arr){

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

cout<<"Array with the new insert  element : "<<endl;
for(int i=0;i<size;i++){
cout<<newArr[i]<<" ";
}
cout<<endl;
}




// fucntion for removing element  
void remove(int size,int *arr){

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

int *newArr;
newArr=new int[size-1];

for(int i=0;i<size;i++){
newArr[i]=arr[i];
}

newArr[i]=key;
size--;

cout<<"Elements in the array after removing : "<<endl;
for(int i=0;i<size;i++){
cout<<newArr[i]<<" ";
}
cout<<endl;
}




