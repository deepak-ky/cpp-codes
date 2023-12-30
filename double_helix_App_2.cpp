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

const int n = 10005;
int dp1[n];
int dp2[n];
int index(int *a, int n, int key)
{
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (a[m] == key)
		{
			return m;
		}
		else if (a[m] > key)
		{
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	return ans;
}
int solve(bool in_array_one, int *a, int *b, int idx, int n, int m)
{
	if (in_array_one)
	{
		if (idx == n)
		{
			return 0;
		}

		if (dp1[idx] != -1)
		{
			return dp1[idx];
		}

		if (index(b, m, a[idx]) != -1)
		{
			//I can continue in my original array

			int op1 = a[idx] + solve(true, a, b, idx + 1, n, m);

			//Change my array

			int id = index(b, m, a[idx]);

			int op2 = b[id] + solve(false, a, b, id + 1, n, m);

			return dp1[idx] = max(op1, op2);
		}
		else
		{
			// If the element is not present / I have to continue in array - 1
			return dp1[idx] = a[idx] + solve(true, a, b, idx + 1, n, m);
		}

	}
	else //In array 2
	{
		if (idx == m)
		{
			return 0;
		}

		if (dp2[idx] != -1)
		{
			return dp2[idx];
		}

		if ( index(a, n, b[idx]) != -1)
		{
			//I can continue in my original array

			int op1 = b[idx] + solve(false, a, b, idx + 1, n, m);

			//Change my array

			int id = index(a, n, b[idx]);

			int op2 = a[id] + solve(true, a, b, id + 1, n, m);

			return dp2[idx] = max(op1, op2);
		}
		else
		{
			// If the element is not present / I have to continue in array - 2
			return  dp2[idx] = b[idx] + solve(false, a, b, idx + 1, n, m);
		}
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t)
	{

		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));



		int n;
		cin >> n;

		if (n == 0)
		{
			return 0;
		}
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int m;
		cin >> m;
		int *b = new int[m];
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}


		//I have to give it two starts
		int op1 = solve(true, a, b, 0,  n, m);
		int op2 = solve(false, a, b, 0, n, m);

		cout << max(op1, op2) << endl;


	}
	return 0;
}
