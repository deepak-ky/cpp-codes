#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n,x;
		cin >> n >> x;
		int prices[n];
		int pages[n];
		for(int i=0;i<n;i++) cin >> prices[i];
		for(int i=0;i<n;i++) cin >> pages[i];

		int dp[n+1][x+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=x;j++){
				if (i == 0 || j == 0){
					dp[i][j] = 0;
					continue;
				}

				if(j >= prices[i-1]){

					int opt1 = pages[i-1] + dp[i-1][j - prices[i-1]];
					int opt2 = dp[i-1][j];

					dp[i][j] = max(opt1,opt2);

				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		cout << dp[n][x] << endl;

	}
	return 0;
}
