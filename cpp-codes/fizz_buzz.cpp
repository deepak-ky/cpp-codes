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
	int A;
	cin >> A;
	vector<string> ans;
	for (int i = 1; i <= A; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			ans.push_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			ans.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			ans.push_back("Buzz");
		}
		else
		{
			string w = to_string(i);
			ans.push_back(w);
		}
	}
	for (auto x : ans)
	{
		cout << x << " ";
	}
	return 0;
}
