#include<iostream>
#include<math.h>
using namespace std;
typedef long long int lli;
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
    lli x=pow(10,(p-1));
    cout<<"\n x : "<<x;
    ans+=(x*i);
    cout<<"\n ans : "<<ans;
    i++;
}

cout<<endl<<ans;
return 0;
}
