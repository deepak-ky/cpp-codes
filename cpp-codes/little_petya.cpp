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
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
	}

	int flag = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] > b[i])
		{
			flag = 1;
			cout << 1;
			break;
		}
		else if (a[i] < b[i])
		{
			flag = 1;
			cout << -1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << 0;
	}
	return 0;
}
