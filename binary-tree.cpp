#include<iostream>
using namespace std;


struct node{
int info;
struct node *left;
struct node *right;

node(int val ){
info=val;
left=NULL;
right=NULL;

~node{
delete left;
delete right;
}

};



int main(){

struct node *root=  new node(1);
root->left=  new node(2);
root->right=  new node(3);

root->left->left =new node(4);
root->left->right=NULL;
root->right->left=new node(5);
root->right->right=new node(6);

delete root;
return 0;
}
