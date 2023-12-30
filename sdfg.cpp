#include<iostream>
using namespace std;
void bubblesrt(int a[],int n)
{
    if(n==1)
    {
        return;
    }
    for(int j=0;j<=n-2;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }


    bubblesrt(a,n-1);
}
int main()
{
int a[]={9,3,5,8,7};
int n=sizeof(a)/sizeof(int);
int i,j,temp;
/*
for(i=0;i<n;i++)
{
 for(j=i+1;j<n;j++)
  {
   if(a[j]<a[i])
  {
      temp=a[j];
      a[j]=a[i];
      a[i]=temp;
  }
 }
}
*/
bubblesrt(a,n);
cout<<endl;
for(i=0;i<n;i++)
{
    cout<<a[i];
}

return 0;
}
