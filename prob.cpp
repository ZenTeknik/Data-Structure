
// sum of n natural number 
#include<iostream>
using namespace std;

/*
int sum(int n);
int main(){

int n=5;
cout<<sum(n)<<endl;


return 0;
}

int sum(int n){
if(n==0){
return 0;
}
else {
sum(n-1)+n;

}
return 0;
}
*/


// sum of  factorial number 
int fact(int n );
int main(){

int n=5;
cout<<fact(n)<<endl;
return 0;
}


int fact(int n ){
if(n==0){
return 1;
}
else{
return  fact(n-1)*n;
}
return 0;
}
