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
void prime_sieve(int *p, int n)
{
	for (int i = 3; i <= (n); i += 2)
	{
		p[i] = 1;
	}
	for (int i = 3; i <= (n); i += 2)
	{
		if (p[i] == 1)
		{
			for (int j = (i * i); j <= n; j = j + i)
			{
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[1] = p[0] = 0;

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
	int n;
	cin >> n;
	int p[n + 3] = {0};
	prime_sieve(p, n + 3);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] == 1)
		{
			//wer(i);
			cnt++;
		}
	}
	cout << cnt % n;

	return 0;
}
