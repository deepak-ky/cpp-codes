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

struct DSU
{
	vector<int> par, sz;
	int total_comp;
	int sizee;
	DSU(int n) {
		total_comp = n;
		sizee = n;
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int findSuperParent(int x) {
		if(x == par[x]) {
			return x;
		}

		return par[x] = findSuperParent(par[x]);
	}

	void merge(int a, int b) {
		wer(a);
		wer(b);

		int s_a = findSuperParent(a);
		int s_b = findSuperParent(b);

		wer(s_a);
		wer(s_b);

		if(s_a == s_b) {
			return;
		} else {
			par[s_b] = s_a;
			sz[s_a] += sz[s_b];
			sz[s_b] = 0;
			total_comp--;
		}
	}

	void printStatus() {
		cout <<"total_comp : " << total_comp << endl;
		for(int i=0;i<sizee;i++) {
			cout << "i : " << i <<" : "<< findSuperParent(i) << endl;
		}

		cout << endl;

		for(int i=0;i<sizee;i++) {
			cout << "i : " << i << " : "<< sz[i] << endl;
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
		cout<<"Long time no see 😃" << endl;
		int n = 4;
		DSU dsu(n);
				dsu.printStatus();


		dsu.merge(0,1);
		dsu.merge(2,3);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		dsu.printStatus();


	}
	return 0;
}
