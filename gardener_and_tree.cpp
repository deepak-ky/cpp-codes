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
		int n,k;
		cin >> n >> k;
		int w = k;
		vector<int> nbrs(n+1,0);
		vector<int> cutting_layer(n+1,0);
		map<int,list<int>> mp;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin >> a >> b;
			mp[a].push_back(b);
			mp[b].push_back(a);
			nbrs[a]++;
			nbrs[b]++;
		}

		queue<int> q;
		for(int i=1;i<=n;i++){
			if(nbrs[i] == 1){
				q.push(i);
				cutting_layer[i] = 1;
			}
		}

		while(!q.empty()){
			int w = q.front();
			q.pop();
			for(auto &x : mp[w]){
				if(nbrs[x] != 1){
					nbrs[x]--;
					if(nbrs[x] == 1){
						q.push(x);
						cutting_layer[x] = cutting_layer[w] + 1;
					}
				}
			}
		}

		int ans = 0;

		for(int i=1;i<=n;i++){
			if(cutting_layer[i] > k){
				ans++;
			}
		}


		cout << ans << endl;

	}
	return 0;
}
