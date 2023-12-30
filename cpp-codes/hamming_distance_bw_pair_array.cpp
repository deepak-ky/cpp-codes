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
int hamming_distance(vector<int> v)
{
	int sum = 0;
	for (int i = 31; i >= 0; i--)
	{
		int cnt1 = 0; //count of 1 at the ith position for all numbers
		int cnt2 = 0; //count of 0 at the ith position for all numbers
		for (int j = 0; j < v.size(); j++)
		{
			int k = v[j] >> i;
			if (k & 1) cnt1++;
			else cnt2++;
		}
		int w = cnt1 * cnt2 * 2 ;
		sum += w;
	}
	return sum;
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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		v.push_back(w);
	}
	cout << hamming_distance(v);

	return 0;
}
