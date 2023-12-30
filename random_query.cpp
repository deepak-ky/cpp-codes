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
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	map<int, int> last_occ;
	int unique_element_till[n];
	unique_element_till[0] = 1;
	last_occ[a[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		unique_element_till[i] = unique_element_till[i - 1] + (i + 1) - last_occ[a[i]];
		last_occ[a[i]] = i + 1;
	}
	//out(unique_element_till, n);
	int sum = 0;
	for (auto x : unique_element_till)
	{
		sum += x;
	}



	double f;
	f = ((2 * sum) - n);
	double d = (n * n);
	cout  << fixed << setprecision(6) << f / d << endl;
	return 0;
}
