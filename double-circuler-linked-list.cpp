#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node *prev;
};



class list {
private:
node *head,*temp,*temp1;
public:
list();
~list();
void option();
void search();
void length();
void add();
void remove();
void print();
};

//constructer 
list :: list(){
head=temp=temp1=NULL;
}



// destructer 
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
cout<<"Avalible option : "<<endl;
cout<<"1) add "<<endl;
cout<<"2) remove "<<endl;
cout<<"3) print "<<endl;
cout<<"4) length "<<endl;
cout<<"5) search "<<endl;
cout<<"0) Exit ! "<<endl;
cout<<"Enter your choice : "<<endl;
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

default :
cout<<"Invalid choice :"<<endl;
     }
  }while(choice!=0);
}


void list :: print(){
temp=head;
if(head==NULL){
cout<<"No Element to print : "<<endl;
return;
}

do{
cout<<temp->info<<" ";
temp=temp->next;
}while(temp!=head);
cout<<endl;
}



void list :: length(){
temp=head;
int count=0;
do{
count++;
temp=temp->next;
}while(temp!=head);
cout<<"Length : "<<count<<endl;
}

void list :: search(){
temp=head;
if(head==NULL){
cout<<"No element to search : "<<endl;
return;
}

int key;
cout<<"Enter the key :"<<endl;
cin>>key;

do {
if(temp->info==key){
cout<<"Key Found : "<<endl;
return;
}
temp=temp->next;
}while(temp!=head);
cout<<"Key not found : "<<endl;
}


void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the value : "<<endl;
cin>>head->info;
head->next=head;
head->prev=head;
return;
}

while(temp->next!=head){
temp=temp->next;
}

temp1=new node;
cout<<"Enter the value "<<endl;
cin>>temp1->info;
temp1->next=head;
temp1->prev=head;
temp->next=temp1;
head->prev=temp1;
}


void list :: remove(){
temp=head;
if(head==NULL){
cout<<"No element to remove : "<<endl;
return;
}

int key;
cout<<"Enter the key to remove : "<<endl;
cin>>key;

if(head->info==key){
 if(head->next==head){
 delete head;
  head==NULL;
 return;
 }
 
while(temp->next!=head){
temp=temp->next;
}

temp1=head;
head=head->next;
temp->next=head;
head->prev=temp;
delete temp1;
return;
}


while(temp->next!=head){
 if(temp->next->info==key){
temp1=temp->next;
temp->prev=temp1;
delete temp1;
return;
  }
temp=temp->next;
}
cout<<"Ket not found : "<<endl;
}









int main(){
list obj;
obj.option();
return 0;
}
