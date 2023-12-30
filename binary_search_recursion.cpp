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

int binary_search_recursion(int *a, int n, int k, int l, int h)
{
	if (l > h) return -1;
	int m = (l + h) / 2;
	if (a[m] == k) return m;
	if (a[m] < k) return binary_search_recursion(a, n, k, m + 1, h);
	else return binary_search_recursion(a, n, k, l, m - 1);
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {1, 2, 3, 4, 5};
		int n = 5;
		int k = 1;
		cout << binary_search_recursion(a, n, k, 0, n - 1);


	}
	return 0;
}
