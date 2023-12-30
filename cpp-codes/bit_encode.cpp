#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
typedef long long unsigned int llsi;
llsi fastbit(llsi n)
{
    llsi ans=0;
    if(n>0)
    {
    while(n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
    }
    else if(n==0)
    {
        return ans;
    }
    else if(n<0)
    {
      while(n<0)
    {
        n=n&(n+1);
        ans++;
    }
    return ans;
    }

}
using namespace std;
int main()
{
llsi t;
cin>>t;
while(t--)
{
    llsi a;llsi b;
    cin>>a>>b;
    llsi i=0;
    llsi sum=0;
    for(i=a;i<=b;i++)
   {sum+=__builtin_popcount(i);}
   cout<<"\nThe sum is "<<sum<<endl;
}
return 0;
}
