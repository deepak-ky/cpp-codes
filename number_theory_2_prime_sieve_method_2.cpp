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

const int N = 100000007;
int p[N] = {0};

void fill_array()
{
	//Here all are set to zero now -> NO NUMBER is PRIME
	//Consider making all the odd numbers as prime;
	for (int i = 3; i < N; i += 2)
	{
		p[i] = 1;
	}

	//start from the square of every prime number and make it non prime
	for (int i = 3; i < N; i += 2)
	{
		if (p[i] == 1)
		{	// if I is Prime
			for (int j = i * i ; j < N; j += i)
			{
				p[j] = 0;
			}
		}
	}
	p[0] = p[1] = 0;
	p[2] = 1;

}

void fill_array_type_2()
{
	//all the numbers are prime
	for (int i = 0; i < N; i++)
	{
		p[i] = 1;
	}
	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++)
	{
		if (p[i] == 1)
		{
			for (int j = i * i; j < N; j += i)
			{
				p[j] = 0;
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
	fill_array_type_2();
	for (int i = 0; i < 30; i++)
	{
		if (p[i] == 1)
		{
			cout << i << " ";
		}
	}
	return 0;
}
