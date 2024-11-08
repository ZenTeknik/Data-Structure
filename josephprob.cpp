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
void add();
void remove();
void print();
void search();
};



list :: list(){
head=temp=temp1;
}


list :: ~list(){
temp=head;
while(temp->next!=head){
temp1=temp;
temp=temp->next;
delete temp1;
}
}


void list :: option(){
int choice;
do{
cout<<"Avalible Choices : "<<endl;
cout<<"1)  Add : "<<endl;
cout<<"2)  Remove : "<<endl;
cout<<"3)  Print  : "<<endl;
cout<<"4)  Search : "<<endl;
cout<<"0)  Exit : "<<endl;
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




void list :: add(){
temp=head;

while(head==NULL){
head =new node;
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


void list :: remove(){
temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

int k,count=1;
cout<<"Enter the K value (Joseph problem : )"<<endl;
cin>>key;



while(temp->next!=head){
    if(count==k){
  temp->next=temp1;
  temp->next->next=temp->next;
  delete temp1;
  listsize--;
  return;
}
temp=temp->next;
count++;
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


void list :: search(){
temp=head;
int key;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

cout<<"Enter the key to search : "<<endl;
cin>>key;

while(temp->next!=head){
     if(temp->info==key){
cout<<"Key exist : "<<endl;
}
temp=temp->next;
}
cout<<"Key not exist : "<<endl;
}





int main(){



return 0;
}
