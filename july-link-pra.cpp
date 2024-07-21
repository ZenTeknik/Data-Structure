#include<iostream>
using namespace std;


struct node {
int info;
node * next;
};


class list {
private: 
node *head,*mini,*maxi;
node *temp, *temp1;

public: 
list();
~list();
void option();
void search();
void max();
void min();
void length();
void add();
void remove();
void print();


};



list :: list(){
head=temp=temp1=mini=maxi=NULL;
}


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
cout<<"Avalible Option : "<<endl;
cout<<"1) Add : "<<endl;
cout<<"2) Remove : "<<endl;
cout<<"3) Length : "<<endl;
cout<<"4) Search  : "<<endl;
cout<<"5) Max : "<<endl;
cout<<"6) Min : "<<endl;
cout<<"7) Print : "<<endl;
cout<<"0) Exit  : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if ((choice >= 'a' && choice <= 'z') || (choice >= 'A' && choice <= 'Z')) {
            cout << "JUST input given option: " << endl;
            continue; // Skip the rest of the loop and prompt for input again
        }

if(choice==1){
add();
}
else if(choice==2){
remove();
}
else if(choice==3){
length();
}
else if(choice==4){
search();
}
else if(choice==5){
max();
}
else if(choice==6){
min();
}
else if(choice==7){
print();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid Choice : "<<endl;
}


}while(choice!=0);
}


// search function 


void list :: search(){
temp=head;

if(head==NULL){
cout<<"No element to search : "<<endl;
return ;
}
int key;
cout<<"Enter the key u wanna search : "<<endl;
cin>>key;

while(temp!=NULL){
if(key==temp->info){
cout<<"Key found : "<<endl;
return;
}
temp=temp->next;
}
cout<<"Not found : "<<endl;
}




// fucntion for print the value
void list :: print(){
temp=head;

if(head==NULL){
cout<<"No element to print : "<<endl;
return;
}

while(temp!=NULL){
cout<<temp->info <<" ";
temp=temp->next;
}
cout<<endl;
}


// fucntion for find length 

void list :: length(){
temp=head;

int count=0;
while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"Length : "<<count<<endl;
}


// function for finding the max value 
void list :: max(){
temp=head;

if(head==NULL){
cout<<"No element to find the maximum number : "<<endl;
return ;
}

int maxi=head->info;
while(temp!=NULL){
if(temp->info>maxi){
 maxi=temp->info;
}
temp=temp->next;
}

cout<<"Max number : "<<maxi<<endl;
}



// function for finding  the min value
void list :: min(){
temp=head;
if(head==NULL){
cout<<"No element to find minimum : "<<endl;
return ;
}

int mini;
mini=head->info;
while(temp!=NULL){
if(temp->info<mini){
mini=temp->info;
}
temp=temp->next;
}
cout<<"Min Number : "<<mini<<endl;
}



// fucntion to remove the value
void list :: remove(){
temp=head;

if(head==NULL){
cout<<"No element to remove : "<<endl;
return ;
}

int key;
cout<<"Enter the key to remove  : "<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;
delete temp1;
return ;
}


while(temp->next!=NULL){
if(temp->next->info==key){
temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
return;
}
temp=temp->next;
}
cout<<"Key Not Found : "<<endl;
}




void list :: add(){
temp=head;

if(head==NULL){
head=new node;
cout<<"Enter  the element in the head : "<<endl;
cin>>head->info;
head->next=NULL;
return;
}
int key;
char option;
cout<<"You wanna add normally(n) or between(b) : "<<endl;
cin>>option;

if(option=='n' || option=='N'){

while(temp->next!=NULL){
temp=temp->next;
}
temp1=new node;
cout<<"Enter the element u wanna add : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
}
else if(option=='b' || option=='B'){
temp=head;

cout<<"Enter the element where after u wanna add  : " <<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){

temp1=new node;
cout<<"Enter the element u add : "<<endl;
cin>>temp1->info;
temp1->next=temp->next;
temp->next=temp1;
}
temp=temp->next;
}
cout<<"Invalid Choice : "<<endl;

}
else{
cout<<"No option avalible : "<<endl;
return;
}
}




int main(){
list obj;

obj.option();
return 0;
}





