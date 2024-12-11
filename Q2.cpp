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
    void inorder(node *&root);
    int height(node *&root);
    node* remove(node *&root,int val);
    node* findmin(node *&root);
    void  search(node *&root,int key);
};



tree :: tree(){
    root=temp=NULL;
}


tree :: ~tree(){
    while(root!=NULL){
      delete root->left;
      delete root->right;
      root=NULL;
      root->left=NULL;
      root->right=NULL;
    }
}



// function for the option
void tree :: option() {
    int choice,val,key;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insert    " << endl;
        cout << "2) Inorder   " << endl;
        cout << "3) Height    " << endl;
        cout << "4) Remove :  " << endl;
        cout<<"5)  Search Node :"<<endl;
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
                inorder(root);
                break;
            case 3:
                cout<<"Height of Tree : "<<height(root)<<endl;
                break;

            case 4:
                cout<<"Enter the key to remove : "<<endl;
                cin>>val;
                remove(root,val);
                break;


            case 5:
                cout<<"Enter the key to search  : "<<endl;
                cin>>key;
                search(root,key);
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






void tree :: search(node *&root,int key){
   if(root==NULL){   // for the return
    return;
   }

if(root->info<key){
        search(root->left,key);
}
else if (root->info>key){
    search(root->right,key);
}

}



int main(){
    tree obj;
    obj.option();

    return 0;
}
