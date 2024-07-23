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
~list():
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

while(temp->next!=NULL){
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

}while(temp->next!=head);
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

while(temp->next!=head){
if(temp->info==key){
cout<<"Key Found : "<<endl;
return;
}
temp=temp->next;
}
cout<<"Key Not Found : "<<endl;
}


void list :: length(){
temp=head;
int count=0;
while(temp->next!=head){
count++;
temp=temp->next;
}
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
temp->next=temp1;
temp->next=temp->next->next;
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
temp1=temp;
head=head->next;
delete temp1;
return;
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



return 0;
}
