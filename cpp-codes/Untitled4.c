#include<iostream>
using namespace std;
typedef long long ll;
ll binsrch(ll a[],ll key,ll n)
{
ll low=0;
ll high=n-1;
mid=(low+high/2);
while(low<high)
{
   if(a[mid]==key)
   {return mid;
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
return -1;
int main()
{
ll n,i,key;
cin>>n;
ll a[n];
for(i=0;i<n;i++)
{
cin>>a[i];
}
ll key;
cin>>key;
ll o;
o=binsrch(a,n);
ciut<<o;
return 0;
}
