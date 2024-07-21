/*
#include<iostream>
using namespace std;


void fun(int x);
int main(){

int x=3;
fun(x);


return 0;
}


void fun(int x){
if(x>0){
fun(x-1);
cout<<x<<endl;

}
}
*/



/*
#include<iostream>
using namespace std;
int fun(int x);



int main(){
int x=5;
cout<<fun(x)<<endl;


return 0;
}

int n=0;
int fun(int x){
 

if(x>0){
n++;
return fun(x-1)+n;
}
return 0;
}


*/

// TREE recursion 
#include<iostream>
using namespace std;

int fun(int x);
int main(){
int x=3;

fun(x);


return 0;
}


int fun(int x){

if(x>0){
cout<<x<<endl;
fun(x-1);
fun(x-1);
}
return 0;
}
