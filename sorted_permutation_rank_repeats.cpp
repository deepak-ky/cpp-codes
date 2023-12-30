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
int fact(int n)
{
	if (n <= 1) return 1;
	else return ((n) * (fact(n - 1)));
}
void change_map(map<char, int> &freq_mp, map<char, int> &index_mp, string a)
{
	freq_mp.clear();
	index_mp.clear();
	sort(a.begin(), a.end());
	for (int i = 0; i < a.length(); i++)
	{
		if (index_mp[a[i]] == 0)
		{
			index_mp[a[i]] = i + 1;
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		freq_mp[a[i]]++;
	}

}
int rank_string(string a)
{	//index of the character in the sorted string
	//frequency map
	map<char, int> freq_mp;
	map<char, int> index_mp;
	int ans = 0;
	for (int i = 0; i < a.length(); i++)
	{
		change_map(freq_mp , index_mp, a.substr(i, a.length() - i));
		// cout << a.substr(i, a.length() - i) << endl;
		// cout << "index" << endl;
		// for (auto x : index_mp)
		// {
		// 	cout << x.first << " :: " << x.second << endl;
		// }
		// cout << "freq" << endl;
		// for (auto x : freq_mp)
		// {
		// 	cout << x.first << " :: " << x.second << endl;
		// }
		//restrictions is npthing but multiply all the facotrials of that number
		int restrictions = 1;
		for (auto x : freq_mp)
		{
			restrictions *= fact(x.second);
		}
		int w = index_mp[a[i]];
		ans = (ans + ((w - 1) ) * ((fact(a.length() - i - 1) ) / (restrictions )));
	}
	return (ans + 1);
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
	string a;
	cin >> a;
	cout << rank_string(a);
	return 0;
}
