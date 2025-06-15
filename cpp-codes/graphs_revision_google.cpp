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
	void addEdge(int a,int b){
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void printAllNeighbours(){
		for(int i=0;i<v;i++){
			cout << i << " : ";
			for(auto &x : mp[i]){
				cout << x << ",";
			}
			cout << endl;
		}
	}

	void bfs(int start){
		// Assuming one connected component, 
		// If more than one component, start queue-bfs from every unvisited vertex 
		vector<int> visited(v,false);
		queue<int> q;

		q.push(start);
		visited[start] = true;

		while(!q.empty()){
			int node = q.front();
			cout << node << " ";
			q.pop();
			for(auto &nbr : mp[node]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}


	void singleShortestPathUsingBFS(int start){
		vector<int> distance(v,INT_MAX);
		queue<int> q;
		q.push(start);
		distance[start] = 0;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto &nbr : mp[node]){
				if(distance[nbr] == INT_MAX){
					distance[nbr] = distance[node] + 1;
					q.push(nbr);
				}
			}
		}

		for(int i=0;i<v;i++){
			cout << start << "-->" << i << " : " << distance[i] << endl;
		}
	}

	void dfsHelper(int node, vector<bool> &visited){
		visited[node] = true;
		cout << node << " ";
		for(auto &nbr : mp[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;
	}

	void dfs(){
		vector<bool> visited(v,false);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				dfsHelper(i,visited);
			}
		}
	}

	bool detectCycleUsingBFS(){
		// Assuming one connected component

		vector<int> parent(v,-1);
		vector<bool> visited(v,false);

		visited[0] = true;
		parent[0] = 0;

		queue<int> q;
		q.push(0);

		while(!q.empty()){
			int f = q.front();
			q.pop();
			for(auto &nbr : mp[f]){
				if(visited[nbr]){
				 	if(parent[f] != nbr) return true;
				}else{
					parent[nbr] = f;
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		} 

		return false;
	}

	bool detectCycleUsingDFSHelper(int node, vector<int> &parent,vector<bool> &visited){
		for(auto &nbr : mp[node]){
			if(visited[nbr]){
				if(parent[node] != nbr){
					return true;
				}
			}else{
				parent[nbr] = node;
				visited[nbr] = true;
				if(detectCycleUsingDFSHelper(nbr,parent,visited)){
					return true;
				}
			}
		}

		return false;
	}

	bool detectCycleUsingDFS(){
		vector<int> parent(v,-1);
		vector<bool> visited(v,false);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				parent[i] = i;
				visited[i] = true;
				if(detectCycleUsingDFSHelper(i,parent,visited)){
					return true;
				}
			}
		}

		return false;
	}


};

class directedGraph{
	int v;
	map<int,list<int>> mp;
public:
	directedGraph(int v){
		this->v = v;
	}

	void addEdge(int a,int b){
		mp[a].push_back(b);
	}

	void printAllNeighbours(){
		for(int i=0;i<v;i++){
			cout << i << "->";
			for(auto &nbr : mp[i]){
				cout << nbr << ",";
			}
			cout << endl;
		}

	}

	void topologicalSortBFS(){
		// Assuming Acyclic graph
		vector<int> inDegree(v,0);
		for(auto &x : mp){
			for(auto &y : x.second){
				inDegree[y]++;
			}
		}

		queue<int> q;

		for(int i=0;i<v;i++){
			if(inDegree[i] == 0){
				q.push(i);
			}
		}

		vector<int> topoSort;

		while(!q.empty()){
			int f = q.front();
			q.pop();
			topoSort.push_back(f);
			for(auto &nbr : mp[f]){
				inDegree[nbr]--;
				if(inDegree[nbr] == 0){
					q.push(nbr);
				}
			}

		}

		cout << endl << "topoSort : " << endl;
		for(auto &x : topoSort) cout << x << " ";
	}
	
	void topologicalSortDFSHelper(int node, vector<bool> &visited, stack<int> &s){
		visited[node] = true;
		for(auto &nbr : mp[node]){
			if(!visited[nbr]){
				topologicalSortDFSHelper(nbr,visited,s);
			}
		}
		s.push(node);
		return;
	}

