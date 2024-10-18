#include<iostream>
using namespace std;



struct node{
int info;
node *next;
node *prev;
};


class list{
private:
node *head,*temp1,*temp;
public:
list();
~list();
void option();
void add();
void remove();
void print();
};



list :: list(){
head=temp1=temp=NULL;
}


list :: ~list(){
temp=head;
while(temp!=head){
temp1=temp;
temp=temp->next;
delete temp1;
}
}



void list :: option(){
int choice;
do{
cout<<"Avalible Optoin : "<<endl;
cout<<"1) add : "<<endl;
cout<<"2) remove : "<<endl;
cout<<"3) print : "<<endl;
cout<<"0) exit : "<<endl;
cout<<"Enter the choice : "<<endl;
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
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}
}while(choice!=0);
}


void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;
head->next=head;
return;
}

while(temp->next!=head){
temp=temp->next;
}



temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;
temp1->next=head;
temp->next=temp1;
}


void list :: remove(){
temp=head;
int count=1;
int  pos;


if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

cout<<"Enter the pos : "<<endl;
cin>>pos;


if(pos==1){
temp1=temp;
head=head->next;
delete temp1;
head=NULL;
return;
}



while(temp->next!=head){
      if(count==pos){
  temp->next=temp1;
temp->next->next=temp->next;
delete temp1;
return;
}
temp=temp->next;
count++;
}

cout<<"Invalid Position : "<<endl;
}



void list :: print(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

while(temp->next!=head){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}






int main(){
list obj;
obj.option();


return 0;
}
