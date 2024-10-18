#include<iostream>
using namespace std;


struct node{
int info;
node *next;
node *prev;
};


class list{
private:
node *head,*temp,*temp1;
public:

list();
~list();
void option();
void add();
void remove();
void print();
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

head->next=NULL;
head->prev=NULL;
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
temp1->prev=temp;

}


void list :: remove(){
temp=head;

if(head==NULL){
cout<<"Empty List : "<<endl;
return;
}



int count=1;
int pos;
cout<<"Enter the pos : "<<endl;
cin>>pos;

if(pos==1){
temp1=temp;
head=head->next;
head->prev=NULL;
delete temp1;
return;
}


while(temp!=NULL){
      if(count==pos){

temp1=temp;
if(temp->next!=NULL){
temp->next->prev=temp->prev;
}

if(temp->prev!=NULL){
temp->prev->next=temp->next;
}
delete temp1;
return;
}

count++;
temp=temp->next;
}
cout<<"Invalid position : "<<endl;
}




void list :: print(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


while(temp!=NULL){
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
