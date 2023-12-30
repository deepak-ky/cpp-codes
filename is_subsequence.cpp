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

bool is_subsequence(string a, string b)
{
	int i = 0;
	int j = 0;
	if (b.length() == 0) return true;
	int target = b[j];

	while (i < a.length())
	{
		if (a[i] == target)
		{
			j++;
			if (j == b.length())
			{
				return true;
			}
			target = b[j];
		}
		i++;
	}
	return false;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;


		if (is_subsequence(a, b))
		{
			yes;
		}
		else no;
	}
	return 0;
}
