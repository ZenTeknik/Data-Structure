#include<iostream>
using namespace std;

struct node{
int info;
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
void insert();
void reverse();
void search();
void palindrome();
void print();
void removeduplicate();
void swap();
};


// constructer
list :: list() {
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



// function for the option
void list :: option(){
int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1) ADD : "<<endl;
cout<<"2) Remove : "<<endl;
cout<<"3) Insert : "<<endl;
cout<<"4) reverse  : "<<endl;
cout<<"5) Search: "<<endl;
cout<<"6) Palindrome: "<<endl;
cout<<"7) Remove duplicate  : "<<endl;
cout<<"8) Swap : "<<endl;
cout<<"9) Print : "<<endl;
cout<<"0) Exit   : "<<endl;
cout<<" Enter your choice : "<<endl;
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
reverse();
}
else if(choice==5){
search();
}
else if(choice==6){
palindrome();
}
else if(choice==7){
removeduplicate();
}
else if(choice==8){
swap();
}
else if(choice==9){
print();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}
}while(choice!=0);
}





// function for adding the element 
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




// function for inserting new node
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

if(pos>listsize || pos<1){
cout<<"Invalid Position : "<<endl;
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
cout<<"New node inserted at pos "<<pos<<" :  "<<endl;
}





// function for removing the node
void list :: remove(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


int pos;
int count=1;
cout<<"Enter the pos : "<<endl;
cin>>pos;

if(pos>listsize || pos<1){
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
  delete temp1;
  listsize--;
  return;
  }
count++;
temp=temp->next;
}
}


// function for reverse 
void list :: reverse(){
node* current=NULL;
node* next=NULL;
node* prev=NULL;

current=head;


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




// function for the search
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
    return;
}
temp=temp->next;
}
cout<<"Key not exist : "<<endl;
}



// function for the palindrome 
void list :: palindrome(){
temp=head;
node *fast=head;
node *slow=head;
node * mid=NULL;
node * next=NULL;


if(head==NULL){
cout<<"Empyt list : "<<endl;
return;
}

while(fast!=NULL && fast->next!=NULL){
fast=fast->next->next;
slow=slow->next;
}

mid=slow;
node* prev=NULL;
// here reverse the half list for compareing 
while(mid!=NULL){
  next=mid->next;
mid->next=prev;

prev=mid;
mid=next;
}
mid=prev;


// now comapring
while(temp!=NULL && mid!=NULL){
  if(temp->info!=mid->info){
  cout<<" Not a  Palindrome :  "<<endl;
  return;
  }
temp=temp->next;
mid=mid->next;
}
cout<<"yess! palindrome : "<<endl;
}







// functoion for the dulicates removing 
void  list :: removeduplicate(){
temp=head;
node *rm=NULL;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


while(temp!=NULL  && temp->next!=NULL){
     temp1=temp;
       while(temp1->next!=NULL){
          if(temp->info==temp1->next->info){
      rm=temp1->next;
      temp1->next=temp1->next->next;
      delete rm;
        listsize--;
}
temp1=temp1->next;
}
temp=temp->next;
}
print();
}


// function for swapping 
void list :: swap(){
temp=head;
node *fast=head;
node *slow=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int k;
cout<<"Enter the value of K : "<<endl;
cin>>k;

for(int i=1;i<k;i++){
  fast=fast->next;
  temp1=fast;
}


while(fast->next!=NULL){
fast=fast->next;
slow=slow->next;
}

int val=temp1->info;
temp1->info=slow->info;
slow->info=val;
temp=head;
print();
}


// function for printing 
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
