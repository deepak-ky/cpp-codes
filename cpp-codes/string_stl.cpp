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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	// vector<int> v;
	// for (int i = 0; i < 5; i++)
	// {
	// 	int x; cin >> x; v.push_back(x);
	// }
	// //remove(v.begin(), v.end(), 2);
	/*v.erase( v.begin() + 2);
	for (auto x : v)
	{
		cout << x << " ";
	}*/
	/*string b = "a";
	int b_i = stoi(b);
	wer(b_i);*/
	/*	char b[5] = {'1', '2', 'a', '4', '5'};
		int s = atoi(b);
		for (auto c : b)
		{
			cout << c << " ";
		}
		wer(s);*/
	string s;
	cin >> s;
	string str = "^^^";
	int pos = s.find(str);
	int pos1 = s.find(str, pos + 1);
	if (pos1 == string::npos)
	{
		cout << "not found";
	}
	else
	{
		wer(pos1);
	}
	return 0;
}
