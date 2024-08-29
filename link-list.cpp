#include<iostream>
using namespace std;

struct node{
int info;
node *next;
};


class list {
private:
node *head,*temp,*temp1;
public:

// all the function here
list();
~list();
void option();
void insert();
void remove();
void search();
void display();
void max();
void min();
};

// constructer 
list ::  list(){
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


// defination for the list option 
void list :: option(){
int choice;
do{
cout<<"Avalible Choices : "<<endl;
cout<<"1) Insert :"<<endl;
cout<<"2) Remove : "<<endl;
cout<<"3) Search : "<<endl;
cout<<"4) Maximum : "<<endl;
cout<<"5) Minimum : "<<endl;
cout<<"6) Display : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
insert();
}

else if(choice==2){
remove();
}
else if(choice==3){
search();
}
else if(choice==4){
max();
}
else if(choice==5){
min();
}
else if(choice==6){
display();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}
}while(choice!=0);
}



// defination for the insettion
void list :: insert(){
temp=head;
if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;
head->next=NULL;
}

head=temp;
while(temp->next!=NULL){
temp=temp->next;
}
temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
}


// defination for the searching 
void list :: search(){
head=temp;

if(head==NULL){
cout<<"No element in the list : "<<endl;
return;
}

int key;
cout<<"Enter the key to find : "<<endl;
cin>>key;

while(temp->next!=NULL){
   if(temp->info==key){
cout<<"Key Found : "<<endl;
}
temp=temp->next;
}
cout<<"Not found : "<<endl;
}


// defination for the display
void list :: display(){
temp=head;

if(head==NULL){
cout<<"No element in the list : "<<endl;
return;
}

while(temp->next!=NULL){
 cout<<temp->info<<" ";
 temp=temp->next;
 }
}

// defiantion for finding the max 
void list :: max(){
temp=head;
if(head==NULL){
cout<<"No element in the list : "<<endl;
return;
}

int max=0;
while(temp->next!=NULL){
   if(temp->info>max){
  max=temp->info;
}
}
cout<<"Maximum value : "<<max<<endl;
}


//defination for finding  the minimum value 
void list :: min(){
temp=head;
if(head==NULL){
cout<<"No element in the list : "<<endl;
return;
}

int min=0;
while(temp->next!=NULL){
   if(temp->info<min){
  min=temp->info;
}
}
cout<<"Minimum value : "<<min<<endl;
}



// definaiton for the removing element 
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
temp1=head;
head=head->next;
delete temp1;
return;
}


while(temp->next!=NULL){
   if(temp->info==key){
 temp1=temp->next;
 temp->next=temp->next->next;
 delete temp1;
 return;
 }
 temp=temp->next;
 }
}




int main(){
list obj;
obj.option();

return 0;
}
