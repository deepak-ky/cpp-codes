#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
int count1=0;
int count2=0;
for(int i=0;i<n;i++)
{
  if(a[i]==2)
  {cout<<"2";}
  else if(a[i]==1)
  count1++;
  else if(a[i]==0)
  count2++;
 }

for(int i=0;i<count1;i++)
{cout<<1;}

for(int i=0;i<count2;i++)
{cout<<0;}
return 0;
}
