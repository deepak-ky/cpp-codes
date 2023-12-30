#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maximum(int g,int h,int v)
{
 return (max(max(g,h),v));
}
int minimum(int g,int h,int v)
{
 return (min(min(g,h),v));
}
int main()
{
int a[100000];
int b[100000];
int c[100000];
int i,j,k;
int n1,n2,n3,n4,n5;
cin>>n1>>n2>>n3;
for(i=0;i<n1;i++)
{

  cin>>a[i];
}

for(j=0;j<n2;j++)
{

  cin>>b[j];
}

for(k=0;k<n3;k++)
{

  cin>>c[k];
}
int diff=0;
int lesmin=(maximum(a[0],b[0],c[0])-minimum(a[0],b[0],c[0]));
for(i=0;i<n1;i++)
{
    for(j=0;j<n2;j++)
    {
        for(k=0;k<n3;k++)
        {
            n4=maximum(a[i],b[j],c[k]);
            n5=minimum(a[i],b[j],c[k]);
            diff=abs(n4-n5);
            if(diff<lesmin)
            {
                lesmin=diff;
            }
            else if(diff>=lesmin)
            {
                lesmin=lesmin;
            }
        }
    }
}
cout<<lesmin<<endl;
return 0;
}
