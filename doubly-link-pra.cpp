#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node * prev;
};


class list {
private: 
node * head;
node *temp,*temp1;

public: 
list();
~list();
void option();
void add();
void remove();
void print();
void length();
void search();
};


// constructer 
list :: list(){
head=temp=temp1=NULL;
}

// destructer 
list :: ~list(){
temp=head;
while(temp!=NULL){
temp1=temp;
temp=temp->next;
delete temp1;
}
}



// fucntion for display option 
void list :: option(){
int choice; 
do{
cout<<"AVALIBLE CHOICES : "<<endl;
cout<<"1) ADD : "<<endl;
cout<<"2) REMOVE : "<<endl;
cout<<"3) PRINT : "<<endl;
cout<<"4) LENGTH  : "<<endl;
cout<<"5) SEARCH  : "<<endl;
cout<<"0) EXIT : "<<endl;
cout<<" Enter your choice : "<<endl;
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
else if(choice==5){
search();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}


}while(choice!=0);
}


// fucntion for print values 
void list :: print(){
temp=head;
if(head==NULL){
cout<<"No element to print : "<<endl;
return;
}

while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
cout<<endl;
}


// function for length
void list :: length(){
temp=head;
int count=0;
while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"Length : "<<count<<endl;
cout<<endl;
}


// function for search 
void list :: search(){
temp=head;
int key;
int count=0;
int found=0;
if(head==NULL){
cout<<"No element to search : "<<endl;
return;
}


cout<<"Enter the element to search : "<<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){
found=1;
break;
}
temp=temp->next;
}

while(temp!=NULL){
if(temp->info==key){
count++;
}
temp=temp->next;
}

if(found){
cout<<"Key found : "<<count<<" times "<<endl;
}
else {
cout<<"Not found : "<<endl;
}
}



// fucntion for adding the element 
void  list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the element : "<<endl;
cin>>head->info;

head->next=NULL;
head->prev=NULL;
return;
}

while(temp->next!=NULL){
temp=temp->next;
}


temp1=new node;
cout<<"Enter the new element : "<<endl;
cin>>temp1->info;
temp->next=temp1;
temp1->prev=temp;

}


// function for removing the elements 
void list :: remove(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to remove : "<<endl;
return;
}


cout<<"Enter key to remove : "<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;

if(head!=NULL){
head->prev=NULL;
}
delete temp1;
return;
}

while(temp!=NULL){
if(temp->info==key){
temp1=temp;

if(temp->prev!=NULL){
temp->prev->next=temp->next;
}
if(temp->next!=NULL){
temp->next->prev=temp->prev;
}
delete temp1;
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
