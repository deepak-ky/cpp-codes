#include<iostream>
using namespace std;
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
int main()
{
llsi n,n1;
cin>>n>>n1;
llsi sum=0;
for(llsi i=n;i<=n1;i++)
{
    sum=sum+fastbit(i);
}
cout<<sum;
return 0;
}
