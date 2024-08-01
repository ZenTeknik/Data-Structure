#include<iostream>
#include<queue>
using namespace std;

struct node{
int info;
node * left,*right;
 node(int val) : info(val), left(NULL), right(NULL) {};
};

class tree{
public:
node *root;

tree();
~tree();
void deleteTree(node* root);
void option();
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);
void levelorder(node *root);
};


// constructer
tree :: tree(){
root=NULL;
}

// destructer 
tree :: ~tree(){
deleteTree(root);
}


void tree::deleteTree(node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
// fucntion for options 
void tree :: option(){
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
cout<<endl;
}
else if(choice==2){
postorder(root);
cout<<endl;
}
else if(choice==3){
inorder(root);
cout<<endl;
}
else if(choice==4){
levelorder(root);
cout<<endl;
}
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}



// fucntion for the preorder
void tree :: preorder(node *root){
if(root==NULL){
cout<<"Tree in empty : "<<endl;
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




// function for the postorder
void tree :: postorder(node *root){
if(root==NULL){
cout<<"Tree is empty : "<<endl;
return;
}
if(root->left!=NULL){
postorder(root->left);
}
if(root->right){
postorder(root->right);
}
cout<<root->info<<" ";
}



// function for inorder
void tree :: inorder(node *root){
if(root==NULL){
cout<<"Tree in empty : "<<endl;
return;
}
if(root->left){
inorder(root->left);
}
cout<<root->info<<" ";
if(root->right!=NULL){
inorder(root->right);
}
}

// function for the level order 
void tree :: levelorder(node *root){
if(root==NULL){
return;
}
else{
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

return 0;
}

