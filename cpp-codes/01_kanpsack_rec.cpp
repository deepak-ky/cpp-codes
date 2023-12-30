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

int maxi;

void max_profit(int *weight, int *price, int capacity, int idx, int n, int p)
{
	if (idx == n || capacity == 0)
	{
		maxi = max(maxi, p);
		return;
	}
	if (weight[idx] <= capacity)
	{
		max_profit(weight, price, capacity - weight[idx], idx + 1, n, p + price[idx]);
	}
	max_profit(weight, price, capacity, idx + 1, n, p);
	return;
}


int max_profit_2(int *weight, int *price, int idx, int n, int capacity)
{
	if (idx == n || capacity == 0)
	{
		return 0;
	}
	int op1 = 0;
	int op2 = 0;
	if (weight[idx] <= capacity)
		op1 = price[idx] + max_profit_2(weight, price, idx + 1, n, capacity - weight[idx]);
	op2 = max_profit_2(weight, price, idx + 1, n, capacity);
	return max(op1, op2);
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		maxi = -1;
		int weight[] = {1, 2, 3, 5};
		int price[]  = {40, 20 , 30, 100};
		int capacity = 7;
		int n = sizeof(weight) / sizeof(int);
		max_profit(weight, price, capacity, 0, n, 0);
		cout << maxi;
		cout << endl;
		cout << max_profit_2(weight, price, 0, n, capacity);
	}
	return 0;
}
