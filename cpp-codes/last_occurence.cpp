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

int last_occ(int *a, int n, int key)
{
	if (n == 0)
	{
		return -1;
	}
	int i = last_occ(a + 1, n - 1, key);
	if (i != -1) // an occurence of key is also present in the smaller part of the array
	{
		return i + 1;
	}
	if (a[0] == key)
	{
		return 0;
	}
	else return -1;
}
int last_occ_2(int *a, int n, int key)
{
	if (n - 1 == -1)
	{
		return -1;
	}
	if (a[n - 1] == key)
	{
		return n - 1;
	}
	else return last_occ(a, n - 1, key);
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
		int key = 2;
		int n = sizeof(a) / sizeof(int);
		cout << last_occ(a, n, key);
		cout << endl <<  last_occ_2(a, n, key);
	}
	return 0;
}
