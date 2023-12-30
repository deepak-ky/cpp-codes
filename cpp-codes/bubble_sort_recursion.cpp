#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
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

void bubble_sort(int a[], int n)
{
	//base case
	if (n == 1)
	{
		return;
	}

	//recur case
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
		}
	}
	bubble_sort(a, n - 1);
}
void bubble_sort_recursion(int a[], int idx, int n)
{
	//base case
	if (n == 1)
	{
		return;
	}
	//rec case
	if (idx == n - 1)
	{
		bubble_sort_recursion(a, 0, n - 1);
		return;
	}
	if (a[idx] > a[idx + 1])
	{
		swap(a[idx], a[idx + 1]);
	}
	bubble_sort_recursion(a, idx + 1, n);
	return;

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {8, 5, 4, 2, 1};
		int n = sizeof(a) / sizeof(int);

		//SIMPLE BUBBLE SORT

		/*for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
				}
			}
		}*/

		//BUBBLE SORT ITERATIVE + RECURSIVE

		//bubble_sort(a, n);

		//BUBBLE SORT RECURSIVE

		bubble_sort_recursion(a, 0, n);



		out(a, n);
	}
	return 0;
}
