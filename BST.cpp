#include<iostream>
using namespace std;



struct node{
    int info;
    node *left,*right;
};


class tree{
private:
    node *root,*temp;
public:
    tree();
    ~tree();
    void option();
    void insert(node *&root,int val);
    void preorder(node *&root);
    void postorder(node *&root);
    void inorder(node *&root);
    int height(node *&root);
    int  nodescount(node *&root);
    node* remove(node *&root,int val);
     node* findmin(node *&root);
};



tree :: tree(){
    root=temp=NULL;
}


tree :: ~tree(){

}



// function for the option
void tree :: option() {
    int choice,val;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insert    " << endl;
        cout << "2) preorder  " << endl;
        cout << "3) postorder " << endl;
        cout << "4) Inorder   " << endl;
        cout << "5) Height    " << endl;
        cout << "6) Nodes Count : " << endl;
        cout << "7) Remove :  " << endl;
        cout << "0) Exit      " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter the info : "<<endl;
                cin>>val;
                insert(root,val);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                cout<<"Height of Tree : "<<height(root)<<endl;
                break;
            case 6:
                cout<<"Total Nodes : "<<nodescount(root)<<endl;
                break;
            case 7:
                cout<<"Enter the key to remove : "<<endl;
                 cin>>val;
                remove(root,val);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}



// for adding the elements
void tree :: insert(node *&root,int val){
   if(root==NULL){
   root=new node;
   root->info=val;
   root->left=NULL;
   root->right=NULL;
   return;
   }

   if(val>root->info){
       insert(root->right,val);
   }
  else if(val<root->info){
     insert(root->left,val);
  }
  else {
    cout<<" Duplicate value : "<<endl;
  }
cout<<endl;
}



// function for the preorder
void tree :: preorder(node *&root){
    if(root!=NULL){
   cout<<root->info<<" ";
   preorder(root->left);
   preorder(root->right);
    return;
    }
}


// function for the posrorder
void tree :: postorder(node *&root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->info<<" ";
        return;
    }
}



// function for the inorder
void tree :: inorder(node *&root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->info<<" ";
        inorder(root->right);

        return;
    }
}


// function for the finding the height of the tree
int  tree :: height(node *&root){
    if(root==NULL){
     return 0;
    }

    int leftcount;
    int rightcount;

    leftcount=height(root->left);
    rightcount=height(root->right);
   int max;

if(leftcount>rightcount){
    max=leftcount;
}
  else{
      max=rightcount;
 }

return 1+max;
}




// function for finding  the number of nodes
int  tree :: nodescount(node *&root){
    if (root == NULL) {
        return 0;
    }


   int  rootleft=nodescount(root->left);
   int  rootright=nodescount(root->right);


return 1+ rootleft+rootright;
}



// function to delete the node from the BST
node* tree :: remove(node *&root,int val){
  if(root==NULL){
  cout<<"Empty BST : "<<endl;
  return 0;
  }


  if(val>root->info){
       remove(root->right,val);
  }
  else if(val<root->info){
     remove(root->left,val);
  }

  // case 1 no child
  else {
        if(root->left==NULL && root->right==NULL){
         delete root;
         root=NULL;
         }
         // case 2
         else if(root->left==NULL){
           node *temp=root;
           root=root->right;
           delete temp;
         }
          else if(root->right==NULL){
           node  *temp=root;
            root=root->left;
            delete temp;
          }
          // case 3
          else {
           node *temp=findmin(root->right);
             root->info=temp->info;
           root->right=  remove(root->right,temp->info);
          }
}
return root;

}


// function that use in removing function
node* tree :: findmin(node *&root){
  while(root->left!=NULL){
   root=root->left;
  }
  return root;
}




int main(){
   tree obj;
   obj.option();

    return 0;
}
