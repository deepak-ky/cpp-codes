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
#define s                            second

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

int string_to_int(string a)
{

	if (a.length() == 0)
	{
		return 0;
	}
	int n = a.length();
	int c = a[0] - '0';
	c = c * pow(10, n - 1);
	string w = a.substr(1, n - 1);

	return c + string_to_int(w);

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a;
		cin >> a;
		int w = string_to_int(a);
		cout << w;

	}
	return 0;
}
