#include<iostream>

using namespace std;

class student{
private: 
string name;
int age;

public:


void data(){
cout<<"Enter the name : "<<endl;
cin>>name;
cout<<"Enter the age : "<<endl;
cin>>age;
}

void display(){
cout<<"Name : "<<name<<endl;
cout<<"Age : "<<age<<endl;
}




};



int main(){
int size;
cout<<"Enter the size how many student u wanna add : "<<endl;
cin>>size;

student *su=new student[size];

cout<<"Enter the data : "<<endl;
for(int i=0;i<size;i++){
 su->data();
 }
 
 
 cout<<"Enter the data : "<<endl;
for(int i=0;i<size;i++){
 su->display();
 }
 
 
 

delete[] su;
return 0;
}
