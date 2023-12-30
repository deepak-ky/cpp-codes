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

const int N = 3005;
int p[N] = {0};
//here 0 -> prime
// > 0   -> not prime and p[i] denotes the number of distinct divisors that it has

void fill_array()
{
	p[0] = p[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (p[i] == 0)
		{
			for (int j = i + i; j < N; j += i)
			{
				p[j]++;
			}
		}
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
	fill_array();
	// for (int i = 0; i < 15; i++)
	// {
	// 	cout << i << "->" << p[i] << endl;
	// }
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 2)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
