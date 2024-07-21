// Doubly Linked List 

// each item allocated space as it is added to the list.  
// Each node  of the list has three element 
// (data,next pointer, previous pointer)

// simply doubly linked list can go back also as it move next using pointer
// on the both end they have  NULL (head with NULL) & (end with also NULL)



struct node{
int info;
node *next;       // here next for go next 
node *previous;   // here previous for go previous
};

  
  
void add(){
temp=head;
if(head==NULL){
head=new node;

cout<<"Enter element  in head : "<<endl;
head->next=NULL;
previous->next=NULL;
return;
}
int key;
temp=head;
cout<<"After which key u wannt to add the code  : "<<endl;
cin>>key;

while(temp!=NULL){
if(temp->info==key){
temp1=new node;
cout<<"Enter the element : "<<endl;
cin>>temp1->info;

temp1->next=temp->next;
temp->next=temp1;
temp1->previous=temp;
if(temp->next!=NULL){
temp1->next->prev=temp1;
}
}
temp=temp->next;
}



void remove(){
temp=head;
int key;
if(head==NULL){
cout<<"No element to remove :"<<endl;
}

cout<<"Enter the key :"<<endl;
cin>>key;

if(head->info==key){
temp1=head;
head=head->next;
delete temp1;
}

while(temp!=NULL){
if(temp->info==key){
temp1=temp->previous;

if(temp->next!=NULL){
temp->previous->next=temp->next;
}
if(temp->next!=NULL){
temp->next->previous=temp->previous;
}
delete temp;
temp=temp1;

}
temp=temp->next;
}




//
