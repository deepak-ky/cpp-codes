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
	cin >> t;
	while (t--)
	{
		int w,d,h;
		cin >> w >> d >> h;
		int a,b,f,g;
		cin >> a >> b >> f >> g;
		int opt1 = b + h + abs(f-a) + g;
		int opt2 = a + h + abs(b-g) + f;
		int opt3 = (d-b) + h + abs(f-a) + (d-g);
		int opt4 = (w-a) + h + abs(b-g) + (w-f);
		int opt5 = min(opt1,opt2);
		int opt6 = min(opt3,opt4);
		cout << min(opt6,opt5) << endl;
	}
	return 0;
}
