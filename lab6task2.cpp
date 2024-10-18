#include<iostream>
using namespace std;

struct node{
int  info;
node *next;
};

class list {
private:
node *head,*temp,*temp1;
int listsize=0;
public:
list();
~list();
void option();
void add();
void removeOdd();
void print();
};


list :: list(){
head=temp=temp1=NULL;
}


list :: ~list(){
temp=head;
do{
temp1=temp;
temp=temp->next;
delete temp1;
}while(temp!=head);
}





void list :: option(){
int choice;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) add    :  "<<endl;
cout<<"2) removeOdd :  "<<endl;
cout<<"3) print  : "<<endl;
cout<<"0) EXIT   : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
add();
}
else if(choice==2){
removeOdd();
}
else if(choice==3){
print();
}
else if(choice==0){
break;
}
else{
cout<<"Invalid Option : "<<endl;
}
}while(choice!=0);
}



// function for add 
void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;
head->next=head;
listsize++;
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
listsize++;
}










// function for removing the  node
void list :: removeOdd(){
temp=head;
int count=1;

while(temp->next!=head){
temp=temp->next;
}

node *last=temp;

temp=head;

if(count%2!=0){
  last->next=head->next;
  temp1=head;
  head=head->next;
  delete temp1;
  temp=head;
  count++;
}


while(temp->next!=head){
count++;

if(count%2!=0){
  temp1=temp->next;
  temp->next=temp->next->next;
  delete temp1;
}
else{
temp=temp->next;
}
}
print();
}






void list :: print(){


if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

temp=head;
do{
   cout<<temp->info<<" ";
   temp=temp->next;
   }while(temp!=head);
   cout<<endl;
}












int main(){
list obj;
obj.option();


}
