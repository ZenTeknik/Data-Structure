#include<iostream>
#include<queue>
#include<climits>              // smallest and largest possible integers
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
    void currentlevel(node *root,int level);
    void  printlevelorder(node *&root);
    bool isBSTUtil(node *root, int minVal, int maxVal);
    void BstorNot(node *&root);
    bool completeBinary(node *&root);
    bool strictlybinary(node *&root);
};



tree :: tree(){
    root=temp=NULL;
}


tree :: ~tree(){

}



// function for the option
void tree :: option() {
    int choice,val,level;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insert    " << endl;
        cout << "2) preorder  " << endl;
        cout << "3) postorder " << endl;
        cout << "4) Inorder   " << endl;
        cout << "5) Height    " << endl;
        cout << "6) Nodes Count : " << endl;
        cout << "7) Remove :  " << endl;
        cout << "8) Current level Printing  :  " << endl;
        cout << "9) Level Order Traversal :  " << endl;
        cout << "10) BSt or not :  " << endl;
        cout << "11) Complete BSt or not :  " << endl;
        cout << "12) Strictly Binart Tree  or not :  " << endl;
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
            case 8:
                cout<<"Enter the level to print : "<<endl;
                cin>>level;
                currentlevel(root,level);
                break;

            case 9:
                printlevelorder(root);
                break;
            case 10:
                BstorNot(root);
                break;

            case 11:
                if(completeBinary(root)){
                  cout<<"Tree is complete Binary Tree : "<<endl;
                }
                else{
                cout<<"Tree is not Complete Binary tree : "<<endl;
                }
                break;

                case 12:
                if(strictlybinary(root)){
                    cout<<"Tree is Strictly  Binary Tree : "<<endl;
                }
                else{
                    cout<<"Tree is not Strictly Binary tree : "<<endl;
                }
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






// function for the level order traversal
void tree :: printlevelorder(node *&root){

    queue<node *> q;
    q.push(root);

while(q.empty()==false){

    node *root=q.front();
    cout<<root->info<<" ";
    q.pop();

if(root->left!=NULL){
      q.push(root->left);
}
if(root->right!=NULL){
      q.push(root->right);
    }
  }
}



// function to print  the desigenated level
void tree :: currentlevel(node *root,int level){
  if(root==NULL){
   return;
 }


if(level==1){
 cout<<"level : "<<level<<":"<<root->info<<endl;
}
else if(level>1){
    currentlevel(root->left,level-1);
    currentlevel(root->right,level-1);
  }
  cout<<endl;
}




// function to check the bst or not
bool tree::isBSTUtil(node *root,int minVal,int maxVal) {
    // An empty tree is a BST
    if (root==NULL){
        return true;
}
    // The current node's value must be in the range (minVal, maxVal)
    if (root->info<=minVal || root->info>=maxVal){
      return false;
    }
    // Recursively check the left and right subtrees
    return isBSTUtil(root->left,minVal,root->info) && isBSTUtil(root->right,root->info,maxVal);
}

// Wrapper function to check if the tree is a BST or not
void tree::BstorNot(node *&root) {
    if (isBSTUtil(root, INT_MIN, INT_MAX)) {
        cout <<"The tree is a Binary Search Tree (BST)."<<endl;
    } else {
        cout <<"The tree is NOT a Binary Search Tree (BST)."<< endl;
    }
}




// function to check complete   binary or not
bool tree :: completeBinary(node *&root){

queue<node*> q;

bool foundempty=false;

q.push(root);

  while(!q.empty()){

       node *root= q.front();
       q.pop();

// checking for  the left child
    if(root->left!=NULL){
       if(foundempty){
       return false;
       }
       q.push(root->left);
    }
   else{
        foundempty=true;
   }

   // checking for the right subtree
   if(root->right!=NULL){
       if(foundempty){
           return false;
       }
       q.push(root->right);
   }
   else{
       foundempty=true;
   }
}
return true;
}




//  function to check the tree is a strictly complete binary tree  or not
bool tree :: strictlybinary(node *&root){

   if(root->left==NULL && root->right==NULL){
     return false;
}

 if(root->left!=NULL  && root->right!=NULL) {
    return strictlybinary(root->left) &&  strictlybinary(root->right);
  }
return false;
}



int main(){
   tree obj;
   obj.option();

    return 0;
}
