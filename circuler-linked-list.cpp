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

list();
~list();
void option();
void add();
void remove();
void print();
void length();
void search();
};

// constructer 
list :: list(){
head=temp=temp1=NULL;
}



// destructer 
list :: ~list(){
temp=head;
if(head==NULL)
return;

while(temp->next!=head){
temp1=temp;
temp=temp->next;
delete temp1;
}
delete temp;
    head = NULL;
}


void list :: option(){
int choice;

do{
cout<<"Avalible Option : "<<endl;
cout<<"1) ADD     : "<<endl;
cout<<"2) REMOVE  : "<<endl;
cout<<"3) PRINT   : "<<endl;
cout<<"4) LENGTH  : "<<endl;
cout<<"5) SEARCH  : "<<endl;
cout<<"0) EXIT    : "<<endl;
cout<<"Enter  your choice : "<<endl;
cin>>choice;

if(choice==1){
add();
}
//else if(choice==2){
//remove();
//}
else if(choice==3){
print();
}
else if(choice==4){
length();
}
else if(choice==5){
search();
}
else if(choice==0){
break;
}
else{
cout<<"Invalid Choice : "<<endl;
}

}while(choice!=0);
}



// fucntion for printing values  
void list :: print(){
temp=head;
if(head==NULL){
cout<<"No Element to Print : "<<endl;
return;
}

while(temp->next!=head){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}


// function for finding length 
void list :: length(){
temp=head;
int count=0;
while(temp->next!=head){
count++;
temp=temp->next;
}
cout<<"Length : "<<count<<endl;
}


// function for search element 
void list :: search(){
temp=head;

if(head==NULL){
cout<<"No Element to Search : "<<endl;
return;
}


int key;
cout<<"Enter the key to search : "<<endl;
cin>>key;

while(temp->next!=head){
if(temp->info==key){
cout<<"Key Found : "<<temp->info<<endl;
return;
}
temp=temp->next;
}
cout<<"Key Not Found : "<<endl;
}





// function for adding values 
void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter the value : "<<endl;
cin>>head->info;
head->next=head;
return;
}

while(temp->next!=head){
temp=temp->next;
}

temp1=new node;
cout<<"Enter the value :"<<endl;
cin>>temp1->info;
temp1->next=head;
temp->next=temp1;
}







int main(){

list obj;
obj.option();

return 0 ;
}
