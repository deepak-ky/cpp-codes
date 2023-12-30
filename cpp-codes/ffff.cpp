#include<iostream>
using namespace std;
int main()
{
int i,j,k,n,m;
int t;
cin>>t;
while(t--)
{
cin>>n;
int c[n];
int l[n];
for(int i=0;i<n;i++)
{
cin>>c[i]>>l[i];
}
int min_cost=0;
int cost=0;
for(int i=0;i<n;i++)
{
  if(i==0)
  {
      min_cost=max(min_cost,c[i]);
      cost=cost+(min_cost*l[i]);
  }
  else if(i!=0)
  {


    min_cost=min(min_cost,c[i]);
  cost=cost+(min_cost*l[i]);
  }


  }
cout<<endl<<cost<<endl;
}
return 0;
}
