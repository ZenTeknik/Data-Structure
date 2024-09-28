#include<iostream>
using namespace std;



int main(){
 int arr2D[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
};


int i,j,k;
int ***arr3D;
arr3D=new int **[2] ; // for the layees dynamically allocation 
for(i=0;i<2;i++){
arr3D[i]=new int*[3];         // for the 3 rows 
     for(j=0;j<3;j++){
    arr3D[i][j]=new int[4];    // for the 4 coloums
    }
}



// copying the elements from 2D to 3D
for (j=0;j<3;j++) { // Traverse rows
        for (k=0;k<4;k++) { // Traverse columns
            arr3D[0][j][k]=arr2D[j][k]; // Copy 2D array to the first layer of 3D array
        }
    }

    // Fill the second layer with zeros
    for (j=0;j<3;j++) {
        for (k=0;k<4;k++) {
            arr3D[1][j][k] = 0; // Set all elements in the second layer to 0
        }
    }



// printing the array 3D
cout<<"Printing Element  3D : "<<endl;
for( i=0;i<2;i++){
    for(j=0;j<3;j++){
         for(k=0;k<4;k++){
  cout<<arr3D[i][j][k]<<" ";        
   }
   cout<<endl;
  }
  cout<<endl;
}




// deallocation of the array 3D
for( i=0;i<2;i++){
    for(j=0;j<3;j++){        
  delete[] arr3D[i][j];       // deallocation for each row  and coloums 
   }
   delete[] arr3D[i];       // deallocation for each row
  }
  delete[] arr3D;            // deallocation for the whole matrix 


return 0;
}
