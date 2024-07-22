#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node *prev;
};


class  list{
private: 
node *head;
node *temp,*temp1,*min,*max;

public: 
list();
~list();
void option();
void print();
void length();
void add();
void remove();
void mini();
void maxi();
void search();

};

// constructer 
list :: list(){
    head=temp=temp1=min=max=NULL;
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

// function for option
void list :: option(){

int choice;
do{
cout<<"Avalible Option  :"<<endl;
cout<<"1) print : "<<endl;
cout<<"2) add : "<<endl;
cout<<"3) remove : "<<endl;
cout<<"4) search : "<<endl;
cout<<"5) minimum : "<<endl;
cout<<"6) maximum : "<<endl;
cout<<"7) length : "<<endl;
cout<<"0) Exit : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){

}
else if(choice==2){

}
else if(choice==3){
    
}
else if(choice==4){
    
}
else if(choice==5){
    
}
else if(choice==6){
    
}
else if(choice==7){
    
}
else if(choice==0){
 break;   
}
else {
    cout<<"Invalid Choice : "<<endl;
    }
}while(choice!=0);

}


// fucntion for printing the value 
void list :: print(){
temp=head;

if(head==NULL){
cout<<"No Element to print : "<<endl;
return;
}

while(temp!=NULL){
cout<<temp->info<<" ";
temp=temp->next;
}
cout<<endl;
}


// function for the lenght 
void list :: length(){
temp=head;
int count=0;
while(temp!=NULL){
 count++;
 temp=temp->next;
 }
 cout<<"Length : "<<count<<endl;
cout<<endl;
}



// fucntion for the searching number
void list :: search(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to search : "<<endl;
return;
}

cout<<"Enter the key to search : "<<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){
cout<<"Key Found "<<temp->info<<endl;
return;
}
temp=temp->next;
}
cout<<"Key Not Found : "<<endl;
return;
}



// function for finding the minimum number 
void list :: mini(){
temp=head;
if(head==NULL){
cout<<"No Element to find minimum : "<<endl;
return;
}
int min;
min=head->info;

while(temp!=NULL){
if(temp->info<min){
min=temp->info;
}
temp=temp->next;
}
cout<<"Minimum Number : "<<min<<endl;
}



// fucntion for finding the maximum number 
void list :: maxi(){
temp=head;
if(head==NULL){
cout<<"No Element to find Maximum : "<<endl;
return;
}
int max;
max=head->info;
while(temp!=NULL){
if(temp->info>max){
max=temp->info;
}
temp=temp->next;
}
cout<<"Maximum Number : "<<temp->info<<endl;
return;
}





