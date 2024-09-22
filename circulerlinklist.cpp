#include<iostream>
using namespace std;

struct node{
int  info;
node *next;
};

class list {
private:
node *head,*temp,*temp1,*lastnode,*fast,*slow,*mid;
int listsize=0;
public:
list();
~list();
void option();
void add();
void remove();
void insert();
void search();
void print();
};


list :: list(){
head=temp=temp1=lastnode=NULL;
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
cout<<"1) add    :  "<<endl;
cout<<"2) remove :  "<<endl;
cout<<"3) insert : "<<endl;
cout<<"4) search :       "<<endl;
cout<<"5) print  : "<<endl;
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
insert();
}
else if(choice==4){
search();
}
else if(choice==5){
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


// function for inserting new node
void list :: insert(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int count=1;
int pos;
cout<<"Enter the pso : "<<endl;
cin>>pos;

if(pos>listsize || pos<1){
cout<<"Invalid position : "<<endl;
return;
}


while(temp->next=head){
     if(pos==count){
temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;

temp1->next=temp->next;
temp->next=temp1;
listsize++;
}
temp=temp->next;
count++;
}
}


// function for removing the  node
void list :: remove(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int pos;
int count=1;

cout<<"Enter the key to remove : "<<endl;
cin>>pos;

if(pos>listsize || pos<1){
cout<<"Invalid position : "<<endl;
return;
}

if(pos==1){
temp1=temp;
head=head->next;
delete temp1;
listsize--;
return;
}

while(temp->next=head){
       if(count==pos){
   temp1=temp->next;
   temp->next=temp->next->next;
   delete temp1;
   listsize--;
   }
   temp=temp->next;
count++;
}
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



void list   :: search(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int key;
cout<<"Enter the key : "<<endl;
cin>>key;

while(temp->next!=head){
   if(temp->info==key){
          cout<<"Key exist : "<<endl;
          return;
}
temp=temp->next;
}
cout<<"Not exist : "<<endl;
}












int main(){
list obj;
obj.option();


}
