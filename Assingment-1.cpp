           // Assingment-1
           
#include<iostream>
using namespace std;
// prototypes
void length(int size );
void update(int size,int index,int arr[],int value );
void  back(int arr[],int size,int &currentIndex);
void start(int arr[],int size,int currentIndex);
void  end(int arr[],int size,int currentIndex);
void get(int size,int arr[]);
void add(int size,int &currentsize,int arr[],int value );

int main(){
int size,choice;
cout<<"Enter the size of an array : "<<endl;
cin>>size;

int arr[size];
int currentIndex=size-1;
int currentsize=0;

cout<<"Enter the elements in the array : "<<endl;
for(int i=0;i<size;i++){
cout<<"Index : "<<i+1<<endl;
cin>>arr[i];
}

do{
cout<<"Operations on Data-Structures :"<<endl;
cout<<"1) GET() :"<<endl;
cout<<"2) UPDATE():"<<endl;
cout<<"3)LENGTH(): "<<endl;
cout<<"4) BACK():"<<endl;
cout<<"5) START():"<<endl;
cout<<"6) END():"<<endl;
cout<<"7) ADD(): "<<endl;
cout<<"0)EXIT(): "<<endl;
cout<<"Enter your choice :"<<endl;
cin>>choice;
int index,value,value1;
if(choice==1){
   get(size,arr);
}

else if(choice==2){
cout<<"Enter the index : "<<endl;
cin>>index;
cout<<"Enter the value : "<<endl;
cin>>value;
update(size,index,arr,value );
}

else if(choice==3){
length(size );
}

else if(choice==4){
back(arr,size,currentIndex);
}

else if(choice==5){
start(arr,size,currentIndex);
}

else if(choice==6){
end(arr,size,currentIndex);
}

else if(choice==7){
cout<<"Enter the value u wanna add : "<<endl;
cin>>value1;
add(size,currentsize,arr,value1 );
}

else if (choice==0){
break;
}

else {
cout<<"Invalid input : "<<endl;
}

}while(choice!=0);

return 0;
}




void length(int size ){
cout<<"Lenght : "<<size<<endl;
}


void update(int size,int index,int arr[],int value ){
for(int i=0;i<size;i++){
if(size>0 && index<size){
arr[index-1]=value;

}
else {
cout<<"Array is empty : "<<endl;
}
}
cout<<"Updated index : "<<index<<" Value : "<<value<<endl;
}









void back(int arr[],int size,int &currentIndex){


if(currentIndex<=0){
cout<<"Not legal you can't go back :"<<endl;
}
else{
currentIndex--;
cout<<"Element : "<<arr[currentIndex]<<endl;
}
}






void start(int arr[],int size,int currentIndex){
if(currentIndex>size && currentIndex<0){
cout<<"Not legal : "<<endl;
}
else{
cout<<"First element : "<<arr[0]<<endl;
}
}


void  end(int arr[],int size,int currentIndex){

if(currentIndex>size ){
cout<<"Not legal :"<<endl;
}
else {
cout<<"Last element : "<<arr[size-1]<<endl;
}
}


void get(int size, int arr[]){
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
} 




void add(int size,int &currentsize,int arr[],int value ){
if(currentsize<size){
arr[size++]=value;
}
else{
cout<<"Array is full : "<<endl;
}
}




