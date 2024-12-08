#include<iostream>
using namespace std;



struct node{
    int info;
    node *next;
    node *prev;
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
        head->next=NULL;
        head->prev=NULL;
        return;
    }


    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp1=new node;
    cout<<"Enter  the info : "<<endl;
    cin>>temp1->info;
    temp1->next=NULL;
    temp1->prev=temp;
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

    while(temp!=NULL){
        if(temp->info==key){
            cout<<"Key exist : "<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Key not exist : "<<endl;
}


// function to show
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

    while(temp!=NULL){
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
        temp1=temp;
        head=head->next;
        head->prev=NULL;
        delete temp1;
        return;
    }


    while(temp!=NULL){
        if(count==pos){
            temp1=temp;
             if(temp->next!=NULL){
                 temp->next->prev=temp->prev;
            }
            if (temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
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
