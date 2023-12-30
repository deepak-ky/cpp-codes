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
		int n,k;
		cin >> n >> k;
		int matrix[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> matrix[i][j];
			}
		}


		int cnt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int i1 = n-1-i;
				int j1 = n-1-j;
				if(matrix[i][j] != matrix[i1][j1]){
					cnt++;
				}
			}
		}
		wer(cnt);
		cnt /= 2;
		wer(cnt);
		if(k < cnt){
			no;
		}else if(k == cnt){
			yes;
		}else{
			k -= cnt;
			if(k&1){
				no;
			}else{
				yes;
			}
		}
	}
	return 0;
}
