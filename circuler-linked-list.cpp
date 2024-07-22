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




int main(){



return 0 ;
}
