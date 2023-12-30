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
#define se                            second

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

int dp[102][102][102];

int changes_for_palin(string a)
{
	int cnt = 0;
	int n = a.length();
	for (int i = 0; i < (n / 2); i++)
	{
		if (a[i] != a[n - i - 1])
		{
			cnt++;
		}
	}

	return cnt;
}



int min_changes_req(int i, int j, string s, int k)
{
	if (i > j)
	{
		return INT_MAX;
	}

	if (k > (j - i + 1))
	{
		return INT_MAX;
	}

	if (dp[i][j][k] != -1)
	{
		return dp[i][j][k];
	}



	if (k == 1)
	{
		string w = s.substr(i, j - i + 1);
		return dp[i][j][k] = changes_for_palin(w);
	}




	int ans = INT_MAX;
	for (int d = i; d <= j; d++)
	{
		string a = s.substr(i, d - i + 1);
		int op1 = changes_for_palin(a);
		int u = min_changes_req(d + 1, j, s, k - 1);

		ans = min(ans, op1 + u);
	}


	return dp[i][j][k] = ans;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{


		memset(dp, -1, sizeof(dp));

		string s = "abc";
		int k  = 2;
		cout << min_changes_req(0, s.length() - 1, s, k);

	}
	return 0;
}
