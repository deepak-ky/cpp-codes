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

void replace_pi(char *a, int n)
{
	// cout << a << endl;
	// cout << n << endl;

	//base case
	if (n == 0)
	{
		return;
	}
	//rec case

	if (a[0] == 'p' && a[1] == 'i')
	{
		a[0] = '3';
		a[1] = '.';
		for (int i = n - 1; i >= 2; i--)
		{
			a[i + 2] = a[i];
		}
		a[2] = '1';
		a[3] = '4';
		return replace_pi(a + 1, n + 1);
	}
	else
	{
		return replace_pi(a + 1, n - 1);
	}


}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		//char a[] = {'x', 'p', 'i', 'g', 'h', 'p', 'i', 'm', 'p', 'i'};
		char a[] = {'2' , ' ' , '*' , ' ' , 'p' , 'i'};
		int n = sizeof(a) / sizeof(char);
		replace_pi(a, n);
		cout << a;
	}
	return 0;
}
