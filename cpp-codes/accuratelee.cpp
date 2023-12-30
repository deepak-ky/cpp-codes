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
		int len;
		cin >> len;
		string b;
		cin >> b;
		int first_1_idx = -1;
		int last_0_idx = -1;
		for (int i = 0; i < len; i++)
		{
			if (b[i] == '1')
			{
				first_1_idx = i;
				break;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (b[i] == '0')
			{
				last_0_idx = i;
			}
		}
		bool flag = false;
		if (last_0_idx < first_1_idx)
			flag = true;
		if ((len == 1) || (last_0_idx == -1) || (first_1_idx == -1) || (flag == true))
		{
			cout << b << endl;
		}
		else
		{
			b.erase(first_1_idx, (last_0_idx - first_1_idx));
			cout << b << endl;
		}
	}


	return 0;
}
