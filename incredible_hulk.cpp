#include<iostream>
using namespace std;
typedef long long ll;
ll fastcnt(ll n)
{
    ll ans=0;
    while(n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;


}
int main()
{
  ll t,n;
  cin>>t;
  ll a[t];
  for(ll i=0;i<t;i++)
  {
      cin>>a[i];
  }
  for(ll i=0;i<t;i++)
  {
      cout<<fastcnt(a[i]);
      cout<<endl;
  }
return 0;
}
