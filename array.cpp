#include<iostream>
using namespace std;



int main(){
int **arr1;
int **arr2;


arr1=new int*[2];
arr2=new int*[2];

for(int i=0;i<2;i++){
arr1[i]=new int[2];
arr2[i]=new int[2];
}


cout<<"Enter the element in the first array : "<<endl;
for(int i=0;i<2;i++){
  for(int j=0;j<2;j++){
  cin>>arr1[i][j];
}
}


cout<<"Enter  the element in the second array : "<<endl;
for(int i=0;i<2;i++){
  for(int j=0;j<2;j++){
  cin>>arr2[i][j];
 }
}


cout<<"Elements in the first array : "<<endl;
for(int i=0;i<2;i++){
  for(int j=0;j<2;j++){
  cout<<arr1[i][j]<<" ";
  }
cout<<endl;
}


cout<<"Elements in the second  array : "<<endl;
for(int i=0;i<2;i++){
  for(int j=0;j<2;j++){
  cout<<arr2[i][j]<<" ";
  }
cout<<endl;
}

for(int i=0;i<2;i++){
delete arr1[i];
delete arr2[i];
}
delete arr1;
delete arr2;



return 0;
}
