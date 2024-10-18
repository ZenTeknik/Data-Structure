#include<iostream>
using namespace std;

struct node{
int  info;
node *next;
node * prev;
};

class list {
private:
node *head,*temp,*temp1,*lastnode,*fast,*slow,*mid;
public:
list();
~list();
void option();
void add();
void print();
void reverseprint();
bool pal();
void duplicate();
};


list :: list(){
head=temp=temp1=lastnode=NULL;
}


list :: ~list(){
temp=head;
while(temp!=NULL){
temp1=temp;
temp=temp->next;
delete temp1;
}
}




void list :: option(){
int choice;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) add  :  "<<endl;
cout<<"2) print :  "<<endl;
cout<<"3) reverse print : "<<endl;
cout<<"4) Pal :       "<<endl;
cout<<"5) Duplicate  : "<<endl;
cout<<"0) EXIT : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
add();
}
else if(choice==2){
print();
}
else if(choice==3){
reverseprint();
}
else if(choice==4){
if(pal()){
   cout<<"This is a palindrome : "<<endl;
   }
   else{
   cout<<"Not a palindrome : "<<endl;
   }
   
}
else if(choice==5){
duplicate();
}
else if(choice==0){
break;
}
else{
cout<<"Invalid Option : "<<endl;
}

}while(choice!=0);
}

void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the info  :"<<endl;
cin>>head->info;
head->next=NULL;
head->prev=NULL;
lastnode=head;
return;
}

while( temp->next!=NULL){
temp=temp->next;
}


temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;

temp1->next=NULL;
temp1->prev=temp;
temp->next=temp1;
lastnode=temp1;
}



void list :: print(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}
while(temp!=NULL){
cout<<temp->info<<"  ";
temp=temp->next;
}
cout<<endl;
}




void list :: reverseprint(){

if(lastnode==NULL){
cout<<"Empty list : "<<endl;
return;
}

temp=lastnode;
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->prev;
}
cout<<endl;
}



bool list :: pal(){
temp=head;

if(head==NULL){
cout<<"Empty List : "<<endl;
return  false;
}

node *left=head;
node *right=lastnode;

while(left!=NULL && right!=NULL){
if(left->info!=right->info){
return false;
}
else{
left=left->next;
right=right->prev;
return true;
}
}
}




void list::duplicate() {
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


while(temp!=NULL && temp->next!=NULL){
   temp1=temp;
      while(temp1->next!=NULL){
  if(temp->info==temp1->next->info){
           fast=temp1->next;
       temp1->next=temp1->next->next;
       delete fast;
}
else{
temp1=temp1->next;
}
}
temp=temp->next;
}
print();
}


int main(){
list obj;
obj.option();


}
