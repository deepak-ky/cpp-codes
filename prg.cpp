#include<iostream>
#include<stdlib.h>
using namespace std;
const int size=50;
class stack
{
  public:
  int elem[size];
  int top;
  stack()
  {
   top=-1;
  }
  void push();
  void pop();
  void reverse();
  void display();
};
void stack :: display()
{
int t;
for(t=top;t>=0;t--)
{
 cout<<"\n"<<elem[t];
}
}
void stack :: push()
{
    int x;
 if(top>=size-1)
 {
  cout<<"Stack Overflow";
 }
 else
 {
 cout<<"Enter the element : ";
 cin>>x;
  top++;
  elem[top]=x;
}
display();
}
void stack :: pop()
{
 if(top<=0)
 {
  cout<<"Stack Underflow";
 }
 else
 {
  elem[top]=elem[top-1];
  top--;
 }
display();
}
void stack :: reverse()
{
int t;
for(t=0;t<=top;t++)
{
 cout<<"\n"<<elem[t];
}
}
int main()
{
int c;
char ch;
stack s;
label:
cout<<"1: PUSH \n2: POP \n3: REVERSE\nEnter your choice : ";
cin>>c;
if(c==1)
{
 s.push();
}
else if(c==2)
{
 s.pop();
}
else if(c==3)
{
 s.reverse();
}
cout<<endl;
cout<<"\nContinue ? (y/n) : ";
cin>>ch;
if(ch=='y')
{
    goto label;
}
else if(ch=='n')
{
     exit(1);
}
return 0;
}


