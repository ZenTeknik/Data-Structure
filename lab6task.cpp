#include<iostream>
using namespace std;

struct node{
int  info;
node *next;
node *prev;
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
void reverse();
void print();
};


list :: list(){
head=temp=temp1=NULL;
}


list :: ~list(){
temp=head;
do{
temp1=temp;
temp=temp->next;
delete temp1;
}while(temp!=head);
}





void list :: option(){
int choice;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) add    :  "<<endl;
cout<<"2) reverse :  "<<endl;
cout<<"3) print  : "<<endl;
cout<<"0) EXIT   : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
add();
}
else if(choice==2){
reverse();
}
else if(choice==3){
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
head->prev=head;
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
head->prev=temp1;
temp->next=temp1;
temp1->prev=temp;
listsize++;
}










// function for reverse the   circuilar link list  
void list :: reverse(){

temp=head;
if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}


while(temp->next!=head){
temp=temp->next;
}



do{
cout<<temp->info<<"  ";
temp=temp->prev;

}while(temp!=head->prev);
}






// function for the print 
void list :: print(){

if(head==NULL){
cout<<"Empty list : "<<endl;
return;
}

temp=head;
do{
   cout<<temp->info<<" ";
   temp=temp->next;
   }while(temp!=head);
   cout<<endl;
}












int main(){
list obj;
obj.option();


}
