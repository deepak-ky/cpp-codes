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
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
// int *a, *p, q;
// 	a = NULL;
// 	delete a;
// 	p = new int;
// 	delete p;
// 	delete p;

// 	Test * t = new Test;
// 	cout << t->x;
// 	// int n = 4;
// 	// int *a;
// 	// a = new int(4);
// 	// // int w = 4;
// 	// // *a = 4;
// 	// wer(a);
	int n = 4;
	int * p;
	p = &n;
	cout << " &n : " << &n << endl;
	cout << " p : " << p << endl;
	cout << "*p : " << *p << endl;
	cout << " n : " << n << endl;

	//((*p)++);
	//p++;
	//*p++;
	//*p++ = p++ only
	cout << endl;
	cout << " &n : " << &n << endl;
	cout << " p : " << p << endl;
	cout << "*p : " << *p << endl;
	cout << " n : " << n << endl;

	int *a = new int[n];
	a[0] = 5;
	a[1] = 8;
	a[2] = 7;
	//a++;
	//(*a)++;
	//*a++;
	cout << *a << endl;
	cout << a[0] << endl;
	cout << a << endl;
	cout << &a[0] << endl;

	cout << endl;

	// int b[n];
	// int w = 0;
	// //b[] = 13;
	// // b[1] = 20;
	// // b[2] = 29;
	// // b[3] = 100;
	// cout << *b << endl;
	// cout << b[0] << endl;
	// cout << b << endl;
	// cout << &b[0] << endl;




	return 0;
}
