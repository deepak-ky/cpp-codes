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

list<vector<int>> s;

void  combinational_sum(int idx, vector<int> a, int curr_sum, int n, vector<int> v)
{
	/*wer(idx);
	wer(curr_sum);
	*/

	if (curr_sum == 0)
	{
		s.push_front(v);
		return;
	}

	if (idx == n)
	{
		return;
	}

	int w = curr_sum;
	while (w >= 0)
	{
		combinational_sum(idx + 1, a, w, n, v);
		w -= a[idx];
		v.push_back(a[idx]);
	}

	return;
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

		int k;
		cin >> k;
		vector<int> b;
		sort(a, a + n);
		int i = 1;
		b.push_back(a[0]);
		while (i < n)
		{
			if (a[i] != a[i - 1])
			{
				b.push_back(a[i]);

			}
			i++;
		}
		vector<int> v;

		combinational_sum(0, b, k, b.size(), v);


		for (auto x : s)
		{
			for (auto y : x)
			{
				cout << y << " ";
			}
			cout << endl;
		}


	}
	return 0;
}
