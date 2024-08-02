#include<iostream>
#include<queue>
using namespace std;


struct node{
int info;
node *right,*left;

node(int val) : val(info), left(NULL),right(NULL){};
};



class tree{ 
private: 
node *root;
public:
tree();
~tree();
void option();
void deletion(node *root);
void insert(node *&root,int key );
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);
void levelorder(node *root);
};

// cosntructer 
tree :: tree(){
root=NULL;
}

// destructer 
tree :: ~tree(){
deletion(root);
}

// fcuntion for the destructer 
void tree :: deletion(node *root){
if(root!=NULL){
deletion(root->left);
deletion(root->right);
delete root;
}

// function for the option's
void tree :: option(){
int choice,key;
do{
cout<<"Avalible option : "<<endl;
cout<<"1) Insert "<<endl;
cout<<"2) Preorder "<<endl;
cout<<"3) Postorder "<<endl;
cout<<"4) Inorder "<<endl;
cout<<"5) Levelorder "<<endl;
cout<<"0) Exit "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
insert(root);
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


// fucntion for the insertion of new node 
void insert(node *&root,int key){
if(root==NULL){
root=new node(key);
return;
}

if(key==root->info){
cout<<"Key is already in Tree : "<<endl;
return;
}

if(key<root->info){
insert(root->left, key);
return;
}
else{
insert(root->right,key);
return;
}

}


// fucntion for the preorder
void tree :: preorder(node *root){


}

int main(){



return 0;
}

