#include <iostream>
using namespace std;



struct node{
int info;
node * next;
};

class list {
private:
node *head,*temp,*temp1;

public:

list();
~list();
void option();
void length();
void add();
void remove();
void print();
void search();

};




list :: list(){
head=temp=temp1=NULL;
}

list :: ~list(){
temp=head;

if(head==NULL){
return;
}

while(temp->next!=head){
temp1=temp;
temp=temp->next;
delete temp1;
}
delete temp;
head=NULL;
}



void list :: option(){
int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1) add : "<<endl;
cout<<"2) remove : "<<endl;
cout<<"3) print  : "<<endl;
cout<<"4) length : "<<endl;
cout<<"5) search  : "<<endl;
cout<<"0) exit : "<<endl;
cout<<"Enter your choice  : "<<endl;
cin>>choice;

switch(choice){
case 1: 
add();

break;

case 2: 
remove();

break;
case 3: 
print();

break;
case 4: 
length();

break;
case 5: 
search();

break;
case 0: 

break;

default: 
cout<<"Invalid Choice : "<<endl;
}

}while(choice!=0);

}



void list :: print(){
temp=head;
if(head==NULL){
cout<<"No element to print : "<<endl;
return;
}

do{
cout<<temp->info<<" ";
temp=temp->next;
}while(temp!=head);
cout<<endl;
}


void list :: search(){
temp=head;

if(head==NULL){
cout<<"No element to search :"<<endl;
return;
}

int key;
cout<<"Enter the key u wanna search : "<<endl;
cin>>key;

do{
if(temp->info==key){
cout<<"Key Found : "<<endl;
return;
}
temp=temp->next;
}while(temp!=head);
cout<<"Key Not Found : "<<endl;
}


void list :: length(){
temp=head;
if(head==NULL){
cout<<"NO element in the link : "<<endl;
return;
}

int count=0;
do{
count++;
temp=temp->next;
}while(temp!=head);
cout<<"Length : "<<count<<endl;
}




void list :: add(){
temp=head;
if(head==NULL){
head=new node;
cout<<"Enter the value  : "<<endl;
cin>>head->info;
head->next=head;
return;
}

while(temp->next!=head){
temp=temp->next;
}


temp1=new node;
cout<<"Enter the value : "<<endl;
cin>>temp1->info;
temp1->next=head;
temp->next=temp1;
}


void list :: remove(){
temp=head;
if(head==NULL){
cout<<"No Element to remove : "<<endl;
return;
}

int key;
cout<<"Enter the elemet to remove : "<<endl;
cin>>key;

if(head->info==key){
 if(head->next==head){
 delete head;
 head==NULL;
 return;
 }
 
 else {
 temp=head;
 while(temp->next!=head){
 temp=temp->next;
 }
temp1=head;
head=head->next;
temp->next=head;
delete temp1;
return;
}
}




while(temp->next!=head){
if(temp->next->info==key){
temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
return;
}
temp=temp->next;
}
cout<<"Key not found : "<<endl;
}







int main(){

list obj;
obj.option();

return 0;
}
