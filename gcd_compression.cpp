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
		vector<int> odd_ind;
		vector<int> even_ind;
		for (int i = 1; i <= (2 * n); i++)
		{
			int x;
			cin >> x;
			if (x & 1)
			{
				odd_ind.push_back(i);
			}
			else even_ind.push_back(i);
		}
		int odd_size  = odd_ind.size();
		if (odd_size & 1) odd_ind.pop_back();
		//cout << odd_ind.size() << endl;
		int even_size  = even_ind.size();
		if (even_size & 1) even_ind.pop_back();
		//cout << even_ind.size() << endl;
		int i = 0;
		int cnt = 1;
		while (cnt <= (n - 1) && (i < odd_ind.size()))
		{
			cout << odd_ind[i] << " " << odd_ind[i + 1] << endl;
			cnt++;
			i = i + 2;
		}
		int j = 0;
		while (cnt <= (n - 1) && (j < even_ind.size()))
		{
			cout << even_ind[j] << " " << even_ind[j + 1] << endl;
			cnt++;
			j = j + 2;
		}
	}


	return 0;
}
