#include<iostream>
using namespace std;
int main()
{
int n,i,j;
cin>>n;
int a[n];
for(i=0;i<n;i++)
{
cin>>a[i];
}
int target;
cin>>target;

for(i=0;i<n;i++)
{
 for(j=i+1;j<n;j++)
  {
      if((a[i]+a[j]==target))
      {
        if(a[i]<a[j])
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
        }
       else if(a[i]>a[j])
        {
            cout<<a[j]<<" and "<<a[i]<<endl;
        }
    }
 }
}
return 0;
}
