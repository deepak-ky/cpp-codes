#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int a = 3;
		cout << "a : " << a << endl;
		cout << "&a : " << &a << endl;

		int* b = &a;
		cout << "b : " << b << endl;
		cout << "&b : " << &b << endl;
		cout << "*b : " << *b << endl;

		cout << "---------------------" << endl;
		cout << "---------------------" << endl;

		int a1;
		cout << "a1 : " << a1 << endl;
		cout << "&a1 : " << &a1 << endl;

		int *b1 = &a1;
		cout << "b1 : " << b1 << endl;
		cout << "&b1 : "<< &b1 << endl;
		cout << "*b1 : "<< *b1 << endl;

		cout << "---------------------" << endl;
		cout << "---------------------" << endl;

		int a2 = 34;
		cout << "a2 : " << a2 << endl;
		cout << "&a2 : " << &a2 << endl;

		int* b2 = &a2;
		cout << "b2 : " << b2 << endl;
		cout << "&b2 : " << &b2 << endl;
		cout << "*b2 : " << *b2 << endl;

		int *c2 = &a2;
		cout << "c2 : " << c2 << endl;
		cout << "&c2 : " << &c2 << endl;
		cout << "*c2 : " << *c2 << endl;

		cout << "---------------------" << endl;

		*c2 = 23;
		cout << "a2 : " << a2 << endl;
		cout << "&a2 : " << &a2 << endl;
		cout << "b2 : " << b2 << endl;
		cout << "*b2 : " << *b2 << endl;
		cout << "c2 : " << c2 << endl;
		cout << "*c2 : " << *c2 << endl;



	}
	return 0;
}
