#include<iostream>
using namespace std;

struct node {
int info;
node *next;
};



class list {
private: 
node *top,*temp;
public: 
list();
~list();
void option();
void push();
void pop();
};


// constructer 
list :: list(){
int count=0;
int limit=10;
top=temp=NULL;
}


void list :: option(){
int choice;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) push : "<<endl;
cout<<"2) Pop  : "<<endl;
cout<<"0) Exit : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

switch(choice){
case 1: 
push();
break;


case 2: 
pop();
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
temp=top;
temp=new node;
cout<<"Enter the value in the stack : "<<endl;
cin>>temp->info;
temp->next=NULL;
top->next=temp;
return;
}
}

// function for removing the element from the stack 
void list :: pop(){
top=temp;


}

int main(){


return 0;
}
