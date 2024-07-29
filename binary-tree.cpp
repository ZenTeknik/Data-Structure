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
