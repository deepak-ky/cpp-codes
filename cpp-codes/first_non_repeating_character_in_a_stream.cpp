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
	string a;
	getline(cin, a);

	deque<char> dq;

	unordered_map<char, int> freq;

	for (int i = 0; i < a.length(); i++)
	{
		int ch = a[i];

		freq[ch]++;
		//keeping on popping the elements until the character at q.front has a frequency
		//of 1 or the deque is completely empty
		dq.push_back(ch);


		while ( freq[dq.front()] != 1 && !dq.empty())
		{
			dq.pop_front();
		}
		if (dq.empty())
		{
			cout << -1 << " ";
		}
		else cout << dq.front() << " ";
	}
	return 0;
}
