#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

int solve(int *a, int n, int k)
{
	//find out a element which is present in every subarry of size k and is the minimum possible
	//find out the elements which are present in every subarray and take the minimum out of them
	//number of subarrays of size k in an array of size n is : n - k + 1

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
	int *a = new int[n];
	bool all_same = true;
	int min_ele = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0)
		{
			if (a[i] != a[i - 1]) all_same = false;
		}
		min_ele = min(min_ele, a[i]);
	}
	if (all_same)
	{
		for (int i = 0; i < n; i++)
		{
			cout << min_ele << " ";
		}
	}
	else
	{
		cout << - 1 << " ";
		for (int i = 1; i < n - 1; i++)
		{
			cout << solve(a, n, i);
		}
		cout << min_ele;
	}
	cout << endl;

	return 0;
}
