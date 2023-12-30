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
void insert_at_bottom(stack<int> &s, int t)
{
	if (s.empty())
	{
		s.push(t);
		return;
	}
	int y = s.top();
	s.pop();
	insert_at_bottom(s, t);
	s.push(y);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int call[n], ideal[n];
	asdf(call, n);
	asdf(ideal, n);

	stack<int> s;
	for (int i = (n - 1); i >= 0; i--)
	{
		s.push(call[i]);
	}
	int value = 0;
	for (int i = 0; i < n; i++)
	{

		if (ideal[i] == s.top())
		{
			value = value + 1;
			s.pop();
		}
		else if (ideal[i] != s.top())
		{
			int cnt = 0;
			while (ideal[i] != s.top())
			{

				int w = s.top();

				s.pop();
				insert_at_bottom(s, w);
				cnt++;
			}

			value = value + cnt + 1;

			s.pop();

		}


	}
	cout  << value;

	return 0;
}
