#include<iostream>
using namespace std;



struct node{
    int info;
    node *next;
};


class link{
private:
    node *head,*temp,*temp1;
public:
    link();
    ~link();
    void option();
    void insert();
    void show();
    void remove();
    void search();
    void update();
};


link :: link(){
    head=temp=temp1=NULL;
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
        cout << "3) Search " << endl;
        cout << "4) Update " << endl;
        cout << "5) Remove " << endl;
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
                search();
                break;
            case 4:
                update();
                break;
            case 5:
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
        return;
    }


    while(temp->next!=head){
        temp=temp->next;
    }

    temp1=new node;
    cout<<"Enter  the info : "<<endl;
    cin>>temp1->info;
    temp1->next=head;
    temp->next=temp1;
}


// function to search
void link :: search(){
    temp=head;
    if(head==NULL){
        cout<<"Empty : "<<endl;
        return;
    }

    int key;
    cout<<"Enter the key : "<<endl;
    cin>>key;

    do{
        if(temp->info==key){
            cout<<"Key exist : "<<endl;
            return;
        }
        temp=temp->next;
    }while(temp->next!=head);
    cout<<"Key not exist : "<<endl;
}


// function to show
void link :: show(){
    temp=head;
    if(head==NULL){
        cout<<"Empty : "<<endl;
        return;
    }

    do{
        cout<<temp->info<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}


// function to insert value bw the nodes
void  link :: update(){
    temp=head;
    if(head==NULL){
        insert();
        return;
    }
    int pos,count=1;
    cout<<"Enter the pos : "<<endl;
    cin>>pos;

    while(temp->next!=head){
        if(count==pos){

            cout<<"Enter the info : "<<endl;
            cin>>temp1->info;
        }
        count++;
        temp=temp->next;
    }
}


// function to remove
void link :: remove(){
    temp=head;
    if(head==NULL){
        cout<<"Empty : "<<endl;
        return;
    }

    int pos,count=1;
    cout<<"Enter  the pos : "<<endl;
    cin>>pos;




    if(pos==1){
        if(head->next=head){
            delete head;
            head=NULL;
        }
        else{
            temp1=temp;
            head=head->next;
            delete temp1;
            return;
        }
}


    while(temp->next!=head){
        if(count==pos){
            temp->next=temp1;
          temp->next->next=temp->next;
          delete temp1;
            return;
        }
        count++;
        temp=temp->next;
    }
}



int main(){
    link obj;

    obj.option();

    return 0;
}
