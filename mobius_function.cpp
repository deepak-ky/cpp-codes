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
#define s                            second

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

const int N = 100000;
int p[N] = {0};
int prime_count[N] = {0};
int mobius[N];
void cal_mobius()
{
	mobius[0] = 1;
	mobius[1] = 1;
	prime_count[0] = 0;
	prime_count[1] = 0;
	for (int i = 2; i < N; i++)
	{
		//declare all as prime
		p[i] = 1;
	}
	for ( int i = 2; i < N; i++)
	{
		if (prime_count[i] > 0)
		{
			//this will ensure that we only take into account prime numbers
			continue;
		}
		else
		{
			for (int j = i; j < N; j += i)
			{
				prime_count[j]++;
				p[j] *= i;
			}
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (p[i] == i)
		{
			//ensures without prime square in prime factorizatoin
			if (prime_count[i] & 1)
			{
				mobius[i] = -1;
			}
			else mobius[i] = 1;

		}
		else
		{
			mobius[i] = 0;
		}
	}

}

int32_t main()
{
	init();

	cal_mobius();
	for (int i = 1; i < 21; i++)
	{
		cout << "mobius(" << i << ") : " << mobius[i] << endl;
	}

	return 0;
}
