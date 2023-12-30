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

int modularExponentiation1(int a,int b,int m){
	if (a == 0) {
		return 0;
	}
	if (b == 0) {
		return 1;
	}


	if (b % 2 == 0){
		int w = modularExponentiation1(a,b/2,m);
		return ((w%m)*(w%m))%m;
	}else{
		int w = modularExponentiation1(a,b-1,m);
		return ((a%m)*(w%m))%m;
	}

	return 0;
}


int modularExponentiation2(int a,int b,int m){
	a = a % m;

	int res = 1;

	while(b > 0){
		if(b & 1){
			res = ((res%m) * (a%m))%m;
		}

		b = b >> 1;

		a = ((a%m)*(a%m))%m;
	}

	return res;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int a = 2;
		int b = 7;
		cout << modularExponentiation1(a,b,5) << endl;
		cout << modularExponentiation2(a,b,5);
	}
	return 0;
}
