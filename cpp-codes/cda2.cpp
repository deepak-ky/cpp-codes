#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,m,n,o,r,c;
cin>>r>>c;
int a[r][c];
for(i=0;i<r;i++)
 {
   for(j=0;j<c;j++)
    {
      cin>>a[i][j];
    }

 }
 cout<<endl;
 for(i=0;i<c;i++)
 {
   for(j=0;j<r;j++)
    {
      cout<<a[i][j]<<" ";
    }
 cout<<endl;
 }
 cout<<endl;

 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<a[i][j]<<" ";
    }

 }
return 0;
 }
