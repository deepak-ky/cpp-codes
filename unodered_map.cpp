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
	map<string, int> m;
	//1. Different ways to insert into the map
	m.insert(make_pair("mango", 100));

	pair<string, int > p;
	p.first = "Apple";
	p.second = 120;
	m.insert(p);

	m["Banana"] = 150;

	//2.Ways to search in a map

	string key;
	cin >> key;
	auto it = m.find(key);
	if (it != m.end())
	{
		cout << "\nPrice of " << key << " is : " << m[key] << endl;
	}
	else
	{
		cout << "\nNot found";
	}
	//erase
	m.erase(key);

	//another way to find a particular object as we know that it stores only once
	if (m.count(key))
	{
		cout << "\nPrice of " << key << " is : " << m[key] << endl;
	}
	else
	{
		cout << "\nNot found";
	}

	//update

	m["mango"] = 500;
	cout << endl << m["mango"];

	//iterate over all the pairs
	m["pineapple"] = 150;
	m["orane"] = 160;
	m["litchi"] = 200;
	cout << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}

	for (auto x : m)
	{
		cout << endl << x.first << "::" << x.second;
	}



	return 0;
}
