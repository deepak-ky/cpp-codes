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
		int n;
		cin >> n;
		int capacity;
		cin >> capacity;

		int weights[n];
		int values[n];
		for(int i=0;i<n;i++){
			cin >> weights[i];
			cin >> values[i];
		}

		int dp[n+1][capacity+1];

		for(int i=0;i<=n;i++){
			for(int j=0;j<=capacity;j++){
				dp[i][j] = 0;
			}
		}

		for(int i=0;i<=n;i++){
			for(int j=0;j<=capacity;j++){
				if(i == 0 || j == 0){
					continue;
				}

				int current_weight = weights[i-1];
				int current_value  = values[i-1];

				if( j >= current_weight){
					int opt1 = dp[i-1][j];
					int opt2 = current_value + dp[i-1][j-current_weight];
					dp[i][j] = max(opt1,opt2);
				}else{
					dp[i][j] = dp[i-1][j];
				}

			}
		}

		cout << dp[n][capacity];
	}
	return 0;
}
