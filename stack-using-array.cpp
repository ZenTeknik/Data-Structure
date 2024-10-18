#include<iostream>
using namespace std;




class stack{
private:
int *arr;
int *top;
int listsize=0;
int limit;

public:
stack(int limit);
~stack();
void option();
void push();
void pop();
void print();
};


// constructer
stack :: stack(int limit){
this->limit=limit;
arr=new int[limit];
top=arr;
}

// destructer
stack :: ~stack(){
delete[] arr;
}





// function for the option 
void  stack ::  option(){
int choice;
do{
cout<<"Avalible OPtion  : "<<endl;
cout<<"1) Push : "<<endl;
cout<<"2) Pop : "<<endl;
cout<<"3) print : "<<endl;
cout<<"0) Exit : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
push();
}

else if(choice==2){
pop();
}

else if(choice==3){
print();
}


else if(choice==0){
break;
}
else{
cout<<"Invalid Choice : "<<endl;
}

}while(choice!=0);
}




// function for adding the elements
void stack :: push(){
if(top-arr==limit){
cout<<"Stack Full : "<<endl;
return;
}

int key;
cout<<"Enter the key : "<<endl;
cin>>key;

*top=key;
top++;
listsize++;
}



// function for removing the elements 
void stack :: pop(){
if(top==arr){
cout<<"Empty Stack : "<<endl;
return;
}

top--;
listsize--;
}


// function for printing elements 
void stack :: print(){
if(top==arr){
cout<<"Empty Stack : "<<endl;
return;
}

int *ptr=NULL;
cout<<"Elements in the Stack : "<<endl;
for(int ptr=arr;ptr<top;ptr++){
    cout<<*ptr<< "  ";
    }
ptr++;
cout<<endl;
}







int main(){

int *arr;
int limit;
cout<<"Enter the limit of the stack : "<<endl;
cin>>limit;


stack obj(limit);
obj.option();


return 0;
}
