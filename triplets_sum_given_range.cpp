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
int solve(vector<string> v1)
{
	int n = v1.size();


	if (n <= 2)
	{
		return 0;
	}
	//vector array;
	vector<float> v1;
	vector<float> v2;
	vector<float> v3;

	for (int i = 0; i < n; i++)
	{
		float w = stof(v1[i]);
		if (w < (2 / 3))
		{
			v1.push_back(w);
		}
		else if (w >= 2 / 3 && w <= 1)
		{
			v2.push_back(w);
		}
		else if (w > 1 && w < 2)
		{
			v3.push_back(w);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());


	if (v1)
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
	vector<string> v = {"0.366507", "0.234601", "2.126313", "1.372403", "2.022170", "0.308558", "2.120754", "1.561462"};
	/*for (int i = 0; i < n; i++)
	{
		string w;
		cin >> w;
		v.push_back(w);
	}

	*/

	cout << solve(v);

	return 0;
}
