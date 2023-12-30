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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		int ans = 0;
		int left = 0;
		int right = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(')
			{
				left++;
			}
			else right++;
			if (left == right)
			{
				ans = max(ans , 2 * right);
			}
			else if (right > left)
			{
				left = 0;
				right = 0;
			}
		}
		left = 0;
		right = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '(')
			{
				left++;
			}
			else right++;
			if (left == right)
			{
				ans = max(ans , 2 * left);
			}
			else if (left > right)
			{
				left = 0;
				right = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


//(()(()(()()(((((()((()())())(())