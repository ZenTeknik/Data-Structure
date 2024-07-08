#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node *prev;
};


class list{
private:
node *head,*temp,*temp1;
public: 
list();
~list();
void option();
void add();
void remove();
void print();
void length();
};


list :: list(){
head=temp=temp1=NULL;
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
cout<<"AVALIBLE OPTION : "<<endl;
cout<<"1) add  "<<endl;
cout<<"2) remove  "<<endl;
cout<<"3) print  "<<endl;
cout<<"4) length "<<endl;
cout<<"Enter your choice  :  "<<endl;
cin>>choice;

if(choice==1){
add();
}
else if(choice==2){
remove();
}
else if(choice==3){
print();
}
else if(choice==4){
length();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid choice : "<<endl;
}
}while(choice!=0);
}


void list ::  print(){
temp=head;
if(head==NULL){
cout<<"No element to print : "<<endl;
}
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}


void list :: length(){
temp=head;
int count=0;
while(temp!=NULL){
count++;
temp=temp->next;
}

cout<<"Lenght : "<<count<<endl;
}

void list :: add(){
temp=head;
if(head==NULL){
head=new node;
cout<<"Enter the element in head : "<<endl;
cin>>head->info;
head->next=NULL;
//head->prev=NULL;
}


while(temp->next!=NULL){
temp=temp->next;
}


temp1=new node;
cout<<"Enter the element : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp1->prev=temp;
}

// function to remove 
void list :: remove(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to remove :"<<endl;
return;
}

cout<<"Enter the key to remove : "<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;
head->prev=NULL;
delete temp1;
}

while(temp!=NULL){
if(temp->info==key){
temp1=temp->prev;

if(temp->next!=NULL){
temp->prev->next=temp->next;
}
if(temp->next!=NULL){
temp->next->prev=temp->prev;
}
delete temp;
temp=temp1;

}
temp=temp->next;
}
}








int main(){

list my;
my.option();


return 0;
}
