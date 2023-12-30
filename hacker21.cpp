#include<iostream>
using namespace std;
int main()
{
    int t;
    int n;
    cin>>t;
    while(t!=0)
    {



cin>>n;
int a[n];
int count=0;
for(int k=0;k<n;k++)
{
    cin>>a[k];
}
for(int i=0;i<n;i++)
 {
   for(int j=i+1;j<n;j++)
    {
      if(a[i]>a[j])
      {count++;}
    }

 }


cout<<count<<endl;




t--;
    }
return 0;
}
