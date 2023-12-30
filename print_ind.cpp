#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int m;
cin>>m;
for(int i=0;i<n;i++)
  {
      if(a[i]==m)
      {
          cout<<i<<endl;
      }
  }
return 0;

}
