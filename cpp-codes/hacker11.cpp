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
cout<<"Enter n1,n2,n3 : \n";
cin>>n1>>n2>>n3;
cout<<"n1 : "<<n1<<endl;
cout<<"n2 : "<<n2<<endl;
cout<<"n3 : "<<n3<<endl;
cout<<endl;
for(i=0;i<n1;i++)
{
  cout<<"Array 1 element "<<i+1<<" : ";
  cin>>a[i];
}
cout<<endl;
for(j=0;j<n2;j++)
{
  cout<<"Array 2 element "<<j+1<<" : ";
  cin>>b[j];
}
cout<<endl;
for(k=0;k<n3;k++)
{
  cout<<"Array 3 element "<<k+1<<" : ";
  cin>>c[k];
}
cout<<endl<<"The three arrays are : \n";
cout<<"Array 1 : ";
for(i=0;i<n1;i++)
{
  cout<<a[i]<<" ";
}
cout<<endl;
cout<<"Array 2 : ";
for(j=0;j<n2;j++)
{
  cout<<b[j]<<" ";
}
cout<<endl;
cout<<"Array 3 : ";
for(k=0;k<n3;k++)
{
  cout<<c[k]<<" ";
}
cout<<endl;
int diff=0;
int lesmin=(maximum(a[0],b[0],c[0])-minimum(a[0],b[0],c[0]));
cout<<endl<<"LESMIN : "<<lesmin<<endl;
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
cout<<endl<<"LESMIN NOW : "<<lesmin<<endl;
return 0;
}
