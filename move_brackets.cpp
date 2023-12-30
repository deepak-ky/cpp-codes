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
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		stack<char> s;
		for (int i = 0; i < n; i++)
		{
			char ch = str[i];
			if (ch == '(')
			{
				s.push(ch);
				//cout << endl << s.top();
			}
			else if (ch == ')')
			{
				if (s.empty())
				{
					s.push(ch);
					//cout << endl << s.top();
				}
				else
				{
					char top = s.top();
					if (top == '(')
					{
						s.pop();
					}
					else
					{
						s.push(ch);
						//cout << endl << s.top();
					}
				}
			}

		}
		if (s.size() == 0)
		{
			cout << 0 << endl;
		}
		else cout << s.size() / 2 << endl;
	}
	return 0;
}
