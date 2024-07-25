#include<iostream>
using namespace std;

struct node{
char info;
node  *next;
};


class queue{
private:
node *front,*rear;
int count;
int limit;
public: 
queue();
~queue();
void option();
void nqueue();
void dqueue();
void print();
};


queue :: queue(){
front=rear=NULL;
count=0;
limit=5;
}

queue :: ~queue(){
rear=front;
while(rear!=NULL){
rear=rear->next;
delete rear;
}
}


void queue :: option(){
int choice;
do{
cout<<"Avalible option :"<<endl;
cout<<"1) insert "<<endl;
cout<<"2) remove : "<<endl;
cout<<"3) print : "<<endl;
cout<<"0) exit"<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
nqueue();
}
else if(choice==2){
dqueue();
}
else if(choice==3){
print();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid choice : "<<endl;
}
}while(choice!=0);
}


void queue :: nqueue(){
rear=front;
if(front==NULL){
front=new node;
count++;
cout<<"Enter the first letter of name : "<<endl;
cin>>front->info;
front->next=NULL;
return;
}

if(count<=limit){
rear=new node;
count++;
cout<<"Enter the first letter of name : "<<endl;
cin>>rear->info;
rear->next=NULL;
rear->next=front;
}
}



void queue :: dqueue(){
rear=front;

if(front==NULL){
cout<<"No person in the Queue : "<<endl;
return;
}

front=front->next;
delete rear;
count--;
return;
}


void queue :: print(){
rear=front;

if(front==NULL){
cout<<"No person in the queue : "<<endl;
return;
}

while(rear!=NULL){
cout<<rear->info;
rear=rear->next;
}
cout<<endl;
}


int main(){
queue obj;
obj.option();
return 0;
}
