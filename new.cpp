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
void deletion(node *root);
void insert(node *&root,int key );
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);
void levelorder(node *root);
};

int main(){



return 0;
}

