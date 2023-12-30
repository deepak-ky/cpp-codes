#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli indexof(lli a[],lli n,lli m)
{
   cout<<"\nN here is : "<<n;
      cout<<"\na[n-1] here is : "<<a[n-1];
   if(a[n-1]==m)
   {
       cout<<"\n a[n-1] == m ) returning n-1 from here";
     return (n-1);
   }
   if((n-1)==0 && a[n-1]!=m)
   {
              cout<<"\n a[n-1]! == m ) returning  -1 from here";
      return -1;
   }

  cout<<"\nAll three above conditions have been skipped and the control is here";
   return indexof(a,n-1,m);
}
lli lastocc(lli a[],lli idx,lli n,lli m)
{
    if(idx==(n))
    {
        return -1;
    }
    lli rr=lastocc(a,idx+1,n,m);
    if(a[idx]==m && rr==-1)
    {
        return idx;
    }
    return rr;
}
int main()
{

	lli n;
	cin>>n;
	lli a[n];
	for(int i=0;i<n;i++)
	{
      cin>>a[i];
	}
	lli m;
	cin>>m;
	cout<<endl<<lastocc(a,0,n,m);
return 0;
}

