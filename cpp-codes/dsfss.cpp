#include<iostream>
#include<math.h>
using namespace std;
typedef long long int lli;
lli tenpower(lli n)
{
    lli r=1;
    for(lli i=1;i<n;i++)
    {r*=10;}
    return r;
}
int main()
{
lli n;
cin>>n;
lli i=1;
lli ans=0;
while(n>0)
{
    lli p=n%10;
    cout<<"\n p : "<<p;
    n=n/10;
    lli x=tenpower(p);
    cout<<"\n x : "<<x;
    ans+=(x*i);
    cout<<"\n ans : "<<ans;
    i++;
}

cout<<endl<<ans;
return 0;
}
