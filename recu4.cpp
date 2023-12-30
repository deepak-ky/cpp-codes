#include<iostream>
using namespace std;
int mult(int a,int b)
{
    if(b>0)
    {
        if(b==1)
       return a;
       else
      return a+mult(a,b-1);
    }
    else if(b==0)
    {
        return 0;
    }
    else if(b<0)
    {
      mult(-a,-b);
    }
}
int main()
{
int a,b;
cin>>a>>b;
cout<<mult(a,b);
return 0;
}
