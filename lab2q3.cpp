#include<iostream>
#include<cstdlib>

// fucntion prototypes
void matrix(int **month,int sizerow,int sizecol);

using namespace std;

int main(){

int sizerow=4;
int sizecol=7;


int **month;

// for rows 
month=new  int*[sizerow];

// for  coloums 
for(int i=0;i<sizecol;i++){
month[i]=new int[sizecol];
}




matrix(month,sizerow,sizecol);


delete[] month;
return 0;
}


// taking random value in the matrix 
void matrix(int **month,int sizerow,int sizecol){


for(int i=0;i<sizerow;i++){
   for(int j=0;j<sizecol;j++){
    month[i][j]=10+rand()%21;
}
}


for(int i=0;i<sizerow;i++){
   for(int j=0;j<sizecol;j++){
    cout<<month[i][j]<<" ";
}
cout<<endl;
}
}



void temp(int **month,int sizerow,int sizecol){



}




