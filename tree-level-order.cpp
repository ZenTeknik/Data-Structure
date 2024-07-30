#include<iostream>
#include<queue>
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


void 
int main(){


return 0;
}
