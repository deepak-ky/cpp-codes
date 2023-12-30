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

// int	solve(int idx,vector<int> &a,map<vector<int>,int> &dp,int n)
// {
// 	if(idx == n-1)
// 	{
// 		return a[idx];
// 	}

// 	if(dp.find(a) != dp.end()){
// 		return dp[a];
// 	}

// 	//two options 
// 	a[idx] = -a[idx];
// 	a[idx+1] = -a[idx+1];
// 	int w = a[idx] + solve(idx+1,a,dp,n);
// 	a[idx] = -a[idx];
// 	a[idx+1] = -a[idx+1];
// 	int w1 = a[idx] + solve(idx+1,a,dp,n);
// 	return dp[a] = max(w,w1);
// }
int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a;
		int nega = 0;
		int sum = 0;
		for(int i=0;i<n;i++){
			int w; cin >> w;
			if(w < 0) nega++;
			a.push_back(abs(w));
		}

		sort(a.begin(), a.end());

		for(int i=1;i<n;i++){
			sum += a[i];
		}

		if(nega&1){
			cout << sum - a[0] << endl;
		}else{
			cout << sum + a[0] << endl;
		}
		


	}
	return 0;
}
