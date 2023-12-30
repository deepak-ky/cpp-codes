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
		int n;
		cin >> n;
		map<int,int> mp;
		vector<vector<int>> v;
		for(int i=0;i<n;i++){
			vector<int> w;
			int y;
			cin >> y;
			for(int i=0;i<y;i++)
			{
				int z;
				cin >> z;
				w.push_back(z);
				mp[z]++;
			}
			v.push_back(w);
			
		}

		


		bool flag = true;

		
		for(int i=0;i<v.size();i++){
			vector<int> w = v[i];
			flag = true;
			for(int j=0;j<w.size();j++){
				if(mp[w[j]] <= 1){
										flag = false;
					break;

				}
			}
			if(flag) break;
		}

		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
