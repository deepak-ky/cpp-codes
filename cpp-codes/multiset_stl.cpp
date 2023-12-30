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
	multiset<int> ms;
	multiset<int> ms1;
	int a[5] = {1, 1, 2, 3, 4};
	ms1.insert(a, a + 5);
	for (auto x : ms1)
	{
		cout << x << " ";
	}
	cout << endl;
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(40);
	ms.insert(40);
	ms.insert(40);
	ms.insert(10);

	//ms.erase(10);
	int w = ms.count(10);
	wer(w);
	cout << endl;
	for (auto x : ms)
	{
		cout << x << " ";
	}

	//find
	cout << endl;
	auto it = ms.find(30);
	cout << *it;

	//equal range
	multiset<int>::iterator it2;
	pair<multiset<int>::iterator , multiset<int>::iterator  > range = ms.equal_range(40);
	cout << endl;
	for (auto it = range.first; it != range.second; it++)
	{
		cout << *it << " - ";
	}
	cout << endl;

	//using lower  bound and upper bound
	for (auto it = ms.lower_bound(10); it != ms.upper_bound(30); it++)
	{
		cout << *it << " - ";

	}



	return 0;
}
