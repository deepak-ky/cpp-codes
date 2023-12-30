#include<iostream>
using namespace std;
int fact(int n);
int main()
{
int i,j,kl,w;
cout<<"Enter n : ";
cin>>i;
w=fact(i);
cout<<"factorial is : "<<w;
return 0;
}
int fact(int n)
{
if(n>=1)
{return n*fact(n-1);}
else return 1;
}
