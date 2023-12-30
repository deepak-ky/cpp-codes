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

/*unordered_*/map<int, int> next_jump;
/*unordered_*/map<int, int> cost_from_here;

int solve(int *a, int n, int idx, int l)
{
	if (cost_from_here.find(idx) != cost_from_here.end())
	{
		return cost_from_here[idx];
	}
	if (idx == n - 1)
	{
		next_jump[n - 1] = n - 1;
		return 0;
	}

	if (idx == n)
	{
		return 0;
	}
	int min_cost = INT_MAX;
	int length_till_now = 0;
	for (int i = idx; i < n; i++)
	{
		length_till_now += a[i];
		if (l - length_till_now >= 0)
		{
			//If I am able to adjust the last word in my current line only
			//min cost of that line will become zero
			if (i == (n - 1))
			{
				min_cost = 0;
				next_jump[idx] = n - 1;
			}
			else
			{
				int w = l - length_till_now;
				int f1 = (pow(w, 2) + solve(a, n, i + 1, l));
				if (f1 < min_cost)
				{
					next_jump[idx] = i;
				}
				min_cost = min(min_cost, f1);
			}
		}
		else
		{
			break;
		}
		length_till_now++;
	}
	return cost_from_here[idx] = min_cost;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{

		next_jump.clear();
		cost_from_here.clear();


		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int l;
		cin >> l;


		int ans = solve(a, n, 0, l);

		//displaying the path
		// for (auto x : next_jump)
		// {
		// 	cout << x.first  << " " << x.second << endl;
		// }

		// cout << endl;

		// for (auto x : cost_from_here)
		// {
		// 	cout << x.first << " " << x.second << endl;
		// }


		int start = 0;
		while (start != n)
		{
			cout << start + 1 << " " << next_jump[start] + 1 << " ";
			start = next_jump[start] + 1;
		}

		cout << endl;
	}
	return 0;
}
