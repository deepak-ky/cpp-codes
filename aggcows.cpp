#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canplacecows(int a[],int n,int c,int mid)
{
   int last_cow=a[0];
   int cnt=1;
   for(int i=1;i<n;i++)
   {
       if((a[i]-last_cow)>=mid)
       {
           last_cow=a[i];
           cnt++;
           if(cnt==c)
           {
               return true;
           }
       }
   }
  return false;
}
int main()
{
int n,c;
cin>>n>>c;
int a[n];
for(int d=0;d<n;d++)
{
    cin>>a[d];
}
sort(a,a+n);
int low=0;
int high=a[n-1]-a[0];
int ans=0;
while(low<=high)
{
    int mid=(low+high)/2;
    bool cowsrakhpaye=canplacecows(a,n,c,mid);
    if(cowsrakhpaye)
    {
        ans=mid;
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
cout<<ans<<endl;
return 0;
}
