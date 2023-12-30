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
		string a;
		cin >> a;
		int len = a.length();
		int res = 0;
		int cur = 0;
		int helper = 1;
		for (int i = 0; i < len; i++)
		{
			//wer(i);
			res = res + 1;
			//wer(res);
			if (a[i] == '-')
				cur--;
			else cur++;
			//wer(cur);
			if (cur < 0)
			{
				//cout << "\n" << "inside loop \n";
				res += i + 1;
				//cout << "\nres HHere : " << res << endl;


				cur = 0;
			}
		}
		cout << res << endl;
	}

	return 0;
}
