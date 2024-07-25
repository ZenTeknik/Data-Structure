/*

#include<iostream>
using namespace std;

struct node {
int info;
node *next;
};



class list {
private: 
node *top,*temp;
int count;
const int limit=10;
public: 
list();
~list();
void option();
void push();
void pop();
void print();
};


// constructer 
list :: list(){
int count=0;
int limit;
top=temp=NULL;
}

list :: ~list(){
temp=top;
while(top!=NULL){
top=top->next;
delete temp;
}
}


void list :: option(){
int choice;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) push    : "<<endl;
cout<<"2) Pop     : "<<endl;
cout<<"3) Print   : "<<endl;
cout<<"0) Exit    : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

switch(choice){
case 1: 
push();
break;


case 2: 
pop();
break;

case 3: 
print();
break;

case 0: 

break;
default:
cout<<"Invalid choice : "<<endl;
}
}while(choice!=0);
}


// fucntion for adding element into the stack like in top-up position not like array 
// & in stack we have LIFO (last in first out) 
void list :: push(){
top=temp;
if(top==NULL){
top=new node;
cout<<"Enter the value in the stack : "<<endl;
cin>>top->info;
top->next=NULL;
count++;
return;
}

if(count<=limit){

temp=new node;
cout<<"Enter the value in the stack : "<<endl;
cin>>temp->info;
temp->next=top;
top->next=NULL;
top=temp;
return;
}
}

// function for removing the element from the stack 
void list :: pop(){


if(top==NULL){
cout<<"No Element in the stack : "<<endl;
return;
}
temp=top;
top=top->next;
delete temp;
count--;
return ;
}


// fucntion for printing the element in the stack
void list :: print(){
temp=top;

while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}







// main 
int main(){
list obj;
obj.option();
  
return 0;
}



*/


#include<iostream>
using namespace std;

struct node{
int info;
node  *next;
};


class list{
private:
node *temp,*top;
int count;
int limit;
public : 



}

int main(){


return 0;
}


