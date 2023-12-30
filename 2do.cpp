#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[3][3];
int i,g,j,k,l,m,n;
int flag=0;
cout<<"Enter the elements(only 0 and 1) : \n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<"Enter the element ["<<i+1<<"] ["<<j+1<< "] : ";
cin>>a[i][j];
}
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]==0)
{
    cout<<&a[i][j]<<" ";
}
}
}
return 0;
}
