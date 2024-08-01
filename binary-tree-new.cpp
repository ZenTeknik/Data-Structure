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
node *root,*temp;

tree();
~tree();
void deleteTree(node* root);
void option();
void insertion(node *root,node *temp ,int key );
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
int choice,key;
do{
cout<<"Avalible options : "<<endl;
cout<<"1) insertion :"<<endl;
cout<<"2) preorder :"<<endl;
cout<<"3) postorder :"<<endl;
cout<<"4) inorder :"<<endl;
cout<<"5) levelorder :"<<endl;
cout<<"0) Exit :"<<endl;
cin>>choice;

if(choice==1){
cout<<"Enter the key :"<<endl;
cin>>key;
insertion(root,temp,key);
cout<<endl;
}
else if(choice==2){
preorder(root);
cout<<endl;
}
else if(choice==3){
postorder(root);
cout<<endl;
}
else if(choice==4){
inorder(root);
cout<<endl;
}
else if(choice==5){
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


// function for the insertion of new node 
void tree :: insertion(node *root, node *temp,int key){
if(root==NULL){

temp=new node;
temp->info=key;
temp->left=NULL;
temp->right=NULL;
root=temp;
return;
}

if(temp->info==key){
cout<<"Key is already present in this tree : "<<endl;
return;
}

if(temp->info>key){
  if(temp->left!=NULL){
insertion(temp->left);
return;
}
else {
temp->left=new node;
temp->left->info=key;
temp->left->left=NULL;
temp->left->right=NULL;
return;
}
}

if(temp->info<key){
  if(temp->right!=NULL){
insertion(temp->right);
return;
}
else {
temp->right=new node;
temp->right->info=key;
temp->right->left=NULL;
temp->right->right=NULL;
return;
}
}

}




int main(){
tree obj;


obj.option();

return 0;
}

