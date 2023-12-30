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

int total_sum;
int ans;
int t1;
int t2;


void find_min_diff(int idx, int *a, int n, int curr_sum, int num)
{

	if (num == 0)
	{
		int rest_sum = total_sum - curr_sum;
		int w = abs(curr_sum - rest_sum);

		if (w < ans)
		{

			ans = w;
			t1 = curr_sum;
			t2 = rest_sum;
		}


		return;
	}

	if (idx == n)
	{
		return;
	}


//If the number of elements remainging is less thatn the number of elements
//that I have left to take


	find_min_diff(idx + 1, a, n, curr_sum + a[idx], num - 1);
	find_min_diff(idx + 1, a, n, curr_sum, num);


	return;
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int a[] =  {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
		int n = sizeof(a) / sizeof(int);

		total_sum = 0;

		for (int i = 0; i < n; i++)
		{
			total_sum += a[i];
		}


		int num = n / 2;

		ans = INT_MAX;
		find_min_diff(0, a, n, 0, num);

		if (ans != INT_MAX)
		{
			wer(ans);
			wer(t1);
			wer(t2);
		}




	}
	return 0;
}
