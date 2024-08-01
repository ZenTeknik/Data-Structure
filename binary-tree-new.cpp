#include<iostream>
#include<queue>
using namespace std;

struct node{
int info;
node * left,*right;
};

class tree{
public:
node *root;

tree(info);
~tree();
void option(root);
void preorder(root);
void postorder(root);
void inorder(root);
void levelorder(root);
};


// constructer
tree :: tree(int info){
this->info=info;
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
void tree : option(node *root){
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
preorder(root);
}
else if(choice==2){
postorder(root);

}
else if(choice==3){
inorder(root);
}
else if(choice==4){
levelorder(root);
}
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}


void tree :: preorder(node *root){
if(root==NULL){
cout<<"Tree is empty : "<<endl;
return;
}

cout<<root->info<<" ";
preorder(root->left);
preorder(root->right);
}


void tree :: postorder(node *root){
if(root==NULL){
cout<<"Tree in empty : "<<endl;
return;
}
postorder(root->left);
postorder(root->right);
cout<<root->info<<" ";
}


// function for inorder
void tree :: inorder(node *root){

if(root==NULL){
cout<<"Tree is empty : "<<endl;
return;
}
inorder(root-left);
cout<<root->info<<" ";
inorder(root->right);
}


// function for the level order 
void tree :: inorder(node *root){
if(root=NULL){
cout<<"Tree is empty : "<<endl;
return;
}

queue<node*> q;
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
tree obj;
obj.root=new node(1);
obj.root->left=new node(2);
obj.root->left->left=new node(3);
obj.root->right=new node(4);
obj.root->right->left=new node(5);
obj.root->right->right=new node(6);


obj.option();

delete root;

return 0;
}

