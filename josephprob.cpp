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
void remove();
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
cout<<"2) remove :  "<<endl;
cout<<"3) print  : "<<endl;
cout<<"0) EXIT   : "<<endl;
cout<<"Enter your choice : "<<endl;
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
void list :: remove(){
node *current=head;
node *prev=NULL;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int k;
cout<<"Enter the k : "<<endl;
cin>>k;

while(listsize>1){
      
      for(int i=1;i<k;i++){
      prev=current;
      current=current->next;
}

cout<<"Removing nodes : "<<current->info<<endl;

if(current==head){
head=head->next;
}

prev->next=current->next;
delete current;
current=prev->next;
listsize--;
}
cout<<"Last node : "<<head->info<<endl;
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
