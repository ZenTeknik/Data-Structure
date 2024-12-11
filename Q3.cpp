#include<iostream>
#define max 7        // here i suppose the random size user can take as he want
using namespace std;



// here am doin the Q3  stack using array

class st{
private:
    int *arr,*top,*temp;
public:
    st();
    ~st();
    void option();
    void insert();
    void peek();
    void remove();
    void  displayprime();
};


st :: st(){
    arr=new  int[max];
    top=arr;
}

st :: ~st(){
    delete []arr;
}




void st :: option() {
    int choice;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insert " << endl;
        cout << "2) Top" << endl;
        cout << "3) Remove " << endl;
        cout << "4) display Prime " << endl;
        cout << "0) Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                peek();
                break;
            case 3:
                remove();
                break;
            case 4:
               displayprime();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}



// here is the function to insert value in the stack
void st :: insert(){
    if(top-arr==max){
        cout<<"Stack is full : "<<endl;
        return;
    }
    cout<<"Enter the info : "<<endl;
    cin>>*top;
    top++;
}





// here is the function to check  the top value of the stack
void st :: peek(){
    if(top==arr){
        cout<<"Empty Stack : "<<endl;
        return;
    }
    cout<<"Top Info : "<<*(top-1)<<endl;
}






// here is the funciton to remove value from the stack
void st :: remove(){
    if(top==arr){
        cout<<"Empty Stack : "<<endl;
        return;
    }

    cout<<"LIFO (Key Removed : )"<<*(top-1)<<endl;
    top--;
}




// here is the function to display all the prime number i nthe stack
void st :: displayprime(){
   while(arr!=NULL){
        if(*top%2==1){   // bcz, in the case of the prime number    the rmeinder is always be 1 for evry value
           cout<<"Prime Number : "<<endl;
        }

    top--;      // one by one its pop  the element form the array and check weather its prime  number or not

   }
}




int main(){
    st obj;

    obj.option();

    return 0;
}
