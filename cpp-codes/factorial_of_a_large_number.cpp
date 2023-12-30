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

vector<int> multiply(vector<int> a, int b)
{
	//it will be a very big number in int , multiplied by a , number
	int n = a.size();
	int carry = 0;
	vector<int> ans;
	for (int i = (n - 1); i >= 0; i--)
	{
		int w = (a[i] * b)  + carry;
		ans.push_back(w % 10);
		carry = w / 10;
	}
	while (carry != 0)
	{
		int w = carry % 10;
		ans.pb(w);
		carry = carry / 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> fact(int n)
{
	vector<int> v;
	v.pb(1);
	if (n <= 1)
	{
		return v;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			v = multiply(v, i);
		}
		return v;
	}
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
		vector<int> v = fact(n);
		for (auto x : v)
		{
			cout << x;
		}
	}
	return 0;
}
