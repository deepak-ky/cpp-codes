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

const int N = 1004;
int dp[N][N];

int max_value(int i, int j, int *a, int n)
{

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

	if (i > j)
	{
		return dp[i][j] = 0;
	}
	if (i == j)
	{
		return dp[i][j] = a[i];
	}


	int opt1 = a[i];
	//he has now option of i+1...j
	// if he picks i+1 => I have i+2..j
	// if he picks j   => I have i+1..j-1
	// Yeh uske haath mein hain , mujhe konsa option milega, toh woh yeh try karega, ki woh
	// maximum wala lele , aur mujhe minimum wala mile
	// Assume worst when things happen to me

	opt1 += min(max_value(i + 2, j, a, n), max_value(i + 1, j - 1, a, n));


	int opt2 = a[j];
	opt2 += min(max_value(i + 1, j - 1, a, n), max_value(i, j - 2, a, n));

	return dp[i][j] = max(opt1, opt2);
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		//WHEN YOU CAN DO SOMETHING , DO THE BEST
		//WHEN THINGS HAPPEN TO YOU , ASSUME THE WORST

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << max_value(0, n - 1, a, n);

	}
	return 0;
}
