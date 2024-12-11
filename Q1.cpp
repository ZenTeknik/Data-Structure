#include<iostream>
using namespace std;



struct node{
    int info;
    node *next;
};

// here in this code  we are the parking the car  in a queue but display  car in the link list 
class link{
private:
    node *head,*temp,*temp1,*current,*headwt,*tempwt,*tempwt1;
    int listsize,waitningsize;
public:
    link();
    ~link();
    void option();
    void insert();
    void show();
    void remove();
    void waitingQueue();
    void  waitingshow();
};


link :: link(){
head=temp=temp1=headwt=tempwt=tempwt1=NULL;
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
        cout << "1)  Park car (Enter the car number) " << endl;
        cout << "2)  Display Car in Queue :  " << endl;
        cout << "3)  Display Car in Waiting  Queue :  " << endl;
        cout << "4)  Exit  the car form Parking : " << endl;
        cout << "0)  Exit Programm : " << endl;
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
                waitingshow();
                break;
            case 4:
                remove();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}



// here am using the queue to manage the vehicles that currecntly in the parking area 
void link :: insert(){
temp=head;
 //   the size of this parking area is  just 5 if it's  full it gonna add in the waitingQueue
if(listsize<=5){
  if(head==NULL){
  head=new node;
  cout<<"Enter the car number : "<<endl;
  cin>>head->info;
  head->next=NULL;
  listsize++;
  return;
  }




while(temp->next!=NULL){
temp=temp->next;
}
// here is the limit of the 5 cars  to be park in the queue 

temp1=new node;
cout<<"Enter the car Number: "<<endl;
cin>>temp1->info;
temp1->next=NULL;
temp->next=temp1;
 }
else {
    waitingQueue();     // here waiting queue is th funtion to add cars in the waiting queue
}
listsize++;
}



// here is the function that shows the car the currently in the queue 
void link :: show(){
temp=head;
   if(head==NULL){
   cout<<"Empty : "<<endl;
   return;
   }

  while(temp!=NULL){
    cout<<"Car Number  : "<<temp->info<<endl;
    temp=temp->next;
  }
  cout<<endl;
}





// here is the exit the car from the parking
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




// here is the function that reserved the place of the car if the parking slot id full
 void link :: waitingQueue(){
    tempwt=headwt;

    if(headwt==NULL){
        headwt=new node;
        cout<<"Enter the car number : "<<endl;
        cin>>headwt->info;
        headwt->next=NULL;
        listsize++;
        return;
    }




    while(tempwt->next!=NULL){
        tempwt=tempwt->next;
    }
    // here is the limit of the 5 cars  to be park in the queue

    tempwt1=new node;
    cout<<"Enter the car Number: "<<endl;
    cin>>tempwt1->info;
    tempwt1->next=NULL;
    tempwt1->next=tempwt1;
    waitningsize++;

}



// here is the function to show car that are in the waiting Queue
void link :: waitingshow(){
    tempwt=headwt;
    if(headwt==NULL){
        cout<<"Empty : "<<endl;
        return;
    }

    while(tempwt!=NULL){
        cout<<"Car Number  : "<<tempwt->info<<endl;
        tempwt=tempwt->next;
    }
    cout<<endl;
}





int main(){
link obj;
obj.option();
return 0;
}



