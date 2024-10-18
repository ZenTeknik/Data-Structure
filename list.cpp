 // list : list is a collection of item that are all of the same type (grocery items, integers,name etc) 
 
 // the items or elements of the list , are stored in some particular order 
 
 // It is possible to insert new elements into various position in the list and remove any element from the list 
 
 // Order :
 // 1) assending 
 // 2) descending 
 // 3) no order   (point : also an order )
 
 // list is a set of liner order . 
 
                  // List Operations 
 // createList(): create  a new list (empty)
 // copy():       set one list to be copy of another 
 // clear():      clear a list (remove all elements)
 // insert(X,?):  insert element X at a particuler position in the list 
 // remove(?):    remove elements at some position in the list 
 // get(?):       get elements at a given position 
 // update(X,?):  replace the elements at a given position eith X
 //find(X) :      determine if the element X in the list 
 // length():     return the length   of the list .
 
 // List Operation (when we use pointers)
 // start(): moves to cuurent pointer to the very first element 
 // tail():  moves to current pointer to the very last element.
 // next():  move the current position forwar one element.
 // back():  move the current positon backward one element.
 
 // ADT(Abstract data Type ) = Data Structure + operation applied on Data_structer 
 // When we have a simple array Data structure it known as array Data strcuture and we called its Data Structure array  ! when the operation applied on this data Structure  when we say that its  Array ADT .
 
 // finding X from the array Data structure 
#include<iostream>
using namespace std;
//prototypes
void find(int num);

int main(){
int arr[5]={1,2,3,4,5};
int num;
int i;
cout<<"Enter the number u wanna find : "<<endl;
cin>>num;
find(num);

return 0;
}


void find(int num){
for( i=0;i<5;i++){
if(arr[i]==num){
break;
}
}

if(i<5){
cout<<"Element Found : "<<endl;
cout<<"Current index : "<<i+1<<endl;
}
else {
cout<<"Not Found :"<<endl;
}

}
