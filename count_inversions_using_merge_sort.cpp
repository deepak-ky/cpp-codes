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

void merge(int *a, int l, int mid, int h, int &CNT)
{
	int *b = new int[h - l + 1];
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= h)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else if (a[i] > a[j])
		{

			//Most important step

			//---------------


			CNT += (mid - i + 1);

			//---------------

			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while (j <= h)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for (int d = 0; d < k; d++)
	{
		a[d + l] = b[d];
	}
	return;
}

int  merge_sort(int *a, int l, int h)
{
	if (l == h)
	{
		return 0;
	}
	int mid =  l + ((h - l) / 2);
	int c1 = merge_sort(a, l, mid);
	int c2 = merge_sort(a, mid + 1, h);
	int CNT = 0;
	merge(a, l, mid, h, CNT);
	return c1 + c2 + CNT;
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


		int ans = merge_sort(a, 0, n - 1);

		cout << "Number of Inversions are : " << ans << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}

	}
	return 0;
}
