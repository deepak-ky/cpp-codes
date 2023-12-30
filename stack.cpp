#include<iostream>
#include<stdlib.h>
using namespace std;
const int size=50;
int push(int [],int &,int);
int pop(int [],int &);
int display(int [],int);
int main()
{
int stack[size];
int i,j,k,l,m,n,c;
char ch;
int top=-1;
label:
cout<<"Push[1] or pop[2] : ";
cin>>c;
if(c==1)
 {
   cout<<"Enter the element : ";
   cin>>m;
   push(stack,top,m);
}
else if(c==2)
{
    pop(stack,top);
}
cout<<"The stack now is : ";
display(stack,top);

cout<<"\n Continue ? (y/n) : ";
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
int push(int stack[],int &top,int m)
{

 top++;
 stack[top]=m;
 return 0;
}
int pop(int stack[],int &top)
{
 stack[top]=stack[top-1];
 top--;
 return 0;
}
int display(int stack[],int top)
{
 int t;
 for(t=top;t>=0;t--)
 {
     cout<<"\n"<<stack[t];
 }
}

















