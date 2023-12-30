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
		int n; cin >> n;
		int k; cin >> k;

		int h[n];
		for(int i=0;i<n;i++) cin >> h[i];

		int p[n];
		for(int i=0;i<n;i++) cin >> p[i];



		vector<pair<int,int>> v;

		for(int i=0;i<n;i++){
			v.pb({h[i],p[i]});
		}



		sort(v.begin(), v.end());

		int total_dec_value = k;
		int current_dec_value = k;

		vector<int> min_value_from_here(n,INT_MAX);
		min_value_from_here[n-1] = v[n-1].second;

		for(int i=n-2;i>=0;i--){
			min_value_from_here[i] = min(v[i].second,min_value_from_here[i+1]);
		}

		
		int i = 0;
		while(i<n){

			if(current_dec_value <= 0) break;

			if(total_dec_value >= v[i].first){
				i++;
			}else{
				current_dec_value -= min_value_from_here[i];
				total_dec_value += current_dec_value;
			}
		}

		if(i == n){ yes;}
		else {no;}
	}
	return 0;
}
