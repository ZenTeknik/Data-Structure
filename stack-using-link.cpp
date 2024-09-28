#include<iostream>
using namespace std;


struct node{

int info;
node *next;
};

class list {
private:
node *top,*temp,*temp1,*lastnode;
int count=0;
public:
list();
~list();
void option();
void push();
void pop();
void print();
void search();
};


// constructer
list :: list(){
top=temp=NULL;
}


// destructer
list :: ~list(){
temp=top;
while(temp!=NULL){
  temp=temp->next;
  delete temp;
}
}






// function for the options 
void list :: option(){
int choice;
do{
cout<<"Avalible Option : "<<endl;
cout<<"1) Push : "<<endl;
cout<<"2) Pop : "<<endl;
cout<<"3) print : "<<endl;
cout<<"4) search  : "<<endl;
cout<<"0) Exit : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
push();
}

else if(choice==2){
pop();
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



// function for the add elements 
void list :: push(){
temp=top;
if(top==NULL){
top=new node;

cout<<"Enter the info : "<<endl;
cin>>top->info;

top->next=NULL;
lastnode=top;
count++;
return;
}


while(temp->next!=NULL){
temp=temp->next;
}

temp=new node;
cout<<"Enter the info : "<<endl;
cin>>temp->info;
temp->next=NULL;
top->next=temp;
top=temp;
count++;
}



// function for the remove elements 
void list :: pop(){
temp=top;
if(top==NULL){
cout<<"Empty stack : "<<endl;
return;
}


temp=top;
top=top->next;
delete temp;
count--;
}



// function for the print 
void list :: print(){
temp=top;

if(top==NULL){
cout<<"Empty Stack : "<<endl;
return;
}


while(lastnode!=NULL){
cout<<lastnode->info<<" ";
lastnode=lastnode->next;
}
cout<<endl;
}





// function for the search
void list :: search(){
temp=top;

if(top==NULL){
cout<<"Empty Stack : "<<endl;
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





int main(){
list obj;
obj.option();

return 0;
}

