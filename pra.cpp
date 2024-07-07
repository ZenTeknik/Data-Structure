#include<iostream>
using namespace std;


struct node{
int info;
node *next;
};


class list{
private: 
node *head;
node *temp,*temp1;

public: 
list();
~list();
void option();
void add();
void print();
void remove();
void even();
void odd();
void length();
void search();
};

// contructer 
list :: list(){
head=temp=temp1=NULL;
}


// destructer 
list :: ~list(){
head=temp;
while(temp!=NULL){
temp1=temp;
temp=temp->next;
delete temp1;
}
}


// function for option 
void list :: option(){

int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1) print "<<endl;
cout<<"2) add  "<<endl;
cout<<"3) remove  "<<endl;
cout<<"4) even  "<<endl;
cout<<"5) odd "<<endl;
cout<<"6) search  "<<endl;
cout<<"7) length "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
   print();
}
else if(choice==2){
  add();
}
else if(choice==3){
remove();
}
else if(choice==4){
even();
}
else if(choice==5){
odd();
}
else if(choice==6){
search();
}
else if(choice==7){
length();
}
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);

}



// function for print function 
void list :: print(){
temp=head;
if(head==NULL){
cout<<"No Elements to print : "<<endl;
return;
}
else {
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
}
}


// function for odd function 
void  list :: odd(){
temp=head;
if(head==NULL){
cout<<"No elemnts to find to print odd number  : "<<endl;
return;
}

while(temp!=NULL){
if(temp->info%2!=0){
cout<<"odd number "<<temp->info<<endl;
}
temp=temp->next;
}
cout<<"No odd number : "<<endl;
}


// function for search even 
void list :: even(){
temp=head;
if(head==NULL){
cout<<"No element to find even number : "<<endl;
return;
}


while(temp!=NULL){
if(temp->info%2==0){
cout<<"Even number : "<<temp->info<<endl;
}
else{
cout<<"No even number :"<<endl;
}
temp=temp->next;
}
}


// function to search 
void list :: search(){
int key;
int count=0;
temp=head;
if(head==NULL){
cout<<"No element to search : "<<endl;
return;
}
cout<<"Enter the element to search : "<<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){
cout<<"Element found "<<endl;
count++;
}
else{
cout<<"Not found : "<<endl;
}
temp=temp->next;
}

cout<<"Element found "<<count<<" times "<<endl;
}


// function to add
void list :: add(){
temp=head;
if(head==NULL){
head=new node;

cout<<"Enter element : "<<endl;
cin>>head->info;
head->next=NULL;
}
else {
while(temp->next!=NULL){
temp=temp->next;
}

temp1=new node;
cout<<"Enter the elemnet u wannt to add  : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
}
cout<<endl;
}


// function to remove 
void list :: remove(){
int key;
temp=head;
if(head==NULL){
cout<<"No element to remove : "<<endl;
return;
}

cout<<"Enter the element to remove : "<<endl;
cin>>key; 

int count=0;
temp=head;
while(temp!=NULL){
if(temp->info==key){
count++;
temp=temp->next;
}
}
cout<<key<<" "<<count<<" times which one i have to delete : "<<endl;



if(head->info==key){
temp1=head;
head=head->next;
delete temp1;
}

temp=head;
while(temp!=NULL){
if(temp->info==key){
temp1=temp->next;
temp->next=temp1->next->next;
delete temp1;
return ;
}
temp=temp->next;
}
}


// fucntion for length 
void list :: length(){
temp=head;
int count=0;
while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"lenght : "<<count<<endl;
}



int main(){
list my;
my.option();

return 0;
}

