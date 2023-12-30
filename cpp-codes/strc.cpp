#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,m,n;
int a[10],b[10],c[10];
int strlengtha,strlengthb;
strlengtha=0;
strlengthb=0;
cout<<"Enter the string 1 : ";
cin.get(a,100);
cout<<"Enter the string 2   : ";
cin.get(b,100);
for(m=0;a[m]!='\0';m++)
{
strlengtha++;
}
for(m=0;b[m]!='\0';m++)
{
strlengthb++;
}
for(i=0;j=0;i<strlengtha;i++,j++)
{
c[j++]=a[i++]
}
for(i=0;j=strlength-1;i<strlengthb;i++,j++)
{
c[j++]=b[i++]
}
cout<<endl<<endl<<" : "<<c<<" : ";
return 0;
}
