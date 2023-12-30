#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
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

bool solve(int *a, int n, int curr_index)
{

	if (curr_index < 0 || curr_index >= n)
	{
		return false;
	}
	if (a[curr_index] == 0)
	{
		return true;
	}
	bool flag1 = false;
	if ((curr_index + a[curr_index]) < n)
	{

		int u1 = curr_index + a[curr_index];
		if (a[u1] != -1)
		{
			int w = a[curr_index];
			a[curr_index] = -1;
			flag1 = solve(a, n, curr_index + w);
			a[curr_index] = w;
		}
	}
	bool flag2 = false;
	if ((curr_index - a[curr_index]) >= 0)
	{
		int u = curr_index - a[curr_index];
		if (a[u] != -1)
		{
			int w = a[curr_index];
			a[curr_index] = -1;
			flag2 = solve(a, n, curr_index - w);
			a[curr_index] = w;
		}
	}
	if (flag1 || flag2)
	{
		return true;
	}
	else return false;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int curr_index;
		cin >> curr_index;
		bool flag = solve(a, n, curr_index);
		if (flag)
		{
			yes;

		}
		else no;
	}
	return 0;
}
