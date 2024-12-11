#include<iostream>
#include<string>
using namespace std;


struct node{
    char info;
    node * next;
};




class st{
private:
    node *top,*temp;

public:

    st();
    int precedence(char c);
    bool isOperand(char c);
    string infixTopostfix(string s);
    bool isEmpty();
    void push(char val);
    char pop();
    char peek();
    int evaluatePostfix(string postfix);
};




// constructer
st :: st(){
    top=temp=NULL;
}




// function to push the element into stack
void st :: push(char val){
    node * newnode=new node;
    newnode->info=val;
    newnode->next=top;
    top=newnode;
}


// function to pop  the element from the stack
char st :: pop(){

    if(isEmpty()){
        cout<<" Stack is empty : "<<endl;
        return 0;
    }

    temp=top;
    char popval=top->info;
    top=top->next;
    delete temp;
    return popval;
}



// fucntion to check stack is empty or not
bool  st ::  isEmpty(){
    return top==NULL;
}



// function for the getting the top element
char st ::  peek(){
    if(!isEmpty()){
        return top->info;
    }
    else{
        return  0;
    }
}




// function to set the precedence
int  st :: precedence(char c){
    // higest precedence
    if(c=='^'){
        return 3;
    }

    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }

    else {
        return -1;
    }
    return 0;
}



// function for the operand
bool  st :: isOperand(char c ){
    return ((c>='A' && c<='Z' ) || (c>='a' && c<='z' ) || (c>='0' && c<='9' ));
}




// function for coverting  the expression form infix to postfix
string  st :: infixTopostfix(string s){
    st  obj;                // st is the class (obj is to hold the operator)
    string postfix;        // using for the result



    for(int i=0;i<s.length();i++){
        char currentchar=s[i];

        //according to the rule of postfix  the operand will be append
        if(isOperand(currentchar)){
            postfix+= currentchar;
        }
        else if(currentchar=='('){                 // here if there  is opening brackets like then we have to push into stack
            obj.push(currentchar);
        }

        else if(currentchar== ')'){  // if we have find cloing brackets into the expression when we have to pop from   the  stack
            while(!obj.isEmpty()  && obj.peek()!='('){
                postfix+= obj.peek();
                obj.pop();
            }
            obj.pop();
        }
        // here  the check the operator precedence like greater or less preecedence
        else {
            while(!obj.isEmpty()  && precedence(obj.peek())  >=  precedence(currentchar)){
                postfix += obj.peek();
                obj.pop();
            }
            obj.push(currentchar);
        }
    }


    // here for all the remaining elements
    while(!obj.isEmpty()){
        postfix += obj.peek();
        obj.pop();
    }

    return postfix;
}




// function to evaluate the postfix
// function to evaluate the postfix
int st :: evaluatePostfix(string postfix){
    st evaluate;

    int operand1;
    int operand2;
    int result;

    for(int i=0;i<postfix.length(); i++){
        char currentchar=postfix[i];

        if(isOperand(currentchar)){
            evaluate.push(currentchar-'0');
        }
        else{
            operand2=evaluate.pop();
            operand1=evaluate.pop();



            switch(currentchar){
                case '+':
                    result = operand1 + operand2;
                    evaluate.push(result);
                    break;
                case '-':
                    result = operand1 - operand2;
                    evaluate.push(result);
                    break;
                case '*':
                    result = operand1 * operand2;
                    evaluate.push(result);
                    break;
                case '/':
                    if(operand2 == 0) {   // if there is 0 in the operand then i will give as  the result zero
                        result=0;
                    } else {
                        result=operand1/operand2;
                    }
                    evaluate.push(result);
                    break;
                default:
                    // like invalid operater
                    result=0;
            }
        }
    }

    result=evaluate.pop();  // Final result
    return result;
}





// main function
int main() {
    st obj;
    int result=0;

    // string s="A+B*C-D";
    // string s="A+B*C-D";  test cases
    //string s="(A+B)*(C/D)-E";   //test cases
    string s="6+3*4";
    string postexp=obj.infixTopostfix(s);
    result=obj.evaluatePostfix(postexp);

    cout<<"Postfix expression : "<<postexp<<endl;
    cout<<"Result : "<<result<<endl;

    return 0;
}




