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
    
}
else {
    cout<<"Invalid Choice : "<<endl;
}
}while(choice!=0);

}


