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
while(temp->next!=head){
temp1=temp;
temp=temp->next;
delete temp1;
}
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
else if(choice==2){
remove();
}
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










int main(){



return 0 ;
}
