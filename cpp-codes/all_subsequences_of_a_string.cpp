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

set<string> subseq;
//THIS WILL HANDLE THE CASE FOR DUPLICATES ALSO
void solve(string a, int i)
{
	int ind_pos = 0;
	string s = "";
	while (i > 0)
	{
		if (i & 1)
		{
			s += a[ind_pos];
		}
		ind_pos++;
		i = i >> 1;
	}
	subseq.insert(s);


}
void generate_subseq(string a)
{
	int len = a.length();
	int num = pow(2, len) - 1;
	for (int i = 0; i <= num; i++)
	{
		//START FROM 0 HERE IF YOU WANT EMPTY SUBSEQUENCE ALSO
		solve(a, i);
	}
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
	cout << "The subsequences of the string are : \n";
	generate_subseq(a);
	for (auto x : subseq)
	{
		cout << x << "\n";
	}
	return 0;
}
