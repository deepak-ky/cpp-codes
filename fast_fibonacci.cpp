#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl

int T[2][2];
int I[2][2];

void mult(int A[][2] , int B[][2])
{
	int res_matrix[2][2];
	memset(res_matrix , 0 , sizeof(res_matrix));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res_matrix[i][j] = ((res_matrix[i][j] % mod) + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			A[i][j] = res_matrix[i][j];
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
	test
	{
		memset( I , 0 , sizeof(I));
		for (int i = 0; i < 2; i++)
		{
			I[i][i] = 1;
		}
		memset( T , 0 , sizeof(T));
		T[0][0] = 1;
		T[0][1] = 1;
		T[1][0] = 1;


		int n;
		cin >> n;
		if ( n == 0) cout << 0 << endl;
		else
		{
			n--;
			while (n > 0)
			{
				if (n & 1)
				{
					mult(I, T);
				}
				n = n >> 1;
				mult(T, T);
			}

			int base[2][1] = { {1} , {0} };
			int ans = 0;
			for (int i = 0; i < 2; i++)
			{
				ans += (I[0][i] % mod * base[i][0] % mod) % mod;
			}
			cout << ans << endl;
		}
	}




	return 0;
}
