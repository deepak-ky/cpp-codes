#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
lli n;
cin>>n;
lli a[n];
for(lli i=0;i<n;i++)
{
    cin>>a[i];
}
lli minn=a[0];
lli maxx=a[0];
lli mp=a[0];
for(lli i=1;i<n;i++)
{
   if(a[i]<0)
    {
        swap(minn,maxx);
    }
  maxx=max(a[i],(a[i]*maxx));
  minn=min(a[i],(a[i]*minn));
   mp=max(maxx,mp);
}
cout<<mp;
return 0;
}
