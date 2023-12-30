#include<iostream>
using namespace std;
int main()
{
long long int n,m,i,j,k,s;
cin>>n>>m;
int d;
long long int a[n];
for(k=0;k<n;k++)
  {
      cout<<"Enter the element"<<k+1<<" : ";
      cin>>a[k];
  }
for(i=n;i>=0;i--)
 {
   if(a[i]==m)
   {

     d=1;
     j=i+1;
     break;
    }

   else if(a[i]!=m)
    {
     d=2;
    }
}
 if(d==1)
 {
     cout<<endl<<"element found at "<<j;
 }
 else if(d==2)
 {
     cout<<endl<<"-1";
 }
}
