#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n,d;
    cin>>n>>d;
    lli a[n];
    for(lli i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int count=0;
    lli i=0;
    while(i<n)
    {
       if((a[i+1]-a[i])<=d)
       {
           count++;
           i=i+2;
       }
       else if((a[i+1]-a[i])>d)
       {
           i=i+1;
       }
    }
    cout<<count;
    return 0;
}
