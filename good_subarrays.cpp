#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
  int sum=0;
  int count=0;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          sum=0;
          for(int k=i;k<=j;k++)
          {

              sum=sum+a[k];
          }
          if(sum!=0 && sum%5==0)
          {
              count++;
          }

      }
  }
cout<<count;
    }
return 0;
}
