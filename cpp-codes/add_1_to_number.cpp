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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n1;
	cin >> n1;
	vector<int> a;
	for (int i = 0; i < n1; i++)
	{
		int w ;
		cin >> w;
		a.push_back(w);
	}
	int carry = 1;
	int value = 0;
	for (int i = n1 - 1; i >= 0; i--)
	{


		int w = a[i] + carry;
		if (w > 9)
		{
			a[i] = 0;
			//value = 0;
			carry = 1;
		}
		else
		{
			a[i] = w;
			//value = 0;
			carry = 0;
		}


	}
	if (carry == 1)
	{
		auto it = a.begin();
		a.insert(it, 1);
	}
	while (a[0] == 0)
	{
		auto it = a.begin();
		a.erase(it);
	}
	for (auto x : a)
	{
		cout << x << ", ";
	}
	return 0;
}
