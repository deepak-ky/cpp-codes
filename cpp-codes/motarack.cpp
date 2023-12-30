#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef long long int lli;
int main()
{
lli n;
cin>>n;
lli a[n];
    for(lli i=0;i<n;i++)
    {
        cin>>a[i];
    }
lli abmax=0;
lli maxele=a[0];
    for(lli i=1;i<n;i++)
    {
        maxele=max(maxele,a[i]);
    }
    for(lli i=0;i<n;i++)
    {
    if(a[i]!=-1 && a[i+1]!=-1)
      {
        lli w=(a[i]-a[i+1]);
        if(w>=0 && w>abmax)
         {
           abmax=w;
         }
        else if(w<0)
         {
          w+=(2*w);
          if(w>=0 && w>abmax)
         {
           abmax=w;
         }
        }
      }
    }
if(abmax>0)
{
cout<<abmax<<" "<<maxele-abmax;
}
else if(abmax==0);
{
    lli sum=0;
    lli count=0;
    for(lli i=0;i<n;i++)
    {
    if(a[i]!=-1)
        {
        sum+=a[i];
        count++;
        }
    }
    cout<<"\nSum : "<<sum;
    cout<<"\nCount : "<<count;
    lli q=(sum/count);
    cout<<endl<<maxele-q<<" "<<q;
}
return 0;
}
