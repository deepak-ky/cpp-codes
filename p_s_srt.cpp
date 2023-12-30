#include<iostream>
using namespace std;
void select(int a[],int n,int i)
{
    if(i==(n-1))
    {
       return;
    }
    int min=i;
    for(int j=i+1;j<n;j++)
    {
      if(a[min]>a[j])
      {
          min=j;
          swap(a[min],a[i]);
      }
    }
   select(a,n,i+1);
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
select(a,n,0);
cout<<"\nAFter Sorting : ";
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}

return 0;
}
