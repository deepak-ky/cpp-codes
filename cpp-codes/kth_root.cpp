#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool ispossible(lli n,lli k,lli mid)
{
	lli val=pow(mid,k);
	cout<<"\nVal here : "<<val;
	if(val<=n)
	{
	    return true;
    }
	else if(val>n)
	return false;
}
lli findx(lli n,lli k)
{
	lli s=0;
	lli e=n;
	lli ans=INT_MIN;
	while(s<=e)
	{
      lli mid=(s+e)/2;
      cout<<"\nmid here : "<<mid;
	  if(ispossible(n,k,mid))
	   {
		   ans=max(ans,mid);
		   s=mid+1;
		   cout<<"\nstart here : "<<s;
	   }
     else
	 {
		 e=mid-1;
		 cout<<"\nend here : "<<e;
	 }
	}
	return ans;
}

int main() {
	lli t;
	cin>>t;
	while(t--)
	{
	lli n;
	lli k;
	cin>>n>>k;
	cout<<"\nn here : "<<n;
	cout<<"\nk here : "<<k;
	cout<<endl<<" : "<<findx(n,k)<<endl;
	}
	return 0;
}
