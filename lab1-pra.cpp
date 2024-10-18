#include<iostream>
using namespace std;

class student{
private:
string name;
int rollnum;
string grade;
public:
// constructer
student(string name,int rollnum,string grade ){
this->name=name;
this->rollnum=rollnum;
this->grade=grade;
}
// getter 
string getname(){
return name;
}

int getrollnum(){
return rollnum;
}

//setter
string getgrade(){
return grade;
}


void  setname(string name){
this->name=name;
}

void  setrollnum(int rollnum){
this->rollnum=rollnum;
}

void  setgrade(string garde){
this->grade=grade;
}


void display(){
cout<<"Name : "<<name<<endl;
cout<<"Roll Number : "<<rollnum<<endl;
cout<<"Grade : "<<grade<<endl;
}

};



class teacher{
private:
string name;
string sub;
int yearexp;

public:

teacher(string name,string sub,int yearexp ){
this->name=name;
this->sub=sub;
this->yearexp=yearexp;
}
// getter 
string getname(){
return name;
}

string getsub(){
return sub;
}

int  getyearexp(){
return yearexp;
}

// setter
void  setname(string name){
this->name=name;
}

void   setsub(string  sub ){
this->sub=sub;
}

void  setyearexp(int  yearexp){
this->yearexp=yearexp;
}

void display(){
cout<<"Name : "<<name<<endl;
cout<<"Subject  : "<<sub<<endl;
cout<<"Year of Experience  : "<<yearexp<<endl;
}

};



class principal : public teacher {
public:
int yearsofPrin;


principal( string nam, string su, int ep,int yearsofPrin) : teacher(nam,su,ep) , yearsofPrin(yearsofPrin){
}

void display(){
teacher :: display();
cout<<"Year of experience(Principle) : "<<yearsofPrin<<endl;
}

};

int main(){


student p1("Haris",2445,"A");
p1.display();



// for the pricipal class 
principal b("Ali","DS",5,9);
b.display();



// mdoification of teacher s
string name;
string sub;
int yearexp;

cout<<"Name : "<<name<<endl;
cin>>name;
cout<<"Subject  : "<<sub<<endl;
cin>>sub;
cout<<"Year of Experience  : "<<yearexp<<endl;
cin>>yearexp;

teacher obj(name,sub,yearexp);
obj.display();

return 0;
}
