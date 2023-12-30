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
#define se                            second

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

class ProductOfNumbers
{
	vector<int> v;
	set<int> s;
	int to_multiply;
public:
	ProductOfNumbers()
	{
		to_multiply = 1;

	}

	void add(int num)
	{
		int index = v.size();
		if (num == 0)
		{
			to_multiply = 1;
			v.push_back(1);
			s.insert(index);

		}
		else
		{
			to_multiply *= num;
			v.push_back(to_multiply);
		}
	}

	int getProduct(int k)
	{
		int n = v.size();
		if (s.empty())
		{
			int p = v[n - 1];
			if (k == n)
			{
				return v[n - 1];
			}
			else
			{
				return v[n - 1] / v[n - k - 1];
			}
		}
		else
		{
			auto it = s.end();
			it--;
			int last_index_of_zero = *it;
			if ((n - k) > last_index_of_zero)
			{
				return v[n - 1] / v[n - k - 1];
			}
			else
			{
				return 0;
			}
		}


	}
};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		ProductOfNumbers p;
		p.add(3);
		p.add(0);
		p.add(2);
		p.add(5);
		p.add(4);
		cout << p.getProduct(2);
	}
	return 0;
}
