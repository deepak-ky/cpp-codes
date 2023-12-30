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
int precdence(char ch)
{
	if (ch == '^')
	{
		return 3;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else return 0;
}
string infix_to_postifx(string infix)
{
	stack<char> s;
	string ans = "";
	for (int i = 0; i < infix.length(); i++)
	{
		char ch = infix[i];
		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			ans += ch;
		}
		else
		{
			if (ch == '(')
			{
				s.push(ch);
			}
			else if (ch == ')')
			{
				while (s.top() != '(' && !s.empty())
				{
					ans += s.top();
					s.pop();
				}
				s.pop();
			}
			else
			{
				if (s.empty() == true || (precdence(ch) >= precdence(s.top())))
				{
					s.push(ch);
				}
				else
				{
					while (!s.empty() && precdence(ch) <= precdence(s.top()))
					{
						ans += s.top();
						s.pop();
					}
					s.push(ch);
				}
			}
		}
	}
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	return ans;
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string infix;
	cin >> infix;
	cout << infix_to_postifx(infix);
	return 0;
}
