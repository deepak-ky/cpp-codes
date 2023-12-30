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
	while (1)
	{


		int n;
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		//first negative satisfies frist positive

		int final_ans = 0;

		int buyer_index = 0;
		int seller_index = 0;



		while (1)
		{
			while (a[buyer_index] < 0 && buyer_index < n)
			{
				buyer_index++;
			}


			while (a[seller_index] >= 0 && seller_index < n)
			{
				seller_index++;
			}


			if (seller_index == n && buyer_index == n)
			{
				break;
			}


			//so now I have the indexes of buyer index and seller index


			int abs_dist = abs(buyer_index - seller_index);

			if (a[buyer_index] > abs(a[seller_index]))
			{
				int w = abs(a[seller_index]) * abs_dist;
				final_ans += w;
				a[buyer_index] = a[buyer_index] - abs(a[seller_index]);
				a[seller_index] = -1;
				seller_index++;


			}
			else if (a[buyer_index] < abs(a[seller_index]))
			{
				int w = a[buyer_index] * abs_dist;
				final_ans += w;
				a[seller_index] = a[seller_index] + a[buyer_index];
				a[buyer_index] = 0;
				buyer_index++;

			}
			else
			{
				int w = a[buyer_index] * abs_dist;
				final_ans += w;
				a[seller_index] = -1;
				a[buyer_index] = 0;
				seller_index++;
				buyer_index++;
			}

		}


		cout << final_ans << endl;


	}
	return 0;
}
