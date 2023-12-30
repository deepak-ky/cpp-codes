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

int longest_valid_parenthesis(string a)
{
	stack<char> s;
	stack<int> from_where_to_start;

	int ans = 0;

	from_where_to_start.push(-1);

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '(')
		{
			s.push('(');
			from_where_to_start.push(i);
		}
		else
		{
			//we have a opening bracket
			if (s.empty())
			{
				//we currently have no valid opening bracket
				from_where_to_start.push(i);
			}
			else
			{

				s.pop();
				from_where_to_start.pop();


				int len = i - from_where_to_start.top();
				ans = max(ans, len);
			}
		}
	}

	return ans;
}

int longest_valid_parenthesis_using_one_stack(string a)
{
	stack<int> s;

	int ans = 0;

	s.push(-1);

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '(')
		{
			s.push(i);
		}
		else
		{
			//we have a opening bracket
			if (s.empty())
			{
				//we currently have no valid opening bracket
				s.push(i);
			}
			else
			{
				s.pop();
				if (s.empty())
				{
					//case of ")"
					s.push(i);
				}
				else
				{
					int len = i - s.top();
					ans = max(ans, len);
				}
			}
		}
	}

	return ans;
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a;
		cin >> a;
		cout << longest_valid_parenthesis(a);

	}
	return 0;
}
