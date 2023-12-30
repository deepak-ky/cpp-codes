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

bool compare(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	else return false;
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

	int a[] = {10, 20, 30, 40, 50};
	vector<int> b(a, a + 5);
	for (auto x : b)
	{
		cout << x << " ";
	}

	cout << endl << endl;

	vector<int> v1(5, -1);

	vector<int> v2(v1.begin(), v1.end());

	vector<int> v3{1, 2, 3, 4, 5, 6};

	int n;
	cin >> n;
	vector<int> v;
	v.reserve(12);
	cout << "V.size() : " << v.size() << endl;
	for (int i = 0; i < n; i++)
	{
		int w; cin >> w;
		v.push_back(w);
		cout << "V.capacity now : " << v.capacity() << endl;
	}


	cout << v.capacity() << endl;
	cout << v1.capacity() << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}


	cout << endl << endl;
	sort(v3.begin(), v3.end(), compare);
	for (auto x : v3)
	{
		cout << x << " ";
	}
	return 0;
}
