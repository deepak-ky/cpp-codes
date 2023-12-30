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
	int a[] = {1, 2, 4, 5};
	//map<int, int> mp1;

	for (auto x : a)
	{
		x = 5;
		//because x is read only
		//x can only tell me what the value is but i cannot do anything to the value
	}

	cout << endl;
	out(a, 4);
	cout << endl;
	map<int, int> mp;
	mp[1] = 2;
	mp[3] = 4;
	mp[6] = 5;
	mp[8] = 9;
	//mp.erase(3);
	auto it = mp.begin();
	//it++;
	mp.erase(it);
	// for (auto i = mp.begin(); i != mp.end(); i++)
	// {
	// 	mp.erase(i);
	// }
	// for (auto x : mp)
	// {	//This is able to change it because x.second is not the value of the key but just a variable which displays the value
	// 	if (x.first == 3)
	// 		mp.erase(x.first);
	// 	//x.second = 6;
	// 	//read only operator
	// 	//x.first = 9;
	// }
	for (auto x : mp)
	{
		cout << x.first << " " << x.second << endl;
	}


	cout << endl << "Mutlimap : " << endl;

	multimap<int, int> mmp;
	mmp.insert({1, 2});
	mmp.insert({2, 3});
	mmp.insert({1, 2});
	mmp.insert({2, 1});
	mmp.insert({1, 3});
	mmp.insert({3, 3});
	mmp.insert({3, 3});
	mmp.insert({4, 5});
	mmp.insert({5, 6});
	//mmp.erase(2);
	for (auto x : mmp)
	{
		cout << x.first << " " << x.second << endl;
	}
	auto it5 = mmp.find(5);
	if (it5 == mmp.end())
	{
		cout << "Not present";
	}
	else cout << "present";
	auto it6 = mmp.lower_bound(1);
	auto it7 = mmp.upper_bound(2);

	for (auto i = it6; i != it7; i++)
	{
		cout << i->first << " -> " << i->second << endl;
	}
	cout << endl;
	mp[1] = 9;
	if (mmp.count(1) == 3)
	{
		cout << "Yes";
	}
	else cout << "No";
	return 0;
}
