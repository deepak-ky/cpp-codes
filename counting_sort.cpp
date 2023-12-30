#include<iostream>
using namespace std;
void cntsrt(int a[],int n)
{
    int maxx=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>maxx)
        {
            maxx=a[i];
        }
    }
    int w=maxx+1;
    int output[w];
    int cnt[w];
    for(int i=0;i<=maxx;i++)
    {
        cnt[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    for(int i=1;i<=maxx;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[cnt[a[i]]-1]=a[i];
        cnt[a[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
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
    cntsrt(a,n);
    cout<<"\nAfter Wave Sort : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

  return 0;
}

