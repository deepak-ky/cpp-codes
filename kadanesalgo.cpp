#include<iostream>
using namespace std;
int main()
{
int i,j,k,l;
int n;
cin>>n;
int a[n];
for(j=0;j<n;j++)
{
cin>>a[j];
}
int cs=0;
int ms=0;
for(i=0;i<n;i++)
{
 if(a[i]>0)
 {
  cs=cs+a[i];
   if(cs>=ms)
   {
       ms=cs;
   }
 }
 else if(a[i]<0)
 {
     l=cs+a[i];
   if(l<0)
   {
       cs=0;
   }
  else if(l>0)
  {
      cs=l;
  }
 }
}

cout<<endl<<": "<<cs;

cout<<endl<<": "<<ms;


return 0;
}
