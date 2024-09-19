                                          // LAB TASK   5    DATE : SEP-19-2024

#include<iostream>
using namespace std;



struct node{
int info;
node *next;
node *prev;
};




class list {
private:
node * head,*temp,*temp1,*lastnode;
int listsize=0;
public:
list();
~list();
void option();
void add();
void remove();
void print();
void noOfnodes();
void search();
void reverse();
};


// constructer
list :: list(){
head=temp=temp1=lastnode=NULL;
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



// option function 
void list :: option(){
int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1) Add    : "<<endl;
cout<<"2) Remove : "<<endl;
cout<<"3) Print  : "<<endl;
cout<<"4) No of Nodes : "<<endl;
cout<<"5) Search  : "<<endl;
cout<<"6) Reverse : "<<endl;
cout<<"0) Exit  : "<<endl;
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
else if(choice==4){
noOfnodes();
}
else if(choice==5){
search();
}
else if(choice==6){
reverse();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}
}while(choice!=0);
}





// fucntion for add 
void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the info : "<<endl;
cin>>head->info;
head->next=NULL;
head->prev=NULL;
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
temp1->prev=temp;
listsize++;
}



// function for the delete the node
void list :: remove(){
temp=head;

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int pos;
cout<<"Enter the pos : "<<endl;
cin>>pos;

if(pos>listsize && pos<1){
cout<<"Invalid position : "<<endl;
return;
}

if(pos==1){
temp1=temp;
head=head->next;
head->prev=NULL;
delete temp1;
return;
}

int count=1;
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
listsize--;
return;
}

count++;
temp=temp->next;
}
cout<<"Invalid position : "<<endl;
}



// fucntion for countind the number of nodes
void list :: noOfnodes(){
cout<<"No of NOdes : "<<listsize<<endl;
}


// function for search 
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




// function for print
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


// function for reverse the list 
void list :: reverse(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


while(temp!=NULL){
     lastnode=temp;
     temp=temp->next;
}

while(lastnode!=NULL){
   cout<<lastnode->info<<" ";
   lastnode=lastnode->prev;
   }
}   



int main(){
list obj;
obj.option();


return 0;
}

