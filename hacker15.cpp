#include<iostream>
using namespace std;
int maxi(double g[],int h)
{
    int mac,j;
    mac=g[0];
    for(j=0;j<h;j++)
    {
        if(g[j]>mac)
        {
            mac=g[j];
        }
        else if(g[j]<=mac)
        {
            mac=mac;
        }
    }

   return mac;
}
int main()
{
double a[1000];
double n;
cin>>n;
int i;
for(i=0;i<n;i++)
{
    cin>>a[i];
    }
    cout<<endl<<maxi(a,n);
    return 0;
}
