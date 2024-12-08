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
        head->next=head;
        listsize++;
        return;
  }


  while(temp->next!=head){
       temp= temp->next;
}
temp1=new node;
cout<<"Enter the info : "<<endl;
cin>>temp1->info;

temp1->next=head;
temp->next=temp1;
listsize++;
}


void link :: show(){
temp=head;
  if(head==NULL){
  cout<<"Empty : "<<endl;
  return;
  }

  do{
      cout<<temp->info<<" ";
      temp= temp->next;
}while(temp!=head);
cout<<endl;
}



// void  link :: remove(){
//   temp=head;
//     if(head==NULL){
//     cout<<"Empty : "<<endl;
//     return;
//     }
//
// int pos,count=1;
// cout<<"Enter the pos : "<<endl;
// cin>>pos;
//
//    while(temp->next!=head){
//       if(count==pos){
//           temp->next=temp1;
//           temp->next->next=temp->next;
//         delete temp1;
//     }
//     count++;
//     temp=temp->next;
//    }
// }




void link :: remove(){
current=head;

int key;
cout<<"Enter the key : "<<endl;
cin>>key;

while(listsize>1){

    for(int i=1;i<key;i++){
        temp=current;
     current=current->next;
    }

     if (current == head) {
         head = head->next;

    }
      temp->next = current->next;
      delete current;
      listsize--;
      current = temp->next;
}
cout<<head->info<<" ";
}





int main(){
    link obj;

    obj.option();

    return 0;
}
