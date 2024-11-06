
#include<iostream>
using namespace std;

int main(){
int a = 1;
int sum = 0;

while(a <= 10)
{
if(a % 2 == 0)
{
sum += 2;
}
a++;
}

cout<<"SUM : "<<sum<<endl;
return 0;
}



