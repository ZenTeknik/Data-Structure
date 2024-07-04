     // Linked List implementation 

#include<iostream> 
using namespace std;

struct node{
int info;
node *next;
};


class list {
private:
node *head;
node *temp,*temp1;
public:

 list();
 ~list();
void option();
void print();
void add();
void search();
void remove();
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
cout<<"Select Any One :"<<endl;
cout<<"1) print :"<<endl;
cout<<"2) add :"<<endl;
cout<<"3) remove :"<<endl;
cout<<"4) search :"<<endl;
cout<<"5) length  :"<<endl;
cout<<"0) EXIT :"<<endl;
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
 search();
 }

 else if(choice==5){
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


void list :: print(){
temp=head;
if(head==NULL){
cout<<"No element : "<<endl;
}
else{
while(temp!=NULL){
cout<<temp->info<<"  ";
temp=temp->next;
}
cout<<endl;
}
}

void list :: add(){
temp=head;
if(head==NULL){
head=new node;
cout<<"Enter the element :"<<endl;
cin>>head->info;
head->next=NULL;
}
else{
int key;
head=temp;
while(temp->next!=NULL){
temp=temp->next;
}
temp1=new node;
cout<<"Enter the element you want to add : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
}
}


void list :: search(){
int key;
temp=head;
if(head==NULL){
cout<<"Invalid search No element in the list : "<<endl;
}
else{
cout<<"Enter the element to search : "<<endl;
cin>>key;
while(temp!=NULL){
if(temp->info==key){
cout<<"Found : "<<endl;
return;
}

temp=temp->next;
}
cout<<"Not found : "<<endl;
}
}



void list :: remove(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to remove : "<<endl;
}
else{
cout<<"Enter the element you wannt to remove : "<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;
delete temp1;
return ;
}

temp=head;
while(temp!=NULL){
if(temp->info==key){
temp1=temp->next;
temp->next=temp1->next->next;
delete temp1;
return;
}
temp=temp->next;
}
}
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


int main(){

list obj;

obj.option();

return 0;
}
