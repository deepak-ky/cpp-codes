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

class p
{
public:
	int prod;
	bool to_add;
};

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

p solve(int i)
{
	p r;
	int cnt_set_bits = 0;
	int ind_pos = 0;
	int denom = 1;
	while (i > 0)
	{
		if (i & 1)
		{
			denom *= primes[ind_pos];
			cnt_set_bits++;
		}
		ind_pos++;
		i = i >> 1;
	}
	if (cnt_set_bits & 1) r.to_add = true;
	else r.to_add = false;

	r.prod = denom;

	return r;
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
	test
	{
		int n;
		cin >> n;

		int ans = 0;
		int num = pow(2, 8) - 1;
		for (int i = 1; i <= num; i++)
		{
			p p1 = solve(i);
			if (p1.to_add)
			{
				ans += (n / p1.prod);
			}
			else
			{
				ans -= (n / p1.prod);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
