#include<iostream>
using namespace std;
void dec(int a)
{
if(a==0)
{
  return;
}
else
cout<<a<<" ";
dec(a-1);
}
void inc(int a)
{
if(a==(a+1))
{
  return;
}
else
cout<<(a-(a-1))<<" ";
inc(a+1);
}
int main()
{
int b;
cin>>b;
dec(b);
return 0;
}
