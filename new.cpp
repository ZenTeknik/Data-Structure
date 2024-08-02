#include<iostream>
#include<queue>
using namespace std;

struct node{
int info;
node *left,right;

node(int val) : info(val) , left(NULL), right(NULL){};
};

class tree{
private:
node *root;
public:

tree();
~tree();
void deleteion(node * root);
void option();
void insert(key);
void preorder(node *root);
};



tree :: tree(){
root=NULL;
}

tree :: ~tree(){
deletetion(root);
}

void tree :: deletetion(node *root){
if(root!=NULL){
deletetion(root->left);
deletetion(root->right);
delete root;
}
}


void tree :: option(){
int choice;
int key;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) Insert  "<<endl;
cout<<"2) Preorder  "<<endl;
cout<<"0) Exit  "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
cout<<"Enter the key u have to insert : "<<endl;
cin>>key;
insert(key);
}

else if(choice==2){
preorder(root);
}

else if(choice==0){
cout<<"Exiting the programm : "<<endl;
break;
}

else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}



void preorder(node *root){



}



int main(){



return 0;
}
