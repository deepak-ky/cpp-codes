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
void max_in_every_k(int a[], int n, int k)
{
	deque<int> q;
	int i;
	for (i = 0; i < k; i++)
	{
		while ((!q.empty()) && (a[i] >= (a[q.back()])))
			q.pop_back();
		q.push_back(i);
	}
	for (; i < n; i++)
	{
		cout << (a[q.front()]) << " ";
		while ((!q.empty()) && ((q.front()) <= (i - k)))
			q.pop_front();
		while ((!q.empty()) && (a[i] >= (a[q.back()])))
			q.pop_back();
		q.push_back(i);
	}
	cout << a[q.front()];
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	int k;
	cin >> k;
	max_in_every_k(a, n, k);
	return 0;
}
