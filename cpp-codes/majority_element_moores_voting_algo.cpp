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

int find_candidate(int *a, int n)
{
	int cand = a[0];
	int cnt_cand = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == cand)
		{
			cnt_cand++;
		}
		else if (a[i] != cand)
		{
			cnt_cand--;
		}

		if (cnt_cand == 0)
		{
			cand = a[i];
			cnt_cand = 1;
		}
	}
	return cand;
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

		int c = find_candidate(a, n);
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i] == c) cnt++;
		}
		if (cnt > (n / 2))
		{
			cout << c << endl;
		}
		else cout << -1 << endl;

	}
	return 0;
}
