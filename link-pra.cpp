#include<iostream>
using namespace std;

struct box{
int info;
box  *next;
};

class list{
private:
box *head,*temp,*temp1;

public:
list();
~list();
void option();
void add();
void print();
void remove();
void length();
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
cout<<"AVALIBLE CHOICES : "<<endl;
cout<<"1) Add : "<<endl;
cout<<"2) Remove  : "<<endl;
cout<<"3) Print : "<<endl;
cout<<"4) length : "<<endl;
cout<<"0) Exit : "<<endl;
cout<<"Enter your choice  : "<<endl;
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
length();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}



}while(choice!=0);

}


void list :: print(){
temp=head;
if(head==NULL){
cout<<"No element in Linked List : "<<endl;
}
while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}



void list :: length(){
int count=0;
temp=head;
while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"Length : "<<count<<endl;
cout<<endl;
}


void list :: add(){
temp=head;

if(head==NULL){
head=new box;

cout<<"Enter element in the head : "<<endl;
cin>>head->info;
head->next=NULL;
return;
}


while(temp->next!=NULL){
temp=temp->next;
}

char  option;
int key;
temp=head;
cout<<"You wanna add normally(n) or between(b) : exit(e)  "<<endl;
cin>>option;

if(option=='b' || 'B'){
cout<<"Enter the element after u wanna add  : "<<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){
temp1=new box;
cout<<"Enter the element : "<<endl;
cin>>temp1->info;
temp1->next=temp->next;
temp->next=temp1;
}
temp=temp->next;
}
cout<<"Key  not found : "<<endl;
}

else if (option=='n' || 'N' ){
temp1=new box;
cout<<"Enter the element : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
}

else if(option=='e' || 'E'){
return;
}
else {
cout<<"Invalid option : "<<endl;
return;
}
}





void list :: remove(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to remove : "<<endl;
return;
}

cout<<"Enter the element to remove : "<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;
delete temp1;
return;
}


while(temp!=NULL){
if(temp->info==key){
temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
return;
}
}
cout<<"Element not found : "<<endl;
}







int main(){
list obj;

obj.option();

return 0;
}
