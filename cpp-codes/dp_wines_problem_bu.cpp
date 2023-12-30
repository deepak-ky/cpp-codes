#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void maximize_profit(int *p, int size)
{
	int dp[5][5] = {0};
	int y = 1;
	//you are at the first year
	int start_point_coloumn = 0;
	int year = 5;
	while (start_point_coloumn < 5)
	{
		int j = 0;
		int i = start_point_coloumn;
		while (i < 5)
		{
			dp[i][j] =
		}
	}


}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int p[5] = {2, 3, 5, 1, 4};
	/*cout <<*/ maximize_profit(p, 5);
	return 0;
}
