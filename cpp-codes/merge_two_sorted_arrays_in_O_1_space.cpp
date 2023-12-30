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
		int n1;
		cin >> n1;
		int *a1 = new int[n1];
		for (int i = 0; i < n1; i++)
		{
			cin >> a1[i];
		}


		//Now I have two sorted arrays
		int j = n1 - 1;

		while (j >= 0)
		{
			if (a[n - 1] > a1[j])
			{
				swap(a1[j], a[n - 1]   );
			}
			int i = n - 1;
			while (a[i] < a[i - 1] && i > 0)
			{
				swap(a[i], a[i - 1]);
				i--;
			}
			j--;
		}

		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
		for (int i = 0; i < n1; i++) cout << a1[i] << " ";
	}
	return 0;
}
