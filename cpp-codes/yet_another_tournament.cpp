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

bool custom_sort(pair<int,int> &p1,pair<int,int> &p2){
	if (p1.first < p2.first){
		return true;
	} else if(p1.first == p2.first){
		if(p1.second < p2.second){
			return false;
		}else{
			return true;
		}
	}else{
		return false;
	}
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		int minutes[n];
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++){
			cin >> minutes[i];
			v.push_back({minutes[i],i});
		}

		sort(v.begin(),v.end(),custom_sort);
		map<int,bool> defeated;
		int wins = 0;
		for(int i=0;i<n;i++){
			//wer(v[i].first);
			//wer(v[i].second);
			if(m >= v[i].first){
				wins++;
				m -= v[i].first;
				defeated[v[i].second] = true;
			}else{
				break;
			}

			//wer(m);
		}

		//wer(wins);
	
		map<int,int> wins_count;
		for(int i=0;i<n;i++){
			int win_value = i+1;
			if(defeated[i]) win_value--;
			//wer(i);
			//wer(win_value);
			wins_count[win_value]++;
		}

		wins_count[wins]++;

		int pos = 0;
		for(int i=wins+1;i<=n;i++){
			pos += wins_count[i];
		}

		cout << pos + 1 << endl;
	}
	return 0;
}
