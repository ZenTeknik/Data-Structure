#include<iostream>
using namespace std;



void swap(int &ptr1, int &ptr2){
int temp;
temp=ptr1;
ptr1=ptr2;
ptr2=temp;

}


int main(){
int a=2,b=1;
int *ptr1,*ptr2;
ptr1=&a;
ptr2=&b;

cout<<"The value of a : "<<*ptr1<<endl;
cout<<"The value of b : "<<*ptr2<<endl;

swap(ptr1,ptr2);

cout<<"The value of a : "<<*ptr1<<endl;
cout<<"The value of b : "<<*ptr2<<endl;

return 0;
}

