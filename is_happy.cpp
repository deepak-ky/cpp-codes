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
bool isHappy(int n) {
	if (n == 1)
	{
		return true;
	}
	set<int> s;
	while (n != 1)
	{

		int sum_square = 0;
		while (n > 0)
		{
			int r = n % 10;
			sum_square += r * r;
			n = n / 10;
		}
		if (sum_square == 1)
		{
			return true;
		}
		if (s.find(sum_square) != s.end())
		{
			break;
		}
		s.insert(sum_square);
		n = sum_square;
	}
	return false;
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
	int n;
	cin >> n;
	if (isHappy(n))
	{
		cout << "True";
	}
	else cout << "false";
	return 0;
}
