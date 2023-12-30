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
	unordered_map<string, vector<string> > phonebook;
	phonebook["deepak"].push_back("10004");
	phonebook["deepak"].push_back("100044");
	phonebook["deepak"].push_back("1000444");
	phonebook["deepak"].push_back("130004");
	phonebook["kumar"].push_back("8585");
	phonebook["kumar"].push_back("85851");
	phonebook["kumar"].push_back("85811");
	phonebook["kumar"].push_back("1d8585");

	for (auto x : phonebook)
	{
		cout << endl << x.first << " : ";
		for (auto p : x.second)
		{
			cout << p << ",";
		}
		cout << endl;
	}

	cout << endl;
	for (auto i : phonebook["deepak"])
	{
		cout << i << ";";
	}


	string n;
	cin >> n;
	if (phonebook.count(n) == 0)
	{
		cout << "\nAbsent";
	}
	else
	{
		cout << endl;
		for (auto i : phonebook[n])
		{
			cout << i << ";";
		}

	}

	return 0;
}
