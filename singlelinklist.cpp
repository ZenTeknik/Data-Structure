#include<iostream>
using namespace std;


struct node{
int info;
node *next;
};


class list{
private:
node *head,*temp,*temp1;
int listsize=0;
public:
list();
~list();
void option();
void next();
void add();
void remove();
void insert();
void length();
void print();
void min();
void max();
void reverse();
void search();
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


// option
void list :: option(){
int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1)  Add :  "<<endl;
cout<<"2)  Remove :  "<<endl;
cout<<"3)  Insert :"<<endl;
cout<<"4)  Next : "<<endl;
cout<<"5)  Length : "<<endl;
cout<<"6)  Print :"<<endl;
cout<<"7)  Min"<<endl;
cout<<"8)  Max "<<endl;
cout<<"9)  Reverse :  "<<endl;
cout<<"10)  Search :  "<<endl;
cout<<"0) Exit "<<endl;
cout<<"Enter your choice :  "<<endl;
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
next();
}
else if(choice==5){
length();
}
else if(choice==6){
print();
}
else if(choice==7){
min();
}
else if(choice==8){
max();
}
else if(choice==9){
reverse();
}
else if(choice==10){
search();
}
else if(choice==0){
break;
}
else {
cout<<"Inavlid Choice  : "<<endl;
}
}while(choice!=0);
}


//adding node 
void list :: add(){
temp=head;
if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;
head->next=NULL;
listsize++;
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
listsize++;
}



// remove
void list :: remove(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int count=1;
int pos;

cout<<"Enter the position : "<<endl;
cin>>pos;

if(pos>listsize && pos<1){
cout<<"Invalid Position : "<<endl;
return;
}

if(pos==1){
temp1=temp;
head=head->next;
delete temp1;
listsize--;
return;
}

while(temp!=NULL){
      if(count==pos){
     temp1=temp->next;
     temp->next=temp->next->next;
     listsize--;
 }
temp=temp->next;
count++;
}
}


// inserting the new node
void list :: insert(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int pos;
int count=1;
cout<<"Enter the pos : "<<endl;
cin>>pos;

if(pos>listsize && pos<1){
cout<<"Invalid position : "<<endl;
return;
}


while(temp!=NULL){
   if(count==pos){
temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;

temp1->next=temp->next;
temp->next=temp1;
listsize++;
return;
}
temp=temp->next;
count++;
}
}


// next 
void list :: next(){
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

if(temp!=NULL){
temp=temp->next;
cout<<temp->info<<" ";
}
}


// fucntion for length 
void list :: length(){
cout<<"Lenght : "<<listsize<<endl;
}


// fucntion for print 
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



// function for finding the minimum 
void list :: min(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int min=temp->info;
 while(temp!=NULL){
     if(temp->info<min){
    min=temp->info;
    }
temp=temp->next;
}
cout<<"Minimum value : "<<min<<endl;
}


// function for the maximum value 
void list :: max(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int max=temp->info;
while(temp!=NULL){
   if(temp->info>max){
  max=temp->info;
  }
temp=temp->next;
}
cout<<"Maximum value : "<<max<<endl;
}



// fucntion for the reverse 
void list :: reverse(){
node *current=head;
node *next=NULL;
node *prev=NULL;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

while(current!=NULL){
next=current->next;
current->next=prev;

prev=current;
current=next;

}
head=prev;
print();
}



// function for the seach 
void list :: search(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int key;
cout<<"Enter the key : "<<endl;
cin>>key;

while(temp!=NULL){
   if(temp->info==key){
     cout<<"Key exist : "<<endl;
    }
temp=temp->next;
}
}



int main(){
list obj;
obj.option();

return 0;
}
