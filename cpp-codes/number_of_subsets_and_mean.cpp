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

float return_mean_of_subset(int a[], int i)
{
	int i1 = i;
	float number_of_elements = 0;
	float mean_sum = 0;
	int ind_pos = 0;
	while (i > 0)
	{
		if (i & 1)
		{
			number_of_elements++;
			mean_sum += a[ind_pos];
		}
		ind_pos++;
		i = i >> 1;
	}
	float mean = ((mean_sum) / (number_of_elements));

	return mean;
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
	test
	{
		int n;
		cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			mp[a[i]]++;
		}
		auto it = m.begin();
		auto it1 = m.end();
		it1 -;
		cout << fast_power(2, it1->second) - 1 << " " << fast_power(2, it->second) - 1 << endl;
	}

	return 0;
}
