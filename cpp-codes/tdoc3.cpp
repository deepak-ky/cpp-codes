#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int n1=n;
int n2=n;
int k,l;
int a[n][n];
for(int i=0;i<n1;i++)
{
 for(int j=0;j<n2;j++)
 {
  cin>>a[i][j];
 }
}
int b[n][n];
for(int j=n2-1,k=0;j>=0,k<n;j--,k++)
 {
     for(int i=0,l=0;i<n1,l<n;i++,l++)
     {
         b[k][l]=a[i][j];
     }

 }
 for(int f=0;f<n;f++)
{
 for(int e=0;e<n;e++)
 {
  cout<<" "<<b[f][e];
 }
 cout<<endl;
}
return 0;
}
