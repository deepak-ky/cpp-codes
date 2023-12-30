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
int * fun()
{
	int a[] = {1, 2, 3, 4, 5};
	cout << "a : " << a << endl;
	cout << "a[0] : " << a[0] << endl;
	return a;
}
int * fun1()
{
	int * a = new int[5];
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
	cout << "a : " << a << endl;
	cout << "a[0] : " << a[0] << endl;
	return a;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//int *b = fun();
	int *b = fun1();
	cout << "b : " << b << endl;
	cout << "b[0] : " << b[0] << endl;

	return 0;
}
