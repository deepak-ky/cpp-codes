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

class graph{
public:
	int v;
	int x;
	int y;
	map<int,list<int>> mp;

	graph(int v,int x,int y){
		this->v = v;
		this->x = x;
		this->y = y;
	}

	void add_edge(int a,int b){
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void dfs(int node,vector<bool> &visited,int &cnt){

		wer(node);
		wer(cnt);
		for(int i=0;i<v+1;i++) {
			cout << i << " " << visited[i] << endl;
		}
		cout << endl;

		
		visited[node] = true;
		cnt++;

		for(auto &nbr : mp[node]){
			if(nbr == y && visited[x] == true) continue;

			dfs(nbr,visited,cnt);
		}

	}

	int find_paths(){
		int cnt = 0;
		for(int i=1;i<=v;i++){
			vector<bool> visited(v+1,false);
			dfs(i,visited,cnt);
		}
		return cnt;
	}

};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int v,x,y;
		cin >> v >> x >> y;
		graph g(v,x,y);

		for(int i=0;i<v-1;i++){
			int u,v;
			cin >> u >> v;
			g.add_edge(u,v);
		}

		cout << g.find_paths();
	}
	return 0;
}
