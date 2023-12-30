#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                           long long
#define watch(var,x)                     cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
#define inf                          1e18
int32_t main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n<=3)
		{
		    cout<<"odd";
			for(int i=0;i<n;i++)
            {
               watch(i);
                cout<<i<<" ; ";
            }
		}
		else {
			cout<<"even";
		}
	}
	return 0;
}
