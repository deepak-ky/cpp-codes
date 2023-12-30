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
	if (n == 0 || n == 1) return false;
	int cb_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int len = sizeof(cb_numbers) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		if (n == cb_numbers[i]) return true;
	}
	for (int i = 0; i < len; i++)
	{
		if ((n % cb_numbers[i]) == 0) return false;
	}
	return true;
}
bool is_valid(bool * visited, int l, int e)
{
	for (int i = l; i <= e; i++)
	{
		if (visited[i]) return
			    false;
	}
	return true;
}
int covert_string_to_integer(string s)
{
	int sum = 0;
	int l = s.length();
	int i = 0;
	while ( i < l)
	{
		int a = s[i] - '0';
		sum = sum * 10;

		sum = sum + a;
		i++;
	}
	return sum;
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n; int cnt = 0;
	string s;
	cin >> s;
	bool visited[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			string a = s.substr( i, j - i + 1);
			int w = covert_string_to_integer(a);

			if ((is_a_cb_number(w)) && (is_valid(visited, i, j)))
			{

				wer(w);
				cnt++;
				for (int k = i; k <= j; k++)
				{
					visited[k] = true;
				}
			}

		}
	}
	cout << cnt << endl;

	return 0;
}
