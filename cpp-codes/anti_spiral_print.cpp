#include<iostream>
using namespace std;
int main()
{
int m,n;
cin>>m>>n;
int a[m][n];
int i,j;
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
  {
   cin>>a[i][j];
  }
}
for(i=0;i<m;i++)
{
 for (j=0;j<n;j++)
  {
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
}
cout<<"\nANTI SPIRAL PRINT : ";
int sr=0;
int er=m-1;
int ec=n-1;
int sc=0;
while(sr<=er && sc<=ec)
{
    for(int i=sr;i<=er;i++)
    {
        cout<<a[i][sc]<<", ";
    }
    sc++;
    for(int i=sc;i<=ec;i++)
    {
        cout<<a[er][i]<<", ";
    }
    er--;
    if(er>sr)
    {
    for(int i=er;i>=sr;i--)
    {
        cout<<a[i][ec]<<", ";
    }
    ec--;
    }
    if(ec>sc)
    {
    for(int i=ec;i>=sc;i--)
    {
        cout<<a[sr][i]<<", ";
    }
    sr++;
    }

}
cout<<"END";
return 0;
}
















