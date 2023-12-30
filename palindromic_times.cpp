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
	string times[] = {"01:10",
	                  "02:20",
	                  "03:30",
	                  "04:40",
	                  "05:50",
	                  "10:01",
	                  "11:11",
	                  "12:21",
	                  "13:31",
	                  "14:41",
	                  "15:51",
	                  "20:02",
	                  "21:12",
	                  "22:22",
	                  "23:32",
	                 };
	int n = sizeof(times) / sizeof(string);
	string p;
	cin >> p;
	auto it = upper_bound(times, times + n, p);
	int w = it - times;
	if (w == 15)
	{
		cout << "00:00";
	} else cout << times[w];

	return 0;
}
