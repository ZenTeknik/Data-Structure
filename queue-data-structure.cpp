#include<iostream>
using namespace std;

struct node{
char info;
node  *next;
};


class queue{
private:
node *front,*temp;
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
front=temp=NULL;
count=0;
limit=5;
}

queue :: ~queue(){
temp=front;
while(temp!=NULL){
temp=temp->next;
delete temp;
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


// fucntion for the nqueue 
void queue :: nqueue(){
temp=front;
if(front==NULL){
front=new node;
cout<<"Enter the first letter of your name : "<<endl;
cin>>front->info;
count++;
front->next=NULL;
return;
}

if(count<=limit){
temp=new node;
cout<<"Enter the first letter of your name : "<<endl;
cin>>temp->info;
count++;
temp->next=NULL;
front->next=temp;
return;
}



// fucntion for the dqueue
void queue :: dqueue(){
temp=front;
if(front==NULL){
cout<<"No person in the queue : "<<endl;
return;
}

front=front->next;
delete temp;
count--;
}


void queue :: print(){
temp=front;

if(front==NULL){
cout<<"No person in the queue : "<<endl;
return;
}

while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}


int main(){
queue obj;
obj.option();
return 0;

}
