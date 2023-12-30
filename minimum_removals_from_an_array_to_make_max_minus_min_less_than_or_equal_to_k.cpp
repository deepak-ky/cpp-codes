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

const int N = 10;
int dp[N][N];

int min_number_of_removals(int *a, int i, int j, int k)
{
	if ((a[j] - a[i]) <= k)
	{
		return 0;
	}

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}


	int opt1 = 1 + min_number_of_removals(a, i + 1, j, k);
	int opt2 = 1 + min_number_of_removals(a, i, j - 1, k);

	return dp[i][j] = min(opt1, opt2);
}


int next_greater_element(int *a, int num, int idx, int n, int k)
{
	int l = idx + 1;
	int h = n - 1;


	//a_max - num <= k
	//a_max <= num + k
	int ans = -1;

	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (a[m] - num <= k)
		{
			ans = m;
			l = m + 1;
		}
		else
		{
			h = m - 1;
		}
	}

	return ans;

}

int minimum_removals(int *a, int n, int k)
{
	int ans = n - 1; // This could be the maximum answer possible

	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		int ind = next_greater_element(a, a[i], i, n, k);

		if (ind != -1)
		{
			ans = min(ans, n - (ind - i + 1));
		}
	}

	return ans;
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		memset(dp, -1, sizeof(dp));

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int k;
		cin >> k;


		sort(a, a + n);

		int i = 0;
		int j = n - 1;

		cout << min_number_of_removals(a, i, j, k);

		cout << endl;

		//cout << minimum_removals(a, n, k);



	}
	return 0;
}
