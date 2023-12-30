#include<bits/stdc++.h>
using namespace std;
int main()
{
char a[100],b[100],c[100];
int i,g,j,k,l,m,n;
int sla,slb;
sla=0;
slb=0;
cout<<"Enter the first string : ";
cin>>a;
cout<<"First String : "<<a<<"\n";
cout<<"Enter the second string : ";
cin>>b;
cout<<"Second String : "<<b<<"\n";
for(m=0;a[m]!='\0';m++)
{
    sla++;
}
for(m=0;b[m]!='\0';m++)
{
    slb++;
}
for(i=0,j=0;i<sla;i++,j++)
{
    c[j]=a[i];
}
for(i=0,j=sla;i<slb;i++,j++)
{
    c[j]=b[i];
}
cout<<"\nConcatenated String : ";
for(l=0;l<(sla+slb);l++)
{
    cout<<c[l];
}
return 0;
}
