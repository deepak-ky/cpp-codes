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

int cnt = 0;

int* merge(int *a, int *b, int n1, int n2)
{
	if (n1 == 0)
	{
		return b;
	}
	if (n2 == 0)
	{
		return a;
	}
	int *c = new int[n1 + n2];
	int i = 0;
	int j = 0;
	int k = 0;
	int has_taken_count = false;
	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else
		{



			cnt += n1 - i;



			cout << a[i] << "," << b[j] << endl;

			c[k] = b[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		c[k] = b[j];
		j++;
		k++;

	}

	return c;


}

int* merge_sort(int a[], int l, int h)
{

	if (l >= h)
	{

		int *e = new int[1];
		e[0] = a[l];
		return e;
	}

	int m = (l + h) / 2;
	int *b = merge_sort(a, l, m);
	int *c = merge_sort(a, m + 1, h);

	int *d = merge(b, c, m - l + 1, h - m);

	return d;


}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		a = merge_sort(a, 0, n - 1);

		out(a, n);

		cout << endl << cnt << endl;

	}
	return 0;
}
