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
	int a, b;
	cin >> a >> b;
	// if ((b % a) != 0)
	// {
	// 	cout << "NO";
	// }
	// else
	// {
	// 	cout << "YES\n";
	// 	double q = b / a;
	// 	double w = a;
	// 	cout << log(q) / log(w);
	// }


	//In the above approach I am not considering the case of a = 10 and b = 50 and my else condition gets called and hence the answer is wrong

	int ans = -1;
	while (b % a == 0)
	{
		b = b / a;
		ans += 1;
	}
	if (b == 1)
	{
		cout << "YES\n" << ans;
	}
	else cout << "NO";

	return 0;
}
