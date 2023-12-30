#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000000
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int t[12][12];
int I[12][12];
void mult(int A[][12] , int B[][12] , int r)
{
	int c = r;
	int result_mat[r][c];
	memset(result_mat , 0 , sizeof(result_mat));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < c; k++)
			{
				result_mat[i][j] = ((result_mat[i][j] % mod) + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
			}

		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			A[i][j] = result_mat[i][j];
		}
	}
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int c;
	cin >> c;
	while (c--)
	{
		memset(t, 0, sizeof(t));
		int k;
		cin >> k;
		int base_values[k];
		for (int i = 0; i < k ; i++)
		{
			cin >> base_values[i];
		}
		reverse(base_values , base_values + k);
		for (int i = 0; i < k; i++)
		{
			int w;
			cin >> w;
			t[0][i] = w;
		}
		for (int i = 1; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (j == (i - 1))
				{
					t[i][j] = 1;
				}
				else t[i][j] = 0;
			}
		}
		memset(I, 0, sizeof(I));
		for (int i = 0; i < k; i++)
		{
			I[i][i] = 1;
		}

		int n;
		cin >> n;
		if (n == 0)
		{
			cout << 0 << endl;
		}
		else if (n <= k)
		{
			cout << base_values[k - n] << endl;
		}
		else
		{

			int p = n - k;
			while (p > 0)
			{
				if (p & 1)
				{
					mult(I, t, k);
				}
				mult(t, t, k);
				p = p >> 1;
			}
			int ans = 0;
			for (int i = 0; i < k; i++)
			{
				ans = ((ans % mod) + ((I[0][i] % mod) * (base_values[i] % mod)) % mod) % mod;
			}
			cout << ans << endl;
		}
	}
	return 0;

}

