#include<iostream>
using namespace std;


class arraylist{
private:
int *current,*arrayhead,maxsize,listize;

public: 


// constructer 
arraylist(int val){
arrayhead=new int[val];
current=NULL;
listsize=0;
arraysize=val;
}

// destructer
~arraylist(){
delete[] arrayhead;
}


// function for start 
void start(){
current=arrayhead;
}

// function for end 
void end(){
current=arrayhead+listsize-1;
}


// function for the next 
bool next(){
    if(current=arrayhead+listsize-1){
return false;
}
else {
current--;
return true;
}
}

// function for the previous
bool back(){
 if(current=arrayhead){
return false;
}
else{
current--;
return true ;
}
}



//  function for the get size
int getsize(){
return listsize;
}

// function for max size
int maxsize(){
return maxsize;
}


// function for the isFull 
bool  isFull(){
  if(listsize>=maxsize){
return true;
}
else{
  return false;
}
}

// function for the isEmpty
bool isEmpty(){
   if(listsize==0){
return true;
 }
}


// void print 
void print(){
 
 current=arrayhead;
 if(listsize=0){
 cout<<"No element in the array list : "<<endl;
 return 0;
}
else {
   for(int i=0;i<listsize;i++){
  cout<<*curren<<" ";
  current++;
  }
}
}




// function for the seach 
void search(int val){
    if(listsize==0){
cout<<"No element in the array : "<<endl;
return;
}
else{
current=arrayhead;
   for(int i=0;i<listsize;i++){
     if(current==val){
   return val;
   }
   else {
  current++;
  }
  }
}
}



// function for removing 
bool remove(){
 if(isEmpty()){
return false;
}
else {
listsize--;
return true;
}
}


// function for finding the position 
int findpos(int pos){
    
    if(isEmpty()){
cout<<"No element in the array : "<<endl;
return 0;
}
else {current=arrrayhead+pos;
return *current;
}
}













};


int main(){



return 0;
}
