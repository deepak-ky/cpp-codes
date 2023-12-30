#include<iostream>
using namespace std;
void swapping(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
int min;
for(int i=0;i<min;i++)
{
  min=a[i];
  for(int j=i+1;j<n;j++)
   {
     if(min>a[j])
     {
       min=j;
       swap(a[i],a[min]);
     }
   }
}


for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}


return 0;
}








