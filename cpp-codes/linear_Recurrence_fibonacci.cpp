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
int T[2][2] = { {1, 1} ,
	{1, 0}
};
int I[2][2] = {  {1, 0} ,
	{0, 1}
};
void mult(int A[][2] , int B[][2] , int r)
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

	// Finding the nth term of the following sequence :
	// F(n) = F(n-1) + F(n-2)
	// In this case we know that F[0] = 0 , F[1] = 1



	int n;
	cin >> n;


	int p = n - 2;

	while (p > 0)
	{
		if (p & 1)
		{
			mult(I, T, 2);
		}
		mult(T, T, 2);
		p = p >> 1;
	}

	int base_values[2][1] = { {1} , {0}};
	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		ans += (I[0][i] * base_values[i][0]);
	}
	cout << " \nThese are occurences ,\nnot the nth number but the nth occurence \n\n";
	cout << "The " << n << "th occurence  is : " << ans << endl;



	return 0;

}