#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool binsrch(ll a[],ll key,ll n)
{
ll low=0;
ll high=n-1;
int mid=(low+high/2);
while(low<=high)
{

   if(a[mid]==key)
   {
    return true;
   }
   else if(a[mid]>key)
   {
    high--;
   }
   else if(a[mid]<key)
   {
    low++;
   }
   mid=(low+high/2);
}
return false;
}
int main()
{
ll n,d,t;
ll key;
cin>>t;
while(t!=0)
{
    cin>>n;
ll a[n];
for(ll i=0;i<n;i++)
{
cin>>a[i];
}
sort(a,a+n);
ll qn;
cin>>qn;
ll qa[qn];
for(ll i=0;i<qn;i++)
{
cin>>qa[i];
}
for(ll j=0;j<qn;j++)
{
    if(binsrch(a,qa[j],n))
    {
        cout<<"Yes";
    }
    else cout<<"No";
    cout<<endl;
}
t--;
}
return 0;
}
