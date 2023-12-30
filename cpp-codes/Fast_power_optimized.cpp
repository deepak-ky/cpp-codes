#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int raiseto(int a,int b)
{
	if(b==1)
		{
			return a;
		}
	else if(b>1)
	{
      if(b%2==0)
      {

      	return (raiseto(a,b/2))*(raiseto(a,b/2));
      }
      else if(b%2!=0)
      {
      	return a*raiseto(a,(b-1)/2)*raiseto(a,(b-1)/2);
      }
	}
}
int main()
{
   int a,b;
   cin>>a>>b;
   cout<<raiseto(a,b);
return 0;
}

