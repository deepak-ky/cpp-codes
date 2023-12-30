#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int into_eight(int a)
{
	int x = a * 8;
	return x;
}
int into_four(int a)
{
	int x = a * 8;
	return x;
}
int into_two(int a)
{
	int x = a * 2;
	return x;
}
int find_min_steps_to(int a, int b)
{
	int cnt = 0;
	int i;
	for (i = a; i <= b; i = (i * 8))
	{
		a = a * 8;
		cnt++;
	}
	wer(cnt);
	int cnt1  = 0;
	int j;
	for (j = a; j <= b; j = (j * 4))
	{
		a = a * 4;
		cnt1++;
	}
	wer(cnt1);
	int cnt2 = 0;
	int k;
	for (k = a; k <= b; k = (k * 2))
	{
		a = a * 2;
		cnt2++;
	}
	wer(cnt2);
	return 100;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin>>t; while(t--)
	int a, b;
	cin >> a >> b;
	if (a == b) cout << 0 << endl;

	//multiply case

	else if (a < b)
	{


		cout << find_min_steps_to(a, b);
	}
	/*	else
		{
			divide_to_get_steps(a, b);
		}*/
	return 0;
}
