#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                    cout<<"\n"<<varname(x)<<" here : "<<x
int evenindex(int a[], int j, int n)
{


	int idx = 0;
	for (int i = j ; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{	idx = i;
			break;
		}
	}

	return idx;
}
int oddindex(int a[], int j, int n)
{
	int idx = 0;
	for (int i = j; i < n; ++i)
	{
		/* code */if (a[i] % 2 == 1)
			idx = i;
		break;
	}
	return idx;
}
int* evenodd(int a[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{


		if (k == 0)
		{
			if (a[i] % 2 == 1)
			{
				int j = evenindex(a, i + 1, n);
				int w = a[j];

				swap(a[i], a[j]);
			}
			k = 1;
		}
		else if (k == 1)
		{
			if (a[i] % 2 == 0)
			{
				int j = evenindex(a, i + 1, n);
				swap(a[i], a[j]);
			}
			k = 0;
		}
	}
	return a;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int *p = evenodd(a, n);
	for (int i = 0; i < n; i++)
	{

		/* code */cout  << p[i] << " ";
	}
	return 0;
}

