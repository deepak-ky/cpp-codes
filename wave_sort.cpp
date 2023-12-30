#include<iostream>
using namespace std;
void wavesrt(int a[],int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && a[i-1]>a[i])
        {
            swap(a[i-1],a[i]);
        }
        if(i<=n-2 && a[i+1]>a[i])
        {
            swap(a[i],a[i+1]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Before Wave Sort : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    wavesrt(a,n);
    cout<<"\nAfter Wave Sort : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

  return 0;
}
