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
#define n                         cout << "NO"  << endl;
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
	cin >> t;
	while (t--)
	{
		int a[100];
		int no;
		int i;
		int tmpdata;
		int Minimum = INT_MAX;
		//cout << "Enter the size of the array : ";
		cin >> no;
		if (no <= 0)
		{
			cout << "Invalid size specified" << endl;
		}
		else
		{
			for (int i = 0; i < no; i++)
			{
				//cout << "Enter " << i + 1 << endl;
				cin >> tmpdata;
				a[i] = tmpdata;
			}

			i = 0;
			while (i <= no  - 1)
			{
				if (Minimum > a[i])
				{
					Minimum = a[i];
				}
				i++;
			}
			cout << Minimum << endl;
		}
	}
	return 0;
}
