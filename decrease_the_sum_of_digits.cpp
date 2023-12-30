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

int sum_of_digits(int n)
{
	string s1 = to_string(n);
	int n_sum = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		n_sum += s1[i] - '0';
	}
	return n_sum;
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
		int s;
		cin >> n >> s;
		int n1 = n;
		if (sum_of_digits(n) <= s)
		{
			cout << 0 << endl;
		}
		else
		{

			while (sum_of_digits(n) > s)
			{
				//find me the first non zero from right;
				string f = to_string(n);
				int len = f.length();
				int i;
				int num;
				for (i = len - 1; i >= 0; i--)
				{
					if (f[i] != '0')
					{
						num = f[i] - '0';
						break;
					}
				}

				num = 10 - num;

				num *= pow(10 , len - i - 1);

				n += num;

			}
			cout << n - n1 << endl;
		}
	}
	return 0;
}
