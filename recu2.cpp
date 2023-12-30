#include<iostream>
using namespace std;
int findexp(int a,int b)
{
if(b==0)
return 1;
else
return a*findexp(a,b-1);
}
int main()
{
int a,b;
cin>>a>>b;
cout<<findexp(a,b);
return 0;
}
