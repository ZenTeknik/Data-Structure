#include<iostream>
using namespace std;




struct node{
int info;
node *next;
};

class list {
private:
node *head,*temp,*tail;


public :
list();
~list();
void option();
void add();
void remove();
void print();
};




list :: list(){
head=temp=tail=NULL;
}



list :: ~list(){
 while(head!=NULL){
  temp=head;
  head=head->next;
  delete temp;
}
}



void list :: option(){
int choice;
do{
cout<<" Avalible Option : "<<endl;
cout<<" 1) ADD : "<<endl;
cout<<"2) REMOVE : "<<endl;
cout<<"3) PRINT : "<<endl;
cout<<"0) EXIT : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;


if(choice==1 ){
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
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);

}




void list :: add(){
  temp=head;
  if(head==NULL){
  head=new node;
  cout<<"Enter the info : "<<endl;
  cin>>head->info;
  
  head->next=NULL;
  return;
  }
  
while(temp->next!=NULL){
temp=temp->next;
}  
  
tail=new node;
cout<<"Enter the info : "<<endl;
cin>>tail->info;

tail->next=NULL;
temp->next=tail;
}



void list :: remove(){

if(head==NULL){
  cout<<" Queue is Empty : "<<endl;
  return;
}

temp=head;
while(temp!=NULL){
    temp=head;
    head=head->next;
    delete temp;
    }
}




void list :: print(){
temp=head;
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
