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



		int kw;
		cin >> kw;

		sort(a, a + n);

		int closest_diff = INT_MAX;
		int closest_sum  = -1;


		for (int k = 0; k < n - 2; k++)
		{
			int w = a[k];
			int diff = kw - w;

			int i = k + 1;
			int j = n - 1;

			while (i < j)
			{
				int sup = a[i] + a[j];
				if (abs(kw - (w + sup)) < closest_diff)
				{
					closest_diff = abs(kw - (w + sup));
					closest_sum = w + sup;
				}
				if (sup == diff)
				{
					break;
				}
				else if (sup > diff)
				{
					j--;
				}
				else i++;
			}

			wer(closest_sum);

		}


		cout << closest_sum << endl;

	}
	return 0;
}
