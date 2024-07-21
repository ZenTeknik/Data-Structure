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


list :: list(){
    head=temp=temp1=min=max=NULL;

}

list :: ~list(){
    temp=head;
    while(temp!=NULL){
        temp1=temp;
        temp=temp->next;
        delete temp1;
    }
}


void list :: option(){

int choice;
do{
cout<<"Avalible Option  :"<<endl;
cout<<"1) print : "<<endl;
cout<<"2) print : "<<endl;



}while(choice!=0);




int main(){

return 0;
}
