#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
ll t;
cin>>t;
while(t--)
{
ll n;
cin>>n;
ll a[100005];
ll fre[100005]={0};
ll sum=0;
fre[0]=1;
for(ll i=0;i<n;i++)
{
  cin>>a[i];
  sum+=a[i];
  sum%=n;
  sum=(sum+n)%n;
  fre[sum]++;
}
ll ans=0;
for(ll i=0;i<n;i++)
{
    ll m=fre[i];
    ans=ans+(m*(m-1))/2;
}
cout<<ans<<endl;
}
return 0;
}
