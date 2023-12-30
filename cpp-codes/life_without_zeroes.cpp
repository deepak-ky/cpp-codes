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
	string a;
	string b;
	cin >> a >> b;
	int a_1 = stoi(a);
	int b_1 = stoi(b);
	int ab = a_1 + b_1;
	/*ostringstream c;
	c << ab;
	string c1 = c.str();*/
	string c1 = to_string(ab);
	c1.erase(remove(c1.begin(), c1.end(), '0'), c1.end());
	int abc = stoi(c1);
	a.erase(remove(a.begin(), a.end(), '0'), a.end());
	b.erase(remove(b.begin(), b.end(), '0'), b.end());
	int a_11 = stoi(a);
	int b_11 = stoi(b);
	int ab_1 = a_11 + b_11;
	if (abc == ab_1)
	{
		cout << "YES";
	}
	else cout << "NO";

	return 0;
}
