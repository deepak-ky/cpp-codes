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
bool isgreater(int mid, int prod, int n)
{
	if ((pow(mid, n)) > prod)
	{
		return true;
	}
	else return false;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	int prod = 1;
	// for (int i = 0; i < n; i++)
	// {
	// 	prod = prod * a[i];
	// 	wer(prod);
	// }
	// cout << endl << prod;

	int s = *min_element(a, a + n);
	int e = 10000000000;

	// int ans = INT_MAX;
	// while (s <= e)
	// {
	// 	int mid = (s + e) / 2;
	// 	if (isgreater(mid, prod, n))
	// 	{
	// 		ans = min(mid, ans);
	// 		e = mid - 1;
	// 	}
	// 	else
	// 	{
	// 		s = mid + 1;
	// 	}
	// }
	// cout  << endl << ans;
	int w = 18518700000000;
	int w1 = 90980454;
	cout << endl << w << endl << w1 << endl;
	int w2 = w * w1;
	cout << w2;
	return 0;
}
