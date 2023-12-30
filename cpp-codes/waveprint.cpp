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

int flag=0;
j=0;
while(j!=n)
{
  if(flag==0)
  {
    for(i=0;i<m;i++)
   {
    cout<<a[i][j]<<",";
   }
   flag=flag+1;

  }
  else if(flag==1)
  {
       for(i=m-1;i>=0;i--)
   {
    cout<<a[i][j]<<",";
   }
   flag=flag-1;
  }

j++;
}
cout<<"END";
return 0;
}















