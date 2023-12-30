#include<iostream>
using namespace std;
typedef long long ll;
ll binsrch(ll a[],ll key,ll n,ll low,ll high)
{
    if(low>=high)
    {
        return -1;
    }

ll mid=(low+high/2);
if(a[mid]==key)
   {
       return mid+1;

   }
   else if(a[mid]>key)
   {
       binsrch(a,key,n,low,high-1);
   }
   else if(a[mid]<key)
   {
       binsrch(a,key,n,low+1,high);
   }
}
int main()
{
ll n,i,key;
cin>>n;
ll a[n];
for(i=0;i<n;i++)
{
cin>>a[i];
}
cin>>key;
ll o;
o=binsrch(a,key,n,0,n-1);
cout<<o;
return 0;
}
