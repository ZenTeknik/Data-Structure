#include<iostream>
using namespace std;

struct node{
int info;
node *next;
node *prev;
};



class list {
private:
node *head,*temp,*temp1;
public:
list();
~list();
void option();
void search();

};





int main(){




return 0;
}
