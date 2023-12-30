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

int mat[52][52];
int I_mat[52][52];

void mult(int A[][52] , int B[][52] , int r)
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
void cal_power(int mat[][52], int r , int c , int n)
{
	memset(I_mat, 0, sizeof(I_mat));
	for (int i = 0; i < r ; i++)
	{
		I_mat[i][i] = 1;

	}

	//BRUTE FORCE APPROACH
	/*for (int i = 0; i < n; i++)
	{
		//I_mat = I_mat * mat
		mult(I_mat, mat, r);

	}*/

	//OPTIMISED APPROACH
	while (n > 0)
	{
		if (n & 1)
		{
			mult(I_mat, mat, r);

		}
		mult(mat, mat, r);
		n = n >> 1;

	}
	/*cout << "\nIdentity Matrix now : " << endl;*/
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout <<  I_mat[i][j] << " ";
		}
		cout << endl;
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
		memset(mat, -1, sizeof(mat));
		int r, n;
		cin >> r >> n;
		int c = r;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> mat[i][j];
			}
		}
		cal_power(mat, r, r, n);
	}
	return 0;
}
