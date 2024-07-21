#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node *prev;
};


class  list{
private: 
node *head;
node *temp,*temp1,*min,*max;

public: 
list();
~list();
void option();
void print();
void length();
void add();
void remove();
void mini();
void maxi();
void search();

};



int main(){

return 0;
}
