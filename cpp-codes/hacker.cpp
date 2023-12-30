#include<iostream>
using namespace std;
int main()
{
int n;

cout<<"Enter the size of the matrix : ";
cin>>n;
int n1=n;
int n2=n;
cout<<endl<<"Entries are only 0 and 1 :\n";
int k,l;
int a[n][n];
for(int i=0;i<n1;i++)
{
 for(int j=0;j<n2;j++)
 {
  cin>>a[i][j];
 }
}
cout<<"\nThe original matrix is : \n";
for(int i=0;i<n;i++)
{
 for(int j=0;j<n;j++)
 {
  cout<<" "<<a[i][j];
 }
 cout<<endl;
}
int b[n][n];
 int c[n][n];
 int d[n][n];
 int g[n][n];
 cout<<endl;
 for(int j=n2-1,k=0;j>=0,k<n;j--,k++)
 {
     for(int i=0,l=0;i<n1,l<n;i++,l++)
     {
         b[k][l]=a[i][j];
     }

 }
 cout<<"\nThe first original matrix is : \n";
for(int f=0;f<n;f++)
{
 for(int e=0;e<n;e++)
 {
  cout<<" "<<b[f][e];
 }
 cout<<endl;
}
for(int j=n2-1,k=0;j>=0,k<n;j--,k++)
 {
     for(int i=0,l=0;i<n1,l<n;i++,l++)
     {
         c[k][l]=b[i][j];
     }

 }
 cout<<"\nThe second original matrix is : \n";
for(int f=0;f<n;f++)
{
 for(int e=0;e<n;e++)
 {
  cout<<" "<<c[f][e];
 }
 cout<<endl;
}
for(int j=n2-1,k=0;j>=0,k<n;j--,k++)
 {
     for(int i=0,l=0;i<n1,l<n;i++,l++)
     {
         d[k][l]=c[i][j];
     }

 }
 cout<<"\nThe third original matrix is : \n";
for(int f=0;f<n;f++)
{
 for(int e=0;e<n;e++)
 {
  cout<<" "<<d[f][e];
 }
 cout<<endl;
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==1 || b[i][j]==1 || c[i][j]==1 || d[i][j]==1)
        {
            g[i][j]=1;
        }
        else g[i][j]=0;
    }
}
cout<<"\nThe result original matrix is : \n";
for(int f=0;f<n;f++)
{
 for(int e=0;e<n;e++)
 {
  cout<<" "<<g[f][e];
 }
 cout<<endl;
}
return 0;
}
