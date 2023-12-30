#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int raiseto(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
	if(b==1)
		{return a;}
	else return a*raiseto(a,b-1);
}
int main()
{
   int a,b;
   cin>>a>>b;
   cout<<raiseto(a,b);
return 0;
}

