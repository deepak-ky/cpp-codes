#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mult(int a,int b)
{
    if(b==0)
    {
        return 0;
    }

	if(b==1)
    {
        return a;
    }
	else return a+mult(a,b-1);
}
int findmult(int a,int b)
{
    if(a<0 && b>=0)
    {
        return mult(-a,b);
    }
    else if(a>0 && b<=0)
    {
        return mult(-a,-b);
    }
    else if(a<=0 && b<=0)
    {
        return mult(-a,-b);
    }
    else if(a>=0 && b>=0)
    {
        return mult(a,b);
    }
}
int main()
{
   int a,b;
   cin>>a>>b;
   cout<<findmult(a,b);
return 0;
}

