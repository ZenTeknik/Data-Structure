#include <iostream>
#include <random>

#define lowerRange 0x1000  // lower_range according to the requirements
#define upperRange 0xFFFF   // upper_range according to the requirements
using namespace std;

struct PCB {
int processID;
int parentID;
string processState;
int priority;
unsigned int stackAddress;
unsigned int heapAddress;
PCB *next;
};


// Function to generate random addresses for stack and heap within the range
unsigned int randomAddress() {
    random_device ran;           //  i didnt know how to find random number unsing random library  i take help form satckoverflow     here  "random_device"   is the class in the random library  "ran" i have creted the object 
    mt19937 gen(ran());        // according to random library  mt19937 is  the algorithm on which bases random library generating random number 
    uniform_int_distribution<> distr(lowerRange, upperRange);     // at the above   i defined lower range and upper range 
    return distr(gen);
}



// Class to control all processes
class Manager {
private:
    PCB *head, *temp, *temp1;
public:
Manager();
//~Manager();  
void option();
void Addprocess(int ID, string state, int priority, int parentID = 0);
void RemoveProcess(int ID);
void DisplayAllprocess();
void killAllprocess();
void killParentprocess(int parentID);
void killChildprocess(int parentID);
int getParentID(int ID);
void getAllchildID(int parentID);
void fork(int parentID);
};




// Constructor
Manager :: Manager() {
    head=temp=temp1= NULL;
}



// Function for user options
void Manager :: option() {
int choice;
string state;
int ID, priority, parentID;
 do {
cout << "_____PCB_____" << endl;
cout << " 1)  ADD PROCESS : " << endl;
 cout << " 2)  REMOVE  PROCESS : " << endl;
cout << " 3)  DISPLAY  PROCESS  LIST : " << endl;
 cout << " 4)  KILL ALL PROCESS  : " << endl;
 cout << " 5)   KILL PARENT PROCESS : " << endl;
 cout << " 6)   KILL CHILD  PROCESS : " << endl;
 cout << " 7)   GET PARENT ID : " << endl;
cout << " 8)   GET ALL CHILD PID  : " << endl;
 cout << " 9)   FORK   : " << endl;
 cout << " 0)  EXIT  : " << endl;
cout << " Enter your choice : " << endl;
cin >> choice;

 if (choice==1) {
            cout << " Enter the process ID : " << endl;
            cin >> ID;
            cout << " Enter the process State : " << endl;
            cin >> state;
            cout << " Enter the process Priority  : " << endl;
            cin >> priority;
            Addprocess(ID, state, priority, parentID);
 } else if (choice==2) {
            cout << " Enter the process ID to remove :  " << endl;
            cin >> ID;
            RemoveProcess(ID);
} else if (choice==3) {
            DisplayAllprocess();
} else if (choice==4) {
            killAllprocess();
} else if (choice==5) {
            cout << "Enter the parent ID : " << endl;
            cin >> parentID;
            killParentprocess(parentID);
} else if (choice==6) {
            cout << "Enter the parent ID : " << endl;
            cin >> parentID;
            killChildprocess(parentID);
 } else if (choice==7) {
            cout << "Enter the ID : " << endl;
            cin >> ID;
            int parentID = getParentID(ID);
            cout << "Parent ID: " << parentID << endl;
} else if (choice==8) {
            cout << "Enter the parent ID : " << endl;
            cin >>parentID;
            getAllchildID(parentID);
} else if (choice==9) {
            cout << "Enter the parent ID : " << endl;
            cin >> parentID;
            fork(parentID);
 } else if (choice==0) {
            break;
} else {
            cout << "Invalid Choice : " << endl;
        }
    } while (choice!=0);
}



