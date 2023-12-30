#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
//#define mod                          1000000007
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
	test
	{
		int n;
		cin >> n;
		int a[n];
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			a[i] = w;
			v.push_back(w);
		}
		int min_index = 0;
		int max_index = n - 1;

		int max_ele = *max_element(a, a + n);

		int mod =  max_ele + 2;

		for (int i = 0; i < n; i++)
		{
			if (i & 1)
			{
				a[i] += (a[min_index] % mod)  * mod;
				min_index++;
			}
			else
			{
				a[i] += (a[max_index] % mod)  * mod;
				max_index--;
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << a[i] / mod << " ";
		}
		cout << endl;
	}

	return 0;
}
