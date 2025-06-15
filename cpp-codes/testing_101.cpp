#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
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

int main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<int> v = {1,2};
		int sz = v.size();
		for(int i=-5;i<v.size();i++){
			cout << i*10 << endl;
		}
		cout << endl;
	}
	return 0;
}


// int i 	-> signed value 	(can represent both +ve and -ve)
// v.size() -> unsigned value   (can represnet only non-negative values 0 to +ve)

// C++ cannot compare signed and unsinged value, It does implicit conversion (converts signed to unsigned)
// Now the conversion leads to unexpected results, if the signed integer is negative
// Conversion of signed -1 to unsigned 2^64 -1 
// When a negative signed integer like -1 is promoted to an unsigned integer, it becomes the largest possible unsigned integer that the system can represent (usually 2^64 - 1)
