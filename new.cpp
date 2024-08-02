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
if(root==NULL){
cout<<"Tree is empty :"<<endl;
return;
}
cout<<root->info<<" ";
if(root->left!=NULL){
preorder(root->left);
}
if(root->right!=NULL){
preorder(root->right);
}
}



void tree :: insert(int key){
if(root==NULL){
root=new node;
root->left=NULL;
root->right=NULL;
root=key;
return;
}

if(key==root->info){
cout<<"key is already avalible in this tree : "<<endl;
return;
}

if(root->info>key){
  if(root->left!=NULL){
 insert(root->left);
 return;
}
}
else{
root->left=new node;
root->left->info=key;
root->left->left=NULL;
root->left->right=NULL;
return;
}

if(root->info<key){
  if(root->right!=NULL){
insert(root->right);
}
}
else {
root->right=new node;
root->right->info=key;
root->right->left=NULL;
root->right->right=NULL;
return;

}


}


int main(){



return 0;
}
