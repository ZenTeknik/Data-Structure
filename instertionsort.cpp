#include<iostream>
using namespace std;


void  instertionsort(int A[],int n){
int j, i,key;

for(j=1;j<n;j++){
 key=A[j];
 i=j-1;

while(i>=0  && A[i]>key){
  A[i+1] =A[i];
  i=i-1;
}
A[i+1]=key;
}
}



int main(){

int A[5]={5,4,3,1,2};
int n=4;

instertionsort(A,n);

for(int i=0;i<n;i++){
   cout<<A[i]<<" ";
}

return 0;
}
