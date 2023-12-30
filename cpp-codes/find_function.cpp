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
	int a[] = {1, 2, 3, 4};
	int key;
	cin >> key;
	int n = 4;
	auto it = find(a, a + 4, key);
	int index = it - a;
	if (index == n)
	{
		cout << "element not present";
	}
	else cout << index;
	cout << endl;

	unordered_set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	auto it1 = s.find(key);
	if (it1 == s.end())
	{
		cout << "element not present";
	}
	else cout << "element present is : " << *it1;
	return 0;
}
