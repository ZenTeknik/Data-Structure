/*
#include<iostream>
using namespace std;


class node{
public:
int info;
 node *left;
 node *right;



// constructer
node(int val ){
info=val;
left=NULL;
right=NULL;
}

// destructer
~node(){
cout<<"Destructer : "<<info<<endl;
if(left){
delete left;
left=NULL;
}

if(right){
delete right;
right=NULL;
}
}
};


void preorder(node *root ){
if(root==NULL){
//cout<<" NULL "<<endl;
return;
}
else{
cout<<root->info<<" ";
preorder(root->left);
preorder(root->right);
}
}



int main(){

 node *root=  new node(1);
root->left=  new node(2);
root->right=  new node(3);

root->left->left =new node(4);
root->left->right=NULL;
root->right->left=new node(5);
root->right->right=new node(6);
preorder(root);
cout<<endl;

delete root;
return 0;
}



*/


#include<iostream>
using namespace std;

class node{
public:
int   info;
node *left;
node *right;
node(int info){
this->info=info;
left=NULL;
right=NULL;
}

~node(){
if(left){
delete left;
left=NULL;
}
if(right){
delete right;
right=NULL;
}
}
};



void preorder(node * root){
if(root==NULL){
cout<<"-1 ";
}
else{
cout<<root->info<<" ";
preorder(root->left);
preorder(root->right);
}
}

void postorder(node *root){
if(root==NULL){
cout<<" -1 ";
}
else {
postorder(root->left);
postorder(root->right);
cout<<root->info<<" "; 
}
}


// inoreder 
void inorder(node *root){
if(root==NULL){
cout<<" -1 ";
}
else{
inorder(root->left);
cout<<root->info<<" ";
inorder(root->right);
}
}




int main(){

 node *root=new node(1);
root->left=new node(2);
root->left->left=new node(3);
root->right=new node(4);
root->right->left=new node(5);
root->right->right=new node(6);


// for printing the preorder of the tree like fron top to down 
cout<<"Preorder: "<<endl;
preorder(root);
cout<<endl;
// for printing the postorder of the tree like from down to top
cout<<"Postorder: "<<endl;
postorder(root);
cout<<endl;
// for printing the left side like inorder way 
cout<<"Inorder: "<<endl;
inorder(root);
cout<<endl;

delete root;

return 0;
}
