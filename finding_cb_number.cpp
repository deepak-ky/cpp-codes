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
bool is_a_cb_number(int n)
{
	if (n == 0 || n == 1)
	{
		return false;
	}
	if ( n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29)
	{
		return true;
	}
	if ( n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0 && n % 11 != 0 && n % 13 != 0 && n % 17 != 0 && n % 19 != 0 && n % 23 != 0 && n % 29 != 0 )
	{
		return true;
	}
	return false;
}
int covert_string_to_integer(string s)
{
	int sum = 0;
	int l = s.length();
	int i = 0;
	while ( i < l)
	{
		int a = s[i] - '0';
		sum = sum + a;
		sum = sum * 10;
	}
	return sum / 10;
}
bool is_visited(bool * visited, int l, int e)
{
	for (int i = l; i < e; i++)
	{
		if (visited[i])
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

	int len;
	cin >> len;
	string str;
	cin >> str;
	int cnt = 0;
	bool *visited;
	visited = new bool[len];
	for (int i = 0; i < len; i++) visited[i] = false;
	for (int i = 1 ; i <= len; i++)
	{
		for (int k = 0; k <= (len - i); k++)
		{
			int e = k + i;
			string s = str.substr(k, e - k);
			int w = covert_string_to_integer(s);
			if (is_a_cb_number(w) && is_visited(visited, k, e))
			{
				cnt++;
				for (int j = k; j < e; j++)
				{
					visited[j] = true;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}



