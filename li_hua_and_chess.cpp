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
		int n,m;
		cin >> n >> m;
		vector<int> distances;
		int distance1, distance2, distance3;
		cout << "? 1 1";
		cin >> distance1;
		cout << endl;
		cout.flush();
		int xx = 1 + distance1;
		cout << "? 1 "<<min(xx,m);
		cin >> distance2;
		cout << endl;
		cout.flush();
		cout << "? "<<min(xx,n)<<" 1";
		cin >> distance3;
		cout << endl;
		cout.flush();

		wer(distance1);
		wer(distance2);
		wer(distance3);
	}
	return 0;
}