// Function for adding a process
void Manager :: Addprocess(int ID, string state, int priority, int parentID) {
    temp=head;

    // Check if PID already exists
    while(temp != NULL) {
        if(temp->processID == ID) {
            cout << " Process ID already exists : " << endl;
            return;
        }
        temp = temp->next; 
    }

    // Creating the new node to add
    PCB *newNode=new PCB;
    newNode->processID=ID;
    newNode->processState = state;
    newNode->priority = priority;
    newNode->stackAddress = randomAddress();
    newNode->heapAddress= randomAddress();
    newNode->parentID =parentID;
    newNode->next=head; 
    head=newNode;      

    cout << " PROCESS ADDED SUCCESSFULLY !   ID : " << ID << endl;
}



// Displaying all processes
void Manager  :: DisplayAllprocess() {
    temp=head;

    if (temp==NULL) {
        cout<<" No process ID : " << endl;
        return;
    }

while(temp!=NULL) {
        cout << " Process ID : " << temp->processID << endl;
        cout << " Parent ID : " << temp->parentID << endl;
        cout << " State : " << temp->processState << endl;
        cout << " Priority : " << temp->priority << endl;
        cout << " Stack Address : " << hex << temp->stackAddress << endl;
        cout << " Heap Address : " << hex << temp->heapAddress << endl;

        temp=temp->next; 
    }
    cout << endl;
}


// Function for getting the parent ID
int Manager  ::  getParentID(int ID) {
    temp = head;

    while(temp != NULL) {
        if(temp->processID == ID) {
            return temp->parentID; // parent ID found   or not
        }
        temp =temp->next; 
    }
    return -1; 
}


// Function for getting all child IDs
void Manager  :: getAllchildID(int parentID) {
    temp=head;

    while(temp!=NULL) {
        if(temp->parentID == parentID) {
            cout << temp->processID << " "; 
        }
        temp=temp->next; 
    }
    cout<<endl;
}


// Function to kill all parent processes
void Manager  ::  killParentprocess(int parentID) {
    RemoveProcess(parentID);    // Remove parent process
    killChildprocess(parentID); // Kill child processes
}



// Function for killing all child processes
void Manager  ::  killChildprocess(int parentID) {
    temp=head;
    temp1=NULL;

    while(temp!=NULL) {
        if(temp->parentID == parentID) {
            int child = temp->processID;
            PCB *nextNode = temp->next; 
            RemoveProcess(child); // Remove child process
            temp = nextNode; 
        } 
else {
      temp = temp->next; 
        }
    }
cout << endl;
}


// Function for removing a process
void Manager   ::   RemoveProcess(int ID) {
    temp=head;

    // head is NULL
    if (temp==NULL) {
        cout << "No Process ID to Remove : " << endl;
        return;
    }

    // For the head itself
    if(temp->processID==ID) {
        head = temp->next; 
        delete temp; 
        return;
    }

   
    while(temp!=NULL && temp->processID!=ID) {
        temp1=temp; 
        temp=temp->next; 
    }

    
    if (temp==NULL) {
        cout<<"Process ID not found : " << endl;
        return;
    }

    
    temp1->next = temp->next;
    delete temp; 
    cout << "Process ID removed successfully : " << ID << endl;
}




// Function to kill all processes
void Manager :: killAllprocess() {
    while (head != NULL) {
        RemoveProcess(head->processID);  // here we are adding every new node to the head so also deleting the each process ID form head 
    }
    cout << "All processes killed." << endl;
}


// Function to fork a process  with the paretn ID as same state and priority but with differnet addresses 
void Manager   ::      fork(int parentID) {
    temp =head;

    while(temp != NULL) {
        if(temp->processID == parentID) {
            int newProcessID = temp->processID + 1;   // +1 like to increment to the IDs first ID then ++ etc 
Addprocess(newProcessID, temp->processState, temp->priority, parentID); // calling the addprocess function for  again creating  the child process 
            cout << "Forked new process " << endl;
            return;
        }
        temp=temp->next; 
    }

    cout << "ID Not found " << endl;
}



// Main function
int main() {
    Manager manager;
    
    manager.option();  // here option function for the testing 
return 0;
}

