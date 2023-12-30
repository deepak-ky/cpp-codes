#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}
set<string> ss;
//The string here is not a copy of the original string
void compute_permutations(string &s, int idx)
{
	if (idx == s.length())
	{
		//cout << s << endl;
		ss.insert(s);
		return;
	}
	for (int i = idx; i < s.length(); i++)
	{
		swap(s[idx], s[i]);
		compute_permutations(s, idx + 1);

		//If the string is passed by value then there is no need for backtracking as a new
		//copy of the string is passed and not the original string

		//Backtracking - to restore the original string

		swap(s[idx], s[i]);
	}
	return;


}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s = "1234";
		//cin >> s;
		compute_permutations(s, 0);
		/*cout << endl << s << " ";*/

		for (auto x : ss)
		{
			cout << x << endl;
		}

	}
	return 0;
}
