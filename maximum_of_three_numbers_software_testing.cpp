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

		cout << "Enter the range of the input";
		cout << endl;
		int l_limit , h_limit;
		cin >> l_limit >> h_limit;

		if (h_limit <= l_limit)
		{
			cout << "Please enter valid inputs!";
		}

		int mid = l_limit + ((h_limit - l_limit) / 2);

		int *a = new int[5];
		a[0] = l_limit;
		a[1] = l_limit + 1;
		a[2] = mid;
		a[3] = h_limit - 1;
		a[4] = h_limit;
		cout << "Testcase | " << "  x    | " << "  y  | " << "  z  | Output|";
		cout << endl << "-----------------------------------------";
		cout << endl;
		int testcase = 1;
		for (int i = 0; i < 5; i++)
		{
			if (a[i] < 10)
				cout << "     "  << testcase << "   |   " << a[i] << "    |  50  |  50  |  " << max(a[i], mid)  << "   | " << endl;
			else if (a[i] < 100)
				cout << "     "  << testcase << "   |   " << a[i] << "   |  50  |  50  |  " << max(a[i], mid) << "   | " << endl;
			else
				cout << "     "  << testcase << "   |   " << a[i] << "  |  50  |  50  |  " << max(a[i], mid) << "  | " << endl;
			testcase++;
		}
		for (int i = 0; i < 5; i++)
		{
			if (a[i] < 10)
				cout << "     "  << testcase << "   |   " << "50   |  " << a[i] << "   |  50  |  " << max(a[i], mid)  << "   | " << endl;
			else if (a[i] < 100)
				cout << "     "  << testcase << "   |   " << "50   |  " << a[i] << "  |  50  |  " << max(a[i], mid)  << "   | " << endl;
			else
				cout << "    "  << testcase << "   |   " << "50   |  " << a[i] << " |  50  |  " << max(a[i], mid)  << "  | " << endl;
			testcase++;
		}
		for (int i = 0; i < 5; i++)
		{
			if (a[i] < 10)
				cout << "    "  << testcase << "   |   " << "50   |  50  |  " << a[i] << "   |  " << max(a[i], mid)  << "   | " << endl;
			else if (a[i] < 100)
				cout << "    "  << testcase << "   |   " << "50   |  50  |  " << a[i] << "  |  " << max(a[i], mid)  << "   | " << endl;
			else
				cout << "    "  << testcase << "   |   " << "50   |  50  |  " << a[i] << " |  " << max(a[i], mid)  << "  | " << endl;
			testcase++;
		}



	}
	return 0;
}
