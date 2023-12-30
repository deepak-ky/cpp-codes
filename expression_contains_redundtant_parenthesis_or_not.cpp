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

bool is_redundant(string a)
{
	stack<char> s;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i]  == '('  || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
		{
			s.push(a[i]);
		}
		else if (a[i] == ')')
		{
			if (s.top() == '(')
			{
				return true;
			}
			while (s.top() != '(')
			{
				s.pop();
			}
			s.pop();
		}
		else continue;
	}
	return false;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		if (is_redundant(a))
		{
			yes;
		}
		else no;

	}
	return 0;
}
