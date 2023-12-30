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
	int size;
	cin >> size;
	vector<int> v;
	for (int i = 0; i < size; i++)
	{
		int w;
		cin >> w;
		v.push_back(w);
	}
	int n = v.size();
	vector<int> max_right_from_index(n, 0);

	for (int i = 0; i < n; i++)
	{

		int w = 0;
		int left = max(i - v[i], w);
		int right = min(i + v[i], n - 1);
		max_right_from_index[left] = max(max_right_from_index[left], right);
	}

	for (auto x : max_right_from_index)
	{
		cout << x << " ";
	}
	cout << endl;

	int num_fountains = 1;
	int right = max_right_from_index[0], next_right = 0;
	for (int i = 0; i < n; i++)
	{
		next_right = max(next_right, max_right_from_index[i]);
		if (i - 1 == right) {
			num_fountains++;
			right = next_right;
		}
	}

	cout << num_fountains;
	return 0;
}
