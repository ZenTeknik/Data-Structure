#include<iostream>
#define max 7
using namespace std;





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
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}




void st :: insert(){
   if(top-arr==max){
   cout<<"Stack is full : "<<endl;
    return;
}
cout<<"Enter the info : "<<endl;
cin>>*top;
top++;
}






void st :: peek(){
   if(top==arr){
       cout<<"Empty Stack : "<<endl;
       return;
}
cout<<"Top Info : "<<*(top-1)<<endl;
}







void st :: remove(){
 if(top==arr){
 cout<<"Empty Stack : "<<endl;
    return;
}

cout<<"LIFO (Key Removed : )"<<*(top-1)<<endl;
top--;
}






int main(){
    st obj;

    obj.option();

    return 0;
}
