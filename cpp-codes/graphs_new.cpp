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

class graph{
	int v;
	map<int,list<int>> mp;
public:
	graph(int v){
		this->v = v;
	}

	void add_edge(int a,int b){
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void bfs()
	{
		map<int,bool> visited;
		queue<int> q;
		q.push(0);
		visited[0] = true;
		while(!q.empty()){
			int w = q.front();
			q.pop();
			cout << w << " ";
			for(auto nbr : mp[w]){
				if(visited[nbr] == false){
					visited[nbr] = true;
					q.push(nbr);
				}
			}
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
		graph g(3);
		g.add_edge(0,1);
		g.add_edge(1,2);
		g.bfs();
	}
	return 0;
}
