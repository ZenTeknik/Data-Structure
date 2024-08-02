#include<iostream>
#include<queue>
using namespace std;

struct node{
int info;
node *left,right;
};

class tree{
private:
node *root;
public:

tree();
~tree();
void deleteion(node * root);
void option();
void insert(key);
void preorder(node *root);
};




int main(){



return 0;
}
