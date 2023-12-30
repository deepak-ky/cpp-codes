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

vector<string> ans;

bool is_valid(string a)
{
	stack<char> s;
	for (int i = 0; i < a.length(); i++)
	{
		char ch = a[i];
		if (ch == '(')
		{
			s.push(ch);
		}
		else
		{
			if (s.empty())
			{
				return false;
			}
			else if (s.top() == ')')
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}

	if (s.empty())
	{
		return true;
	}
	else return false;

}


void generate_all_valid(string s, int idx, int n)
{
	if (idx == n)
	{
		if (is_valid(s))
		{
			ans.push_back(s);
		}
		return;
	}

	s[idx] = '(';
	generate_all_valid(s, idx + 1, n);
	s[idx] = ')';
	generate_all_valid(s, idx + 1, n);
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

		n = 2 * n;


		string s = "";
		for (int i = 0; i < n; i++)
		{
			s += "(";
		}

		generate_all_valid(s, 0, s.length());


		for (auto x : ans)
		{
			cout << x << endl;
		}
	}
	return 0;
}
