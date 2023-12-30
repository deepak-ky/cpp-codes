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

void fill_p(int *p, int n)
{
	for (int i = 3; i <= n; i += 2)
	{
		p[i] = 1;
	}
	for (int  i = 3; i <= n; i += 2)
	{
		if (p[i] == 1)
		{
			for (int j = (i * i); j <= n; j += i)
			{
				p[j] = 0;
			}
		}
	}
	p[0] = p[1] = 0;
	p[2] = 1;
}
void primesum(int A)
{

	int * p;
	p = new int[A + 1];
	for (int i = 0; i < (A + 1); i++) p[i] = 0;
	fill_p(p, A + 1);


	vector<int> v;
	vector<int> v1;

	for (int i = 0; i <= (A / 2); i++)
	{
		if (p[i] == 1 && p[A - i] == 1)
		{
			cout << i << " " << A - i;
			break;
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
	int n;
	cin >> n;


	primesum(n);


	return 0;
}
