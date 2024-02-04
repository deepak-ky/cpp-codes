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

class customCompare{
public:
	bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const {
		if(p1.first == p2.first){
			return p1.second < p2.second;
		}else{
			return p1.first > p2.first;
		}
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		set<pair<int,int>, customCompare> s;
		s.insert({-7,0});
		s.insert({-8,1});
		s.insert({7,2});
		s.insert({5,3});

		for(auto &x : s) cout << "(" << x.first << "," << x.second << "),"; cout << endl;

		s.erase({-7,0});

		for(auto &x : s) cout << "(" << x.first << "," << x.second << "),"; cout << endl;

		s.insert({7,4});

		for(auto &x : s) cout << "(" << x.first << "," << x.second << "),"; cout << endl;



	}
	return 0;
}
