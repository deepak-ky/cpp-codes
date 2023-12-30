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

int max_crossing_sum(int *a, int s, int mid, int e)
{
	//jahan tak jaa sakte hon wahan tak maximum sum leke dekho

	int left_from_mid = INT_MIN;
	int ans = 0;
	for (int i = mid; i >= s; i--)
	{
		ans = ans + a[i];
		if (ans > left_from_mid)
		{
			left_from_mid = ans;
		}
	}


	int right_from_mid = INT_MIN;
	int ans1 = 0;
	for (int i = mid + 1; i <= e; i++)
	{
		ans1 = ans1 + a[i];
		if (ans1 > right_from_mid)
		{
			right_from_mid = ans1;
		}
	}


	//VERY IMPORTANT STEP

	int op1 = left_from_mid;
	int op2 = right_from_mid;
	int op3 = left_from_mid + right_from_mid;


	int w =  max(op1 , max(op2, op3));


	return w;


}

int max_subarray_sum(int *a, int s, int e)
{
	if (s == e)
	{

		return a[s];
	}

	int m = s + ((e - s) / 2);

	int op1 = max_subarray_sum(a, s, m);
	int op2 = max_subarray_sum(a, m + 1, e);
	int op3 = max_crossing_sum(a, s, m, e);

	int ans =  max(op1 , max(op2, op3));
	return ans;
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



		cout << max_subarray_sum(a, 0, n - 1);
	}
	return 0;
}
