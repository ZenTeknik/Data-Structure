#include<iostream>
#include<string>
using namespace std;

struct node {

char info[15];
};


class trial {
private:
node obj1,*temp1,*temp2,*temp3;
int i,length;
char *p,*q;

public:
trial();  // constructer 
~trial();

void startin();
};

int  main(){


trial lnk;
lnk.startin();



}


// constructer defination 
trial :: trial(){
temp1=temp2=temp3=NULL;
}

trial :: ~trial(){
delete temp1;
delete temp2;
delete temp3;
delete[] p;// array to delete the 10 character 
}


void trial :: startin(){
cout<<"Making use of new and delete operator is as follow :"<<endl;
temp1=new node;
temp2=new node;
cout<<"Enter information about temp1"<<endl;
cin>>temp1->info;
cout<<"Enter the information about temp2 "<<endl;
cin>>temp2->info;


temp3=&obj1;

cout<<"Enter information about temp3 :"<<endl;
cin>>temp3->info;

cout<<"showing information temp1 :"<<temp1->info<<endl;
cout<<"showing information temp2 :"<<temp2->info<<endl;
cout<<"showing information temp3 :"<<temp3->info<<endl;


cout<<"Enter the lenght of character array :"<<endl;
cin>>length;

p=new char[length];   // allocate 10 char 
q=p;

cout<<"Now enter "<<length<<"character to fill an array :"<<endl;

for(int i=0;i<length;i++){
cin>>*p;
p=p+1;
}
p=q;


cout<<"Elements of array are as follow :"<<endl ;
for(int i=0;i<length;i++){
cout<<*p<<" ";
p=p+1;
}
p=q;
}



