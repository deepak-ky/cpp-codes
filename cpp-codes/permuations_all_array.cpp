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

void printRecursively(vector<int> &a, int idxToFix) {
	//cout << "idxToFix : "<<idxToFix<<", array here : "; for(auto &x : a) cout << x << " "; cout << endl;
	if(idxToFix == a.size()-1){
		for(auto &x : a) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}


	for(int i = idxToFix;i<a.size();i++){
		swap(a[idxToFix],a[i]);
		printRecursively(a,idxToFix+1);
		swap(a[i],a[idxToFix]); // no need if passing vector by value
	}

}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<int> a = {1,2,3};
		printRecursively(a,0);

	}
	return 0;
}
