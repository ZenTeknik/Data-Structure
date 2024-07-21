#include<iostream>
using namespace std;

struct node{
int info;
node * next;
};

class list{
private:
node *head,*temp,*temp1;

public:
list();
~list();
void option();
void print();
void remove();
void search();
void length();
void add();
};




// constructer 
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


void list :: option(){
int choice;

do{
cout<<"SELECT ANY ONE OPTION : "<<endl;
cout<<"1) ADD :"<<endl;
cout<<"2) DELETE  :"<<endl;
cout<<"3) PRINT  :"<<endl;
cout<<"4)  SEARCH      :"<<endl;
cout<<"5) LENGTH  :"<<endl;
cout<<"0) EXIT:"<<endl;
cout<<"ENTER YOUR CHOICE :"<<endl;
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
      search();
}
else if(choice==5){
length();
}
else if(choice==0){
break ;
}
else {
cout<<"Invalid Option : "<<endl;
}

}while(choice!=0);


}



// print function 
void list :: print(){
head=temp;
if(head==NULL){
cout<<"No elements to print : "<<endl;
return;
}
else{
cout<<"Elements in the linked list"<<endl;
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}
}


void list :: search(){
head=temp;
if(head==NULL){
cout<<"No element in linked list  : "<<endl;
}
else{
while(temp!=NULL){
if(temp->info==key){
cout<<"Element found : "<<endl;
}
else{
cout<<"Element Not Found :"<<endl;
      }
      temp=temp->next;
    }
  }
}



void list :: length(){
head=temp;
int count;
while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"Length : "<<count<<endl;
}


// add function 
void list :: add(){
head=temp;
if(head==NULL){
head=new node;

cout<<"Enter the new element :"<<endl;
cin>>head->info;
head->next=NULL;
}

else{
temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp1=new node;
cout<<"Enter the element : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;


}
}


// remove function 
void list :: remove(){
temp=head;
if(head==NULL){
cout<<"No elements to rmeove : "<<endl;
}
else{
cout<<"Enter the elements  to remove : "<<endl;
cin>>key;

if(head==key){
temp1=head;
head=head->next;
delete temp1;
return;
}

temp=head;
while(temp!=NULL){
if(temp->info==key){
temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
return;
}
temp=temp->next;
}
}
}








int main(){


return 0;
}

