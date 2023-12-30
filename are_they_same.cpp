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

bool is_equivalent(string a, string b)
{
	if (a == b)
	{
		return true;
	}
	else if (a.length() != b.length())
	{
		return false;
	}
	else if (a.length() % 2 != 0)
	{
		return false;
	}
	else
	{
		//both the strings have the same size and both have even length
		string a1 = a.substr(0, a.length() / 2);
		string a2 = a.substr(a.length() / 2, a.length() / 2);
		string b1 = b.substr(0, b.length() / 2);
		string b2 = b.substr(b.length() / 2, b.length() / 2);

		bool flag1 = is_equivalent(a1, b1) & is_equivalent(a2, b2);
		bool flag2 = is_equivalent(a1, b2) & is_equivalent(a2, b1);

		if (flag1 || flag2)
		{
			return true;
		}
		else return false;
	}

}
int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{

		string a, b;
		cin >> a >> b;
		if (is_equivalent(a, b))
		{
			yes;
		}
		else no;
	}
	return 0;
}
