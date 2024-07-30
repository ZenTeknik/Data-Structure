/*
#include<iostream>
#include<queue>       // for managing the queue  that we create for storing the element in level up in queue 
using namespace std;

class node{
public:
int info;
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


void levelorder(node *root){
if(root==NULL){
return;
}

queue<node*>q;
q.push(root);

while(!q.empty()){
node *current=q.front();
q.pop();

cout<<current->info<<" ";

if(current->left!=NULL){
q.push(current->left);
}

if(current->right!=NULL){
q.push(current->right);
}

}
}




int main(){


node *root=new node (1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(5);
root->left->right=new node(6);

root->right->left=new node(7);
root->right->right=new node(8);

levelorder(root);

delete root;

return 0;
}



*/


#include<iostream>
using namespace std;

class node{
public:
int info;
node *left;
node *right;

// constructer
node(int info){
this->info=info;
left=NULL;
right=NULL;
}

// destructer 
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



void levelorder(){



}

int main(){


return 0;
}


