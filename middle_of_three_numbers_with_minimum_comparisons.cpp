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

int middle_method_1(int a, int b, int c)
{
	if (a > b && a > c)
	{
		return max(b, c);
	}
	else
	{
		int w = max(b, c) ^ b ^ c;
		if (w > a)
		{
			return w;
		}
		else return a;

	}
}

int middle_method_2(int a, int b, int c)
{
	int x = a - b;
	//x -> positive => a > b;

	int y = b - c;
	//y ->positive => b > c;

	int z = c - a;
	//z -> positive => c > a;

	if (x * y > 0)
	{
		return b;
	}
	else if (y * z > 0)
	{
		return c;
	}
	else return a;

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cout << middle_method_1(a, b, c) << endl;
		cout << middle_method_2(a, b, c) << endl;

	}
	return 0;
}
