#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
#define out(a,n)                     cout<<"\nThe array here is : ";for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define inp(a,n)                     int a[n];for(int i=0;i<n;i++){cin>>a[i];}
#define test                         int t;cin>>t;while(t--)
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
	int i = 0;
	int j = 0;

	while (j < (n))
	{

		int index = max_element(a, a + (n - i)) - a;
		cout << index + 1 << " ";
		reverse(a, a + index + 1);

		cout << n - i << " ";
		reverse(a, a + (n - i));

		if (i < n)
		{
			i++;
		}
		else {i = i;}
		j++;

	}





	return 0;
}
