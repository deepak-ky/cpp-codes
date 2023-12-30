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
int get_val(vector<int> v, int i)
{
	if (i >= v.size() || i < 0) return 1;
	else return v[i];
}



int burst_balloons(vector<int> v)
{
	//base case
	if (v.size() == 0) return 0;

	//recursive case
	i
	int temp = INT_MIN;
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> sample(v);
		sample.erase(sample.begin() + i);
		int t = burst_balloons(sample);
		t += get_val(v, i - 1) * get_val(v, i) * get_val(v, i + 1);
		temp = max(t, temp);
	}
	return temp;
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
	int n = v.size();
	int dp[n][n];
	memset(dp, -1, sizeof(dp));
	cout << burst_balloons(v, dp);
	return 0;
}
