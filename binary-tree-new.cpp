#include<iostream>
#include<queue>
using namespace std;

struct node{
int info;
node * left,*right,*root;
};

class tree{
public:
tree();
~tree();
void option();
void preorder();
void postorder();
void inorder();
void levelorder();
};


// constructer
tree :: tree(){
left=NULL
right=NULL;
}

// destructer 
tree :: ~tree(){
if(left){
delete left;
}

if(right){
delete right;
 }
}

// fucntion for options 
void tree : option(){
int choice;
do{
cout<<"Avalible options : "<<endl;
cout<<"1) preorder :"<<endl;
cout<<"2) postorder :"<<endl;
cout<<"3) inorder :"<<endl;
cout<<"4) levelorder :"<<endl;
cout<<"0) Exit :"<<endl;
cin>>choice;

if(choice==1){

}
else if(choice==2){


}
else if(choice==3){

}
else if(choice==4){

}
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}


void tree :: preorder(){
if(root==NULL){
cout<<"Tree is empty : "<<endl;
return;
}

cout<<root->info<<" ";
preorder(root->left);
preorder(root->right);
}


void tree :: postorder(){
if(root==NULL){
cout<<"Tree in empty : "<<endl;
return;
}
postorder(root->left);
postorder(root->right);
cout<<root->info<<" ";
}


// function for inorder
void tree :: inorder(){

if(root==NULL){
cout<<"Tree is empty : "<<endl;
return;
}
inorder(root-left);
cout<<root->info<<" ";
inorder(root->right);
}


// function for the level order 
void tree :: inorder(){
if(root=NULL){
cout<<"Tree is empty : "<<endl;
return;
}

queue<node*> q;
q.push(root);




int main(){


return 0;
}
