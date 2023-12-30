#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second
#define inf 						 1e18

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

int find_sum(int i,int j,vector<int>&prefix_sum)
{
	if(i == 0) return prefix_sum[j];
	return prefix_sum[j] - prefix_sum[i-1];
}

int solve(int i,int j,vector<int> &a,vector<vector<int>> &dp,vector<int> &prefix_sum)
{	

	if(j == i+1)
	{
		dp[i][j] = max(a[i],a[j]);
		return dp[i][j];
	}

	if(i == j){
		return a[i];
	}

	if(dp[i][j] != inf){
		return dp[i][j];
	}

	int op1 = a[i] + (find_sum(i+1,j,prefix_sum) - solve(i+1,j,a,dp,prefix_sum));
	int op2 = a[j] + (find_sum(i,j-1,prefix_sum) - solve(i,j-1,a,dp,prefix_sum));

	return dp[i][j] = max(op1,op2);
}
int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n,0);
		for(int i=0;i<n;i++){
			int w;
			cin >> w;
			a[i] = w;
		}



		vector<int> prefix_sum(n,0);
		prefix_sum[0]  = a[0];
		for(int i=1;i<n;i++){
			prefix_sum[i] = a[i] + prefix_sum[i-1];
		}


		vector<vector<int>> dp(n,vector<int>(n,inf));

		cout << solve(0,n-1,a,dp,prefix_sum);



	}	
	return 0;
}
