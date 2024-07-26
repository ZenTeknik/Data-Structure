#include<iosteram>
using namespcace std;

class queue{
private:
int *arr,*front,*temp,count,limit,size;
public:
queue();
~queue();
void option();
void enqueue();
//void dequeue();
};

queue :: queue(){
front=temp=arr=NULL;
size=0;
count=0;
limit=size;
}

queue :: ~queue(){
delete front;
delete temp;
delete[] arr;
}


void queue :: option(){
int choice; 
do{
cout<<" Avalible option : "<<endl;
cout<<"1) insert : "<<endl;
//cout<<"2) remove : "<<endl;
cout<<"3) print : "<<endl;
cout<<"0) exit : "<<endl;
cout<<"Enter your choice : "<<endl;
cin>>choice;

if(choice==1){
enqueue();
}
//else if(choice==2){
//dequeue();
//}
else if(choice==3){
print();
}
else if(choice==0){
break;
}
else {
cout<<"Invalid choice :"<<endl;
}
}while(choice!=0);

}


void queue :: enqueue(){
front=temp=arr[0];

if(front==NULL){
cout<<"Enter the element in the array : "<<endl;
cin>>*arr;
*arr++;
count++;
return;
}

if(count<=size){
while(front!=size){
cout<<"Enter the element : "<<endl;
cin>>*arr;
*arr++;
count++;
}
}
cout<<"NO space avalibe in the queue : "<<endl;
}






int main(){

queue obj;
int size;
cout<<"Enter the size of queue : "<<endl;
cin>>obj.size;

obj.arr=new int[size]
return 0;
}
