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

bool flag = false;

void check_for_zero_sum(int *a, int idx, int n, int curr_sum, vector<int> v)
{
	if (curr_sum == 0 && !v.empty())
	{
		flag = true;
		return;
	}
	if (idx == n)
	{
		return;
	}
	v.pb(idx);
	check_for_zero_sum(a, idx + 1, n, curr_sum + a[idx], v);
	v.pop_back();
	check_for_zero_sum(a, idx + 1, n, curr_sum, v);

	return;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		flag = false;
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> v;
		check_for_zero_sum(a, 0, n, 0, v);
		if (flag)
		{

			cout << "Yes" << endl;
		}
		else if (flag == false)
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
