#include<iostream>
using namespace std;

struct node{
int info;
node *next;
};



class list{
private:
node *head,*temp*temp1;
public:

list();
~list();
void option();
void search();
void add();
void remove();
void length();
};





list :: list(){
head=temp=temp1=NULL;
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
cout<<"Avalible option : "<<endl;
cout<<"1) add : "<<endl;
cout<<"2) remove : "<<endl;
cout<<"3) length : "<<endl;
cout<<"4) search : "<<endl;
cout<<"0) EXIT : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;



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
else if(choice==0){
break;
}
else {
cout<<"Invalid choice :"<<endl;
}


}while(choice!=0);


}





int main(){




return 0;
}
