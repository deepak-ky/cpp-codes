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
	cin >> t;
	while (t--)
	{


		vector<int> negatives;
		vector<int> positives;
		int n;
		cin >> n;
		int *a = new int[n];


		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > 0)
			{
				positives.push_back(a[i]);
			}
			else if (a[i] < 0)
			{
				negatives.push_back(a[i]);
			}

		}

		int maxi = *max_element(a, a + n); // For the zero case



		int ans = 1;


		int j = 0;
		while (j < positives.size())
		{
			ans = ans * positives[j];
			j++;
		}


		sort(negatives.begin(), negatives.end());



		bool flag = false;

		int i = -1;
		int size = negatives.size();
		int product_negative = 1;
		if (i + 2 < size)
		{
			flag = true;
			product_negative *= negatives[i + 1];
			product_negative *= negatives[i + 2];

			i = i + 2;
		}

		if (maxi == 0 && negatives.size() <= 1)
		{
			cout << 0 << endl;
		}
		else if (positives.size() == 0)
		{
			if (flag) cout << product_negative << endl;
			else cout << negatives[negatives.size() - 1] << endl;;
		}
		else
		{
			cout << ans * product_negative << endl;
		}


	}
	return 0;
}
