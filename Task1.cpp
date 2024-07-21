#include<iostream>
#include<cstring>
using namespace std;

int main(){
int *intptr=new int;
char *namestr=new char[8];
*intptr=375;
strcpy(namestr,"DataStr");

cout<<"*intptr :"<<intptr<<endl;

for(int i=0;i<8;i++){
cout<<"Address :"<<(void*)(namestr+i)<< " Value : "<<*(namestr+i)<<endl;

}

delete intptr;
delete[] namestr;
return 0;
}
