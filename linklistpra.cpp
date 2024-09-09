#include<iostream>
using namespace std;

struct node{
int info;
node *next;
};



class list{
private:
node *head,*temp,*temp1;
public:

list();
~list();
void option();
void search();
void add();
void remove();
void length();
void display();
void insert();
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
cout<<"Avalible option : "<<endl;
cout<<"1) add : "<<endl;
cout<<"2) remove : "<<endl;
cout<<"3) length : "<<endl;
cout<<"4) search : "<<endl;
cout<<"5) display : "<<endl;
cout<<"6) insert : "<<endl;
cout<<"0) EXIT : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;



if(choice==1){
add();
}
else if(choice==2){
remove();
}
else if(choice==3){
length();
}
else if(choice==4){
search();
}
else if(choice==5){
display();
}
else if(choice==6){
insert();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid choice :"<<endl;
}


}while(choice!=0);


}

void list  :: search(){
temp=head;
 if(temp==NULL){
cout<<"No element in the list : "<<endl;
return;
}

int key;
cout<<"Enter the key to seach : "<<endl;
cin>>key;

while(temp!=NULL){
   if(temp->info==key){
 cout<<"Key exixt : "<<endl;
return;
}
temp=temp->next;
}
cout<<"Key not exist : "<<endl;
}


void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;

head->next=NULL;
return;
}



while(temp->next!=NULL){
temp=temp->next;
}


temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;

temp1->next=NULL;
temp->next=temp1;

}




void list :: length(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int count=0;

while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<" Length : "<<count<<endl;
}



void list :: remove(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
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
   if(temp->next->info==key){
temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
return;
}
temp=temp->next;
}
}

void list :: display(){
temp=head;

if(head==NULL){
cout<<"No element in the list : "<<endl;
return;
}

while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}




void list :: insert(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int pos,count=1;
cout<<"Enter the position : "<<endl;
cin>>pos;


while(temp!=NULL){
    if(count==pos){
temp1=new node;
cout<<"Enter the info in new node : "<<endl;
cin>>temp1->info;
temp1->next=temp->next;
temp->next=temp1;
}
 count++;
temp=temp->next;
}
}










int main(){

list obj;
obj.option();


return 0;
}



