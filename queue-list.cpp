#include<iostream>
using namespace std;



struct node{
    int info;
    node *next;
};


class link{
private:
    node *head,*temp,*temp1,*current;
    int listsize;
public:
    link();
    ~link();
    void option();
    void insert();
    void show();
    void remove();
};


link :: link(){
    head=temp=temp1=current=NULL;
}


link :: ~link(){
    while(head!=NULL){
        temp=head;
        head=head->next;
        delete temp;
    }
}




void link :: option() {
    int choice;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insert " << endl;
        cout << "2) Show " << endl;
        cout << "3) Remove " << endl;
        cout << "0) Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                show();
                break;
            case 3:
                remove();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}




void link :: insert(){
temp=head;
  if(head==NULL){
  head=new node;
  cout<<"Enter the info : "<<endl;
  cin>>head->info;
  head->next=NULL;
  listsize++;
  return;
  }


while(temp->next!=NULL){
temp=temp->next;
}

temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
listsize++;
}



void link :: show(){
temp=head;
   if(head==NULL){
   cout<<"Empty : "<<endl;
   return;
   }

  while(temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->next;
  }
  cout<<endl;
}







void link :: remove(){

if(head==NULL){
    cout<<"Empty : "<<endl;
return;
}



 temp=head;
  head=head->next;
  delete temp;
  listsize--;
}






int main(){
    link obj;

    obj.option();

    return 0;
}
