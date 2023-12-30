#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,m,n,o;
int a[3][3],b[3][3],c[3][3];
cout<<"Enter elements  of  MATRIX 1 A[3][3] :- ";
cout<<endl;
for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<"Enter element "<<i+1<<" "<<j+1<<" :- ";
      cin>>a[i][j];
    }

 }
 cout<<endl;
 cout<<"MATRIX 1 A[3][3] :- "<<endl;
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<a[i][j]<<" ";
    }
 cout<<endl;
 }
 cout<<endl<<"Enter elements  of  MATRIX 2 B[3][3] :- ";
cout<<endl;
for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<"Enter element "<<i+1<<" "<<j+1<<" :- ";
      cin>>b[i][j];
    }

 }
 cout<<endl;
 cout<<"MATRIX 2 B[3][3] :- "<<endl;
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<b[i][j]<<" ";
    }
 cout<<endl;
 }
 cout<<endl;
 cout<<"MATRIX 1 A[3][3] + MATRIX 2 B[3][3] :- "<<endl;
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      c[i][j]=a[i][j]+b[i][j];
    }
 }
 cout<<endl;

 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      cout<<c[i][j]<<" ";
    }
 cout<<endl;
 }
return 0;
 }
