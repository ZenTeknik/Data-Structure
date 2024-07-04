                        // Linked List implementation 
#include<iostream>

using namespace std;

struct  node{
int info;
node *next;
};

class list{
public:
node *head;
node *temp,*temp1;


list();
~list();
void option();
void print();
void search();
void add();
void remove();

};


// constructer defination 
list :: list(){
head=temp=temp1=NULL;
}

list :: ~ list(){
temp=head;
while(temp !=NULL){
temp1=temp;
temp=temp->next;
delete temp1;

}
}

void list :: option(){
int choice;
do{
cout<<"Select any one option ! "<<endl;
cout<<"1) PRINT   : "<<endl;
cout<<"2) ADD  : "<<endl;
cout<<"3) SEARCH    : "<<endl;
cout<<"4) REMOVE  : "<<endl;
cout<<"0) EXIT  : "<<endl;
cout<<"Enter your choice ! "<<endl;
cin>>choice;

if(choice==1){
         print();
}
          
else if(choice==2){
       add();
}

else if(choice==3){
          search();
}


else if(choice==4){
          remove();
}

else if(choice==0){
break;
}

else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);

}

// function for print all the value 
void list :: print(){
temp=head;
if(head==NULL){
cout<<"No value in this linked list : "<<endl;
}
else{
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}
}



// function for adding the value 
void list :: add(){
if(head==NULL){
head=new node;
cout<<"Enter the element : "<<endl;
cin>>head->info;
head->next=NULL;
}
temp=head;
int key;
 cout<<"Enter the key :"<<endl;
 cin>>key;
 while(temp!=NULL){
 if(temp->info==key){
// add code
temp1=new node;
cout<<"Enter the element to add  "<<endl;
cin>>temp1->info;
temp1->next=temp->next;
temp->next=temp1;
}
else {
cout<<"Not found : "<<endl;
}
temp=temp->next;

  }
 }


// function for search the value 
void list :: search(){
temp=head;
int key;
cout<<"Enter the key :"<<endl;
cin>>key;
while(temp!=NULL){

if(temp->info=key){
cout<<"Found :"<<endl;
}
else {
cout<<"Not found : "<<endl;
}
temp=temp->next;
}
}



// function for removing the value 
void list :: remove(){
temp=head;
int key;
cout<<"Enter the number u wannt to delete : "<<endl;
cin>>key;
if(head==NULL){
cout<<"No element to delete : "<<endl;
}
while(temp!=NULL){
if(temp->next->info==key){
// deletetion code here 
temp1=temp->next;
temp->next=temp1->next->next;
delete temp1;
}

temp=temp->next;
 }
}



int main(){

list obj;

obj.option();

return 0;
}



