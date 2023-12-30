#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
int csum[n+1];
cin>>a[0];
csum[0]=a[0];
for(int i=1;i<n;i++)
  {
      cin>>a[i];
      csum[i]=csum[i-1]+a[i];
  }


  int count=0;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          int currentsum=0;
          currentsum=csum[j]-csum[i];
          if(currentsum!=0 && currentsum%n==0)
          {
              count++;

          }
          cout<<"\nCurrent Sum : "<<currentsum;
          cout<<"\nCount now : "<<count;
      }
  }
cout<<"\nCount : "<<count;
return 0;
}
