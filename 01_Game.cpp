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
bool delete_char(string &b)
{
	int len = b.length();
	for (int i = 0; i < len; i++)
	{
		if (b[i] == '0' && b[i + 1] == '1')
		{
			b.erase(i, 2);
			return true;
		}
		else if ((b[i] == '1' && b[i + 1] == '0'))
		{
			b.erase(i, 2);
			return true;
		}
	}
	return false;
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		string b;
		cin >> b;
		int cnt = 0;
		while (delete_char(b))
		{
			cnt++;
		}
		if (cnt & 1) cout << "DA" << endl;
		else cout << "NET" << endl;
	}


	return 0;
}
