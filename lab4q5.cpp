#include<iostream>
using namespace std;



int main(){
int row;
int col;

cout<<" Enter the row : "<<endl;
cin>>row;

cout<<"Enter the col :"<<endl;
cin>>col;


int **arr;
arr=new int *[row];

int i,j;
for(i=0;i<col;i++){
arr[i]=new (nothrow) [col];
}




cout<<"Enter the elements in the array : "<<endl;
for(i=0;i<row;i++){
   for(j=0;j<col;j++){
    cin>>arr[i][j];
    }
}


cout<<"Elements in the matrix : "<<endl;
for(i=0;i<row;i++){
   for(j=0;j<col;j++){
    cout<<arr[i][j]<<" ";
    }
    cout<<"Memory Failed : "<<endl;
    cout<<endl;
}




// deallocating the memory 
for(i=0;i<row;i++){
  delete arr[i];
  }
delete[] arr;

return 0;
}
