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
void rearrange_with_extra_space(int *A, int n)
{
	int changed[n];
	for (int i = 0; i < n; i++)
	{
		changed[i] = A[A[i]];
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = changed[i];
	}

}
void rearrange_without_space(int *A, int n)
{

	for (int i = 0; i < n; i++)
	{
		A[i] = A[i] + (A[A[i]] % n) * n;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = A[i] / n;
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
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	out(a, n);
	rearrange_without_space(a, n);
	out(a, n);
	return 0;
}
