#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back


void product_of_three_distinct(int n)
{
	int num = n;
	vector<int> factors;
	bool is_prime = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			is_prime = false;
			while (n % i == 0)
			{
				n /= i;
				factors.pb(i);
			}
		}
	}
	if (is_prime)
	{
		cout << "NO";
		return;
	}
	else
	{
		if (n != 1)
		{
			factors.pb(n);
		}
	}
	//cout << "factors : "; for (auto x : factors) cout << x << " "; cout << endl;
	set<int> numbers;
	numbers.insert(factors[0]);
	if (factors[1] != factors[0])
	{

		numbers.insert(factors[1]);
		int i = 2;
		int c = 1;
		bool came_here = false;
		while (i < factors.size())
		{
			came_here = true;
			c *= factors[i];
			i++;
		}
		if (came_here)
			numbers.insert(c);
	}
	else if (factors[1] == factors[0])
	{
		numbers.insert(factors[1] * factors[2]);
		int i = 3;
		int c = 1;
		bool came_here = false;
		while (i < factors.size())
		{
			came_here = true;
			c *= factors[i];
			i++;
		}
		if (came_here)
			numbers.insert(c);

	}
	if (numbers.size() >= 3)
	{
		cout << "YES\n";
		for (auto x : numbers) cout << x << " ";
	}
	else
	{

		cout << "NO";
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
	test
	{
		int n;
		cin >> n;
		product_of_three_distinct(n);
		cout << endl;
	}
	return 0;
}
