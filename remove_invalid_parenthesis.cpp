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

int min_removal_to_make_valid(string a)
{
	//If this function returns a 0 value , that means that the entire string is balanced
	stack<char> s;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(')
		{
			s.push(a[i]);
		}
		else if (a[i] == ')')
		{
			if (s.empty())
			{
				s.push(')');
			}
			else if (s.top() == '(')
			{
				s.pop();
			}
			else if (s.top() == ')')
			{
				s.push(')');
			}
		}
		else continue;
	}

	return s.size();
}

void print_strings(string a, int mra, set<string> &sett, unordered_set<string> &is_tested)
{
	if (mra == 0)
	{
		if (min_removal_to_make_valid(a) == 0)
		{
			sett.insert(a);
		}
		return;
	}


	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '(' && a[i] != ')') continue;
		string  left = a.substr(0, i);
		string  right = a.substr(i + 1);
		string w = left + right;
		if (is_tested.find(w) == is_tested.end())
		{
			is_tested.insert(w);
			print_strings(w, mra - 1, sett, is_tested);
		}
	}
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

		int mr = min_removal_to_make_valid(a);

		unordered_set<string> is_tested;
		set<string> sett;
		print_strings(a, mr, sett, is_tested);

		for (auto x : sett)
		{
			cout << x << endl;
		}
	}
	return 0;
}
