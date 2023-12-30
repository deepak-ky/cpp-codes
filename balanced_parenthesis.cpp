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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string w;
	cin >> w;
	stack<int> s;
	int flag = 0;
	for (int i = 0; i < (w.length()); i++)
	{
		if (w[i] == '(' || w[i] == '{' || w[i] == '[')
		{
			s.push(w[i]);
		}
		else
		{
			if (w[i] == ')')
			{
				if ((s.empty() == true) || (s.top() != '('))
				{

					flag = 1;
					break;
				}
				else if (s.top() == '(')
				{
					s.pop();
				}
			}
			else if (w[i] == '}')
			{
				if ((s.empty() == true) || (s.top() != '{'))
				{

					flag = 1;
					break;
				}
				else if (s.top() == '{')
				{
					s.pop();
				}
			}
			else if (w[i] == ']')
			{
				if ((s.empty() == true) || (s.top() != '['))
				{

					flag = 1;
					break;
				}
				else if (s.top() == '[')
				{
					s.pop();
				}
			}
		}
	}
	if (flag == 0 && s.empty() == true)
	{
		cout << "Yes";
	}
	else {cout << "No";}
	return 0;
}
