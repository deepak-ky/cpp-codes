#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void update(string &s, int idx, int k, int n)
{
	int w = 0;
	int l = max(w, idx - k);
	int r = min(idx + k, (n - 1));
	for (int i = l; i <= r; i++)
	{
		if (i != idx)
		{
			s[i] = '1';
		}
	}
}
bool check_original(string s, int idx, int k, int n)
{
	int w = 0;
	int l = max(w, idx - k);
	int r = min(idx + k, (n - 1));
	for (int i = l; i <= r; i++)
	{

		if (s[i] == '2')
		{
			return false;
		}

	}
	return true;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int a[n];
		int i = 0;
		while (i < n)
		{
			if (s[i] == '1')
			{
				s[i] = '2';
				update(s, i, k, n);
				i = i + k + 1;
			}
			else i++;

		}
		//cout << s << endl;
		int cnt = 0;
		int l = 0;
		while (l < n)
		{
			if (s[l] == '0')
			{
				if (check_original(s, i, k, n))
				{
					s[l] = '1';
					cnt++;
					update(s, l, k, n);
					//cout << s << endl;
				}
			}
			l++;
		}
		cout << cnt << endl;
	}


	return 0;
}
