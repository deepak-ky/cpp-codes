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

int T_n[3][3];
int I_n[3][3];

int T_m[3][3];
int I_m[3][3];

void mult(int A[][3] , int B[][3])
{
	int res_matrix[3][3];
	memset(res_matrix , 0 , sizeof(res_matrix));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				res_matrix[i][j] = ((res_matrix[i][j] % mod) + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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
		memset( I_n , 0 , sizeof(I_n));
		for (int i = 0; i < 3; i++)
		{
			I_n[i][i] = 1;
		}
		memset( T_n , 0 , sizeof(T_n));
		T_n[0][0] = 1;
		T_n[0][1] = 1;
		T_n[0][2] = 1;
		T_n[1][1] = 1;
		T_n[1][2] = 1;
		T_n[2][1] = 1;


		memset( I_m , 0 , sizeof(I_m));
		for (int i = 0; i < 3; i++)
		{
			I_m[i][i] = 1;
		}
		memset( T_m , 0 , sizeof(T_m));
		T_m[0][0] = 1;
		T_m[0][1] = 1;
		T_m[0][2] = 1;
		T_m[1][1] = 1;
		T_m[1][2] = 1;
		T_m[2][1] = 1;




		int n;
		cin >> n;

		int S_n = 0;
		if (n <= 1)
		{
			S_n = 0;
		}
		else
		{
			if (n != 0)
			{
				n -= 2;
				while (n > 0)
				{
					if (n & 1)
					{
						mult(I_n, T_n);
					}
					n = n >> 1;
					mult(T_n, T_n);

				}

				int base[3][1] = { {1} , {1} , {0} };

				for (int i = 0; i < 3; i++)
				{
					S_n = (S_n % mod +  (I_n[0][i] % mod * base[i][0] % mod) % mod) % mod;
				}
			}
		}
		//cout << S_n << endl;

		int m;
		cin >> m;
		int S_m = 0;
		if (m != 0)
		{
			m--;
			while (m > 0)
			{
				if (m & 1)
				{
					mult(I_m, T_m);
				}
				m = m >> 1;
				mult(T_m, T_m);

			}
			int base[3][1] = { {1} , {1} , {0} };


			for (int i = 0; i < 3; i++)
			{
				S_m = (S_m % mod + (I_m[0][i] % mod * base[i][0] % mod) % mod) % mod;
			}
		}
		cout << ( (S_m % mod - S_n % mod) + mod ) % mod << endl;
	}





	return 0;
}
