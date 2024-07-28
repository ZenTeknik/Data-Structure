#include<iostream>
using namespace std;
int n=5;
int front=-1;
int rear=-1;
int arr[n];

void enqueue(int x);
void dequeue();
void print();
void peek();
void option();



int main(){


option();

return 0;
}







void option(){
int x;
int choice; 
do{
cout<<"Avalible option : "<<endl;
cout<<"1) enqueue : "<<endl;
cout<<"2) dequeue : "<<endl;
cout<<"3) peek : "<<endl;
cout<<"4) print : "<<endl;
cout<<"0) exit : "<<endl;
cout<<"Enter your choice :"<<endl;
cin>>choice;
if(choice==1){
cout<<"Enter teh value to add : "<<endl;
cin>>x;
enqueue(x);
}
else if(choice==2){
dequeue();
}
else if(choice==3){
peek();
}
else if(choice==4){
print();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid choice : "<<endl;
}

}while(choice!=0);
}


// adding element in the queue 
void enqueue(int x){
if(rear==n-1){
cout<<"Queue is Full : "<<endl;
return;
}
else if(front==-1 && rear==-1){
front=rear=0;
arr[rear]=x;
}
else {
rear++;
arr[rear]=x;
return;
}
}



void dequeue(){

}


void peek(){


}


// fucntion for printing the elements in the queue 
void print(){
if(front==-1 && rear==-1 ){
cout<<"No element in the queue : "<<endl;
return;
}
cout<<"Elements in the array : "<<endl;
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}




