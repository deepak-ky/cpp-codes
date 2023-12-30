#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int mat[2][2] = {{1, 1}, {1, 0}};
void multiply_power(int n1)
{
	int n[2][2] = {{1, 1}, {1, 0}};
	for (int j = 0; j < (n1 - 1); j++)
	{	//wer(j) << endl;
		int w = (mat[0][0] * n[0][0]) + (mat[0][1] * n[1][0]);
		int x = mat[0][0] * n[0][1] + mat[0][1] * n[1][1];
		int y = mat[1][0] * n[0][0] + mat[1][1] * n[1][0];
		int z = mat[1][0] * n[0][1] + mat[1][1] * n[1][1];

		mat[0][0] = w % mod;
		mat[0][1] = x % mod;
		mat[1][0] = y % mod;
		mat[1][1] = z % mod;

	}

}
int fibonacci_number(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	multiply_power(n - 1);

	return mat[0][0] % mod;
}
int/*32_t*/ main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << fibonacci_number(n);
	return 0;
}
