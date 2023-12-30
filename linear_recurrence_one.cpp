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
int T[3][3] = { {1, 1, 1} ,
	{1, 0, 0} ,
	{0, 1, 0}
};
int I[3][3] = {  {1, 0, 0} ,
	{0, 1, 0} ,
	{0, 0, 1}
};
void mult(int A[][3] , int B[][3] , int r)
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
	// F(n) = F(n-1) + F(n-2) + F(n-3)
	// In this case we know that F[0] = 0 , F[1] = 1 , F[2] = 1



	int n;
	cin >> n;

	// we need to design the transformation matrix
	// as the function is depenedent on the last three terms , therefore it will be a 3 * 3 matrix
	// and we know by observation that it would be of the form
	/*int T[3][3] = { {1, 1, 1} ,
	                  {1, 0, 0} ,
	                  {0, 1, 0}
	                            }; */
	// we need to raise it to the power of n - 2 , as in the function the f(n) term is dependent on the last 3 terms
	// but we first need to initialize the identity matrix which will store the result
	/* int I[3][3] = {  {1, 0, 0} ,
	                    {0, 1, 0} ,
	                    {0, 0, 1}
	                               };*/


	int p = n - 2;

	while (p > 0)
	{
		if (p & 1)
		{
			mult(I, T, 3);
		}
		mult(T, T, 3);
		p = p >> 1;
	}

	int base_values[3][1] = { {1} , {1} , {0}};
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		ans += (I[0][i] * base_values[i][0]);
	}
	cout << "The " << n << "th occurence is : " << ans << endl;



	return 0;

}