	void topologicalSortDFS(){
		/*	
			1->0, 
				you start traversing from 0, you go to 0, now nowhere to go, you push in stack 0,
				you start traversing from 1, you see 0 is already visited, do not taverse it, you push in stack 1
				now stack 1(top),0 | when printed you have 1,0
			0->1 
				you start traversing from 0, you go to 1, now no where to go, you push in stack 1,
				come back to 0, no where to go push in stack 0
				now stack 0(top),1 | when printed 0,1

			0->1->2->3->4->5

			if you start travesing from 5, 5 would be at the bottom of the stack
			if you start traversing from 0, then also 5 would be at the bottom of the stack

			basically agar aap kisi node pe depenedent ho, toh aap pahle hee jaaoge stack mein, chahiye ussi node se start karo(5)
			yahan peeche se start karoge(0), 5 toh pahle hee jaaega
		*/
		stack<int> s;
		vector<bool> visited(v,false);
		vector<int> topoSort;

		for(int i=0;i<v;i++){
			if(!visited[i]){
				topologicalSortDFSHelper(i,visited,s);
			}
		}

		while(!s.empty()){
			topoSort.push_back(s.top());
			s.pop();
		}

		cout << endl;
		cout << "topoSort using DFS : " << endl;
		for(auto &x : topoSort) cout << x << " ";
	}
	
	bool detectCycleInADirectedGraphHelper(int node, vector<bool> &visited, vector<bool> &inCurrentCycle){
		visited[node] = true;
		inCurrentCycle[node] = true;

		for(auto &nbr : mp[node]){
			if(visited[nbr]){
				if(inCurrentCycle[nbr]){
					return true;
				}
			}else{
				if(detectCycleInADirectedGraphHelper(nbr,visited,inCurrentCycle)){
					return true;
				}
			}
		}

		inCurrentCycle[node] = false;
		return false;
	}

	bool detectCycleInADirectedGraph(){
		vector<bool> visited(v,false);
		vector<bool> inCurrentCycle(v,false);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				if(detectCycleInADirectedGraphHelper(i,visited,inCurrentCycle)){
					return true;
				}
			}
		}

		return false;
	}
};


class WeightedGraph{
	int v;
	map<int,list<pair<int,int>>> mp;
public:
	WeightedGraph(int v){
		this->v = v;
	}

	int addEdge(int a,int b,int wt){
		mp[a].push_back({b,wt});
		mp[b].push_back({a,wt});
	}

	void dijkstras(int src){
		vector<int> distance(v,INT_MAX);
		distance[src] = 0;

		set<pair<int,int>> s;

		s.insert({0, src});

		while(!s.empty()){
			auto it = s.begin();
			s.erase(it);
			int node = it->second;
			int currentDist = it->first;

			for(auto &nbrInfo : mp[node]){
				int nbr = nbrInfo.first;
				int weightEdge = nbrInfo.second;

				if(currentDist + weightEdge < distance[nbr]){
					auto it = s.find({distance[nbr],nbr});
					if(it != s.end()){
						s.erase(it);
					}

					distance[nbr] = currentDist + weightEdge;
					s.insert({distance[nbr],nbr});
				}
			}
		}

		for(int i=0;i<v;i++){
			cout << src << "->" << i << " : " << distance[i] << endl;
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
		graph g(6);
		g.addEdge(0,1);
		g.addEdge(0,3);
		g.addEdge(1,2);
		g.addEdge(2,3);
		g.addEdge(3,4);
		g.addEdge(4,5);

		// g.printAllNeighbours();

		/*cout << endl;
		g.bfs(3);*/

		/*cout << endl;
		g.singleShortestPathUsingBFS(0);*/

		/*cout << endl;
		g.dfs();*/

		/*cout << endl;
		if(g.detectCycleUsingBFS()){
			cout << "cycle exists";
		}else{
			cout << "cycle does not exist";
		}*/

		/*cout << endl;
		if(g.detectCycleUsingDFS()){
			cout << "cycle exists";
		}else{
			cout << "cycle does not exist";
		}*/


		directedGraph dg(6);
		dg.addEdge(0,3);
		dg.addEdge(0,5);
		dg.addEdge(2,1);
		dg.addEdge(3,2);
		dg.addEdge(4,1);
		dg.addEdge(4,5);

		// For cycle detection
		// dg.addEdge(1,0);
		// dg.addEdge(5,2);
		// dg.addEdge(2,4);

		//dg.printAllNeighbours();

		// dg.topologicalSortBFS();

		// dg.topologicalSortDFS();

		/*if(dg.detectCycleInADirectedGraph()){
			cout << "cycle exists in the directed graph";
		}else{
			cout << "cycle does not exists in the directed graph";
		}*/


		WeightedGraph wg(5);
		wg.addEdge(0,2,1);
		wg.addEdge(0,3,4);
		wg.addEdge(0,4,7);
		wg.addEdge(2,3,1);
		wg.addEdge(3,4,2);

		wg.dijkstras(0);
	}
	return 0;
}
 