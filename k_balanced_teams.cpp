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
		int n,k;
		cin >> n >> k;

		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];

		sort(a,a+n);

		vector<int> left_boundary(n);

		for(int i=n-1;i>=0;i--)
		{
			for(int j=i;j>=0;j--){
				if(a[i] - a[j] > 5) break;
				left_boundary[i] = j;
			}
		}

		/*out(left_boundary,n);*/

		int dp[n+1][k+1];

		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				if(i == 0 || j == 0){
					dp[i][j] = 0;
					continue;
				}

				// wer(i);
				// wer(j);

				int t = left_boundary[i-1];

				//wer(t);

				int opt1 = dp[i-1][j];
				int zero = 0;

				int opt2 = ((i-1)-t+1) + dp[t][j-1];
				/*wer(opt1);
				wer(opt2);*/
				dp[i][j] = max(opt1,opt2);
			}
		}

		cout << dp[n][k];
	}
	return 0;
}
