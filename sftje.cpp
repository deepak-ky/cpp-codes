#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {cin>>a[i];}
 int small=a[0];
 int pos;
  for(int i=1;i<n;i++)
  {
      if(a[i]<small)
      {
          small=a[i];
          pos=i;
      }
      else pos=pos;
  }
cout<<endl<<small<<endl<<pos;
return 0;
}
