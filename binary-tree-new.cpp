#include<iostream>
using namespace std;

struct node{
int info;
node * left,*right,*root;
};

class tree{
public:
tree();
~tree();
void option();
void preorder();
void postorder();
void inorder();
void levelorder();
};


// constructer
tree :: tree(){
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
void tree : option(){
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

}
else if(choice==2){


}
else if(choice==3){

}
else if(choice==4){

}
else if(choice==0){
break;
}
else{
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}





int main(){


return 0;
}
