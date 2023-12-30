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

int power(int a, int b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	return a * power(a, b - 1);
}

fast_power(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return a;
	}/*
	if (b % 2 == 0)
	{
		return fast_power(a, b / 2) * fast_power(a, b / 2);
	}
	else return a * fast_power(a, b / 2) * fast_power(a, b / 2);*/

	//The above way is inefficient because we are using more memory in the call stack
	//by passing the same function (fast_power(a,b/2)) again and again.

	//Efficient approach

	int small_ans = fast_power(a, b / 2);
	if (b & 1)
	{
		return a * small_ans * small_ans;
	}
	else return small_ans * small_ans;


}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a = 2;
		int b = 10;
		cout << power(a, b) << endl;
		cout << fast_power(a, b);
	}
	return 0;
}
