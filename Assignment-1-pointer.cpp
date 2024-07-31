/*
#include<iostream>
using namespace std;

void get(int size,int *ptr);
void update(int size,int value,int index,int *ptr);
void length(int size);
void back(int &currentindex,int size,int *ptr );
void start(int *ptr,int size,int currentindex);
void  end(int *ptr,int size,int currentindex);
void add(int &size,int *&ptr,int value);


int main(){
int size;
cout<<"Enter the size of an array :"<<endl;
cin>>size;

int *arr;
arr=new int(size);
int *ptr;
ptr=arr;
static int currentindex=0;

cout<<"Enter value in the array : "<<endl;
for(int i=0;i<size;i++){
cin>>arr[i];

}


int choice;

do{
cout<<"Operations on Data-Structures :"<<endl;
cout<<"1) GET() :"<<endl;
cout<<"2) UPDATE():"<<endl;
cout<<"3)LENGTH(): "<<endl;
cout<<"4) BACK():"<<endl;
cout<<"5) START():"<<endl;
cout<<"6) END():"<<endl;
cout<<"7)ADD(): "<<endl;
cout<<"0)EXIT(): "<<endl;
cout<<"Enter your choice :"<<endl;
cin>>choice;
int index,value,value3;
if(choice==1){
    get(size,ptr);
}

else if(choice==2){
cout<<"Enter the index : "<<endl;
cin>>index;
cout<<"Enter the value : "<<endl;
cin>>value;
update(size,value,index,ptr);
}

else if(choice==3){
length(size );
}

else if(choice==4){
back(currentindex,size,ptr );
}

else if(choice==5){
start(ptr,size,currentindex);
}

else if(choice==6){
end(ptr,size,currentindex);
}
else if(choice==7){
cout<<"Enter the value to add :"<<endl;
cin>>value3;
add(size,ptr,value3);
}


else if (choice==0){
break;
}

else {
cout<<"Invalid input : "<<endl;
}

}while(choice!=0);

delete arr;


return 0;
}


void length(int size){
cout<<"Length : "<<size<<endl;
}


void update(int size,int value,int index,int *ptr){
if(index<1 || index>size ){
cout<<"Not legal : "<<endl;
}
else {
*(ptr+index-1)=value;
cout<<"Updated Value  : "<<value<<endl;
}
}


void back(int &currentindex,int size,int *ptr  ){
if(currentindex<0){
cout<<"Not legal : "<<endl;
}
else {
currentindex--;
cout<<"Back : "<<*(ptr+currentindex)<<" "<<endl;
}
}


void get(int size,int *ptr,int currentindex){
cout<<"Elements in the array : "<<endl;
for(int i=0;i<size;i++){
cout<<(*ptr+currentindex)<<" ";
}
cout<<endl;
}

void start(int *ptr,int size,int currentindex){
if(size<=0){
cout<<"Array is empty  : "<<endl;
}
else{
cout<<"First element : "<<*ptr<<endl;
}
}

void  end(int *ptr,int size,int currentindex){

if(currentindex>size ){
cout<<"Not legal :"<<endl;
}
else {
cout<<"Last element : "<<*(ptr+size-1)<<endl;
}
}


void add(int &size, int *&ptr, int value) {
    int *newArr = new int[size + 1]; // Allocate new array with increased size
    for (int i = 0; i < size; i++) {
        newArr[i] = ptr[i]; // Copy elements from old array to new array
    }
    newArr[size] = value; // Add new value at the end
    delete[] ptr; // Delete old array
    ptr = newArr; // Update pointer to point to new array
    size++; // Increment size
    cout << "Added value: " << value << endl;
}

void remove(int &size,int *ptr,int idnex){
if(index<1 || index>size){
cout<<"Not legal : "<<endl;
}
else {
int *newArr=new int[size-1];
*/



#include<iostream>
using namespace std;


int main(){
int size;
cout<<"Enter the size of an array : "<<endl;
cin>>size;

int *arr;
arr=new int[size];
int *ptr;
ptr=arr;



cout<<"Enter the value in the array : "<<endl;
for(int i=0;i<size;i++){
cin>>arr[i];

}

cout<<"Elements in the array : "<<endl;
for(int i=0;i<size;i++){
cout<<(*ptr+i)<<" ";
}

int currentIndex=0;




return 0;
}


void length(int size){
cout<<"Length : "<<size<<endl;
}



void update(int size,int *ptr,int index,int value){
if(index>1  || index < size  ){
*(ptr+index)=value;
}
else {
cout<<"Not legal : "<<endl;
}
}

void back(int &currentIndex,int *ptr,int size ){
if(currentIndex<=0){
cout<<"Not lgeal : "<<endl;
}
else {
currentIndex--;
cout<<"Back element : "<<*(ptr+currentIndex)<<endl;
}
}

void add(int &size,int *&ptr,int value){
int *newArr=new int[size+1];

for(int i=0;i<size;i++){
newArr[i]=ptr[i];
}

newArr[size]=value;
delete[] ptr;
ptr=newArr;
size++;
cout<<"Added value : "<<value<<endl;
}


..