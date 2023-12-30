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

class AdjacencyListGraph{
	int v;
	list<int> *l;
public:
	AdjacencyListGraph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void add_edge(int a,int b){
		l[a].push_back(b);
		l[b].push_back(a);
	}

	void display_graph(){
		for(int i=0;i<v;i++){
			cout << i << ":";
			for(auto j : l[i]){
				cout << j << ",";
			}
			cout << endl;
		}
	}
};

class UndirectedGraph{
	int v;
	map<int,list<int>> mp;
	public:
		UndirectedGraph(int v){
			this->v = v;
		}

		void add_edge(int a,int b){
			mp[a].push_back(b);
			mp[b].push_back(a);
		}

		void bfs(int src){
			queue<int> q;
			vector<bool> visited(v,false);
			visited[src] = true;
			q.push(src);
			while(!q.empty()){
				int w = q.front();
				q.pop();
				cout << w << " ";
				for(auto &x : mp[w]){
					if(visited[x] == false){
						q.push(x);
						visited[x] = true;
					}
				}
			}

		}

		void singleShortestPath(int src){
			queue<int> q;
			vector<bool> visited(v,false);
			map<int,int> distance;
			distance[src] = 0;
			q.push(src);
			visited[src] = true;
			while(!q.empty()){
				int w = q.front();
				q.pop();
				for(auto &nbr : mp[w]){
					if(visited[nbr] == false){
						visited[nbr] = true;
						distance[nbr] = distance[w] + 1;
						q.push(nbr);
					}
				}
			}

			for(auto &x : distance){
				cout << src << "->" << x.first << " : " << x.second << endl;
			}
		}

		void dfs_helper(int src,vector<bool> &visited){
			visited[src] = true;
			cout << src << " -> "; 
			for(auto &nbr : mp[src]){
				if(visited[nbr] == false){
					dfs_helper(nbr,visited);
				}
			}

			return;
		}

		void dfs(int src){
			vector<bool> visited(v,false);
			dfs_helper(src,visited);
		}

		bool detectCycleUsingBFS(){
			// ASSUMES THE GRAPH TO BE ONE CONNNECTED COMPONENT
			vector<int> parent(v,-1);
			vector<bool> visited(v,false);

			queue<int> q;

			q.push(0);
			visited[0] = true;
			parent[0] = 0;

			bool cycleExists = false;

			while(!q.empty()){
				int w = q.front();
				q.pop();

				for(auto &nbr : mp[w]){
					if(visited[nbr] == false){
						visited[nbr] = true;
						parent[nbr] = w;
						q.push(nbr);
					}else{
						if(parent[w] == nbr){
							continue;
						}else{
							cycleExists = true;
							break;
						}
					}
				}

				if(cycleExists) break;
			}

			return cycleExists;
		}

		bool detectCycleUsingDFSHelper(int node,vector<int> &parent,vector<bool> &visited){
			visited[node] = true;
			for(auto &nbr : mp[node]){
				if(!visited[nbr]){
					parent[nbr] = node;
					bool cycleExists = detectCycleUsingDFSHelper(nbr,parent,visited);
					if(cycleExists) return true;
				}else{
					if(parent[node] == nbr){
						continue;
					}else{
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
				if(visited[i] == false){
					bool cycleExists = detectCycleUsingDFSHelper(i,parent,visited);
					if(cycleExists) return true;
				}
			}

			return false;

		}

		bool isBiPartiteHelper(int node,vector<int> &color){
			for(auto &nbr : mp[node]){
				if(color[nbr] == color[node]){
					return false;
				}else if(color[nbr] == -1){
					color[nbr] = 1 - color[node];
					bool flag = isBiPartiteHelper(nbr,color);
					if(!flag) return false;
				}
			}

			return true;
		}

		bool isBiPartite(){
			vector<int> color(v,-1);
			for(int i=0;i<v;i++){
				if(color[i] == -1){
					color[i] = 0;
					bool flag = isBiPartiteHelper(i,color);
					if(!flag) return false;
				}
			}
			return true;
		}

		int fint_next_vertex(int node,vector<bool> &visited){

		}
};

class DirectedGraph{
	int v;
	map<int,list<int>> mp;
	vector<int> indegree;
public:
	DirectedGraph(int v){
		this->v = v;
		indegree = vector<int>(v,0);
	}

	void add_edge(int a,int b){
		mp[a].push_back(b);
		indegree[b]++;
	}

	void topologicalSortUsingBFS(){
		queue<int> q;
		vector<int> indegreeBFS = indegree;
		for(int i=0;i<v;i++){
			if(indegreeBFS[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int w = q.front();
			q.pop();
			cout << w << "->";
			for(auto &nbr : mp[w]){
				indegreeBFS[nbr]--;
				if(indegreeBFS[nbr] == 0){
					q.push(nbr);
				}
			}
		}
	}

	void topologicalSortUsingDFSHelper(int node,vector<bool> &visited,stack<int> &s){
		for(auto&nbr : mp[node]){
			if(!visited[nbr]){
				visited[nbr] = true;
				topologicalSortUsingDFSHelper(nbr,visited,s);
			}
		}
		s.push(node);
	}

	void topologicalSortUsingDFS(){
		stack<int> s;
		vector<bool> visited(v,false);
		// Assuming Acyclic Graph
		for(int i=0;i<v;i++){
			if(!visited[i]){
				visited[i] = true;
				topologicalSortUsingDFSHelper(i,visited,s);
			}
		}

		while(!s.empty()){
			cout << s.top() << "->";
			s.pop();

		}
	}

	bool detectCycleUsingDFSHelper(int node,vector<bool> &inCurrentPath, vector<bool> &visited){
		inCurrentPath[node] = true;
		for(auto &nbr : mp[node]){
			if(visited[nbr] == false){
				visited[nbr] = true;
				bool cycleExists = detectCycleUsingDFSHelper(nbr,inCurrentPath,visited);
				if(cycleExists) return true;
			}else if(visited[nbr] && inCurrentPath[nbr]){
				return true;
			}
		}
		inCurrentPath[node] = false;
		return false;
	}
	
	bool detectCycleUsingDFS(){
		vector<bool> inCurrentPath(v,false);
		vector<bool> visited(v,false);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				visited[i] = true;
				bool cycleExists = detectCycleUsingDFSHelper(i,inCurrentPath,visited);
				if(cycleExists) return true;
			}
		}
		
		return false;
	}

	void findStronglyConnectedComponetsHelper(int node,vector<bool> &visited,stack<int> &s){
		for(auto &nbr : mp[node]){
			if(!visited[nbr]){
				visited[nbr] = true;
				findStronglyConnectedComponetsHelper(nbr,visited,s);
			}
		}
		s.push(node);
		return;
	}

	void printStronglyConnectedComponentUsingDFS(int node,vector<bool> &visited,map<int,list<int>> &reverseEdgesMap){
		cout << node << " ";
		for(auto &nbr : reverseEdgesMap[node]){
			if(!visited[nbr]){
				visited[nbr] = true;
				printStronglyConnectedComponentUsingDFS(nbr,visited,reverseEdgesMap);
			}
		}
	}

	int findStronglyConnectedComponets(){
		// Topological Sort only exists for Acyclic Graph
		// But we would here be using the same concept that we use in Topological Sort
		// Push into stack when you cannot visit any other neighbour from that position
		// ie. all other neighbours are visited

		vector<bool> visited(v,false);
		stack<int> s;

		for(int i=0;i<v;i++){
			if(!visited[i]){
				visited[i] = true;
				findStronglyConnectedComponetsHelper(i,visited,s);
			}
		}

		cout << "Dummy Topological Sort" << endl;
		stack<int> s1 = s;
		while(!s1.empty()){
			cout << s1.top()  <<"->";
			s1.pop();
		} 
		cout << endl;

		map<int,list<int>> reverseEdgesMap;
		for(auto &x : mp){
			for(auto &y : x.second){
				reverseEdgesMap[y].push_back(x.first);
			}
		}

		int numberOfConnectedComponents = 0;

		visited = vector<bool>(v,false);
		cout << "The SCC's are(in no particular order)" << endl;
		while(!s.empty()){
			int i = s.top();
			s.pop();
			if(!visited[i]){
				numberOfConnectedComponents++;
				visited[i] = true;
				printStronglyConnectedComponentUsingDFS(i,visited,reverseEdgesMap);
				cout << endl;
			}
		}

		return numberOfConnectedComponents;


	}
	
};

class DirectedWeightedGraph{
	int v;
	map<int,list<pair<int,int>>> mp;

public:
	DirectedWeightedGraph(int v){
		this->v = v;
	}

	void add_edge(int a,int b,int w){
		mp[a].push_back({b,w});
	}

	void dijkstrasAlgo(int src){
		vector<int> distance(v,INT_MAX);
		distance[src] = 0;
		set<pair<int,int>> s;
		s.insert({distance[src],src});

		while(!s.empty()){

			auto f = s.begin();
			s.erase(s.begin());
			int node = (*f).second;
			int current_dist = (*f).first;

			for(auto &nbr : mp[node]){
				if(distance[nbr.first] > (current_dist + nbr.second)){
					auto f = s.find({distance[nbr.first],nbr.first});
					if(f != s.end()){
						s.erase(f);
					}

					distance[nbr.first] = current_dist + nbr.second;
					s.insert({distance[nbr.first],nbr.first});
				}
			}
		}

		cout << "The distances are : " << endl;
		for(int i=0;i<v;i++){
			cout << src << "->" << i <<" : " <<  distance[i] << endl;
		}
	}

	// Bellman Ford 
	bool negativeWeightCycle(){
		 
		vector<int> distance(v,INT_MAX);
		distance[0] = 0;

		// This can be done using edges array also
		// as I have not maintained a edges array here in this class
		// this approach is being used
		for(int i=0;i<v-1;i++){
			for(auto &x : mp){
				int a = x.first;
				for(auto &y : x.second){
					int b = y.first;
					int wt = y.second;

					if(distance[a] == INT_MAX){
						continue;
					}else{
						if(distance[a] + wt < distance[b]){
							distance[b] = distance[a] + wt;
						}
					}

				}
			}
		}


		// Doing it one more time

		for(auto &x : mp){
				int a = x.first;
				for(auto &y : x.second){
					int b = y.first;
					int wt = y.second;
					if(distance[a] + wt < distance[b]){
							return true;
				}

			}
		}

		return false;
	}

	// Floyd Warshall
	void multiSourceShortestPath(){
		vector<vector<int>> distance(v,vector<int>(v,INT_MAX));

		for(int i=0;i<v;i++){
			distance[i][i] = 0;
		}

		for(auto &x : mp){
			int a = x.first;
			for(auto &y : x.second){
				int b = y.first;
				int wt = y.second;
				distance[a][b] = wt;
			}
		}

		for(int via=0;via<v;via++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if( distance[i][via] != INT_MAX && 
						distance[via][j] != INT_MAX &&
						distance[i][via] + distance[via][j] < distance[i][j]){
						distance[i][j] = distance[i][via] + distance[via][j];
					}
				}
			}
		}

		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout << distance[i][j] << " ";
			}
			cout << endl;
		}
	}
};

struct DSU{
	int n;
	vector<int> size;
	vector<int> parent;
	int numberOfConnectedComponents;
	DSU(int n){
		this->n = n;
		numberOfConnectedComponents = n;
		size = vector<int>(n,1);
		parent = vector<int>(n);
		for(int i=0;i<n;i++){
			parent[i] = i;
		}
	}

	int find_superparent(int x){
		if(x == parent[x]){
			return x;
		}

		return parent[x] = find_superparent(parent[x]);
	}

	void merge(int a,int b){
		int spa = find_superparent(a);
		int spb = find_superparent(b);

		if(spa == spb){
			cout << "Cannot Merge, in Same Component";
			return;
		}else{
			if(size[spa] >= size[spb]){

				parent[spb] =  spa;
				size[spa] += size[spb];
				size[spb] = 0;
			}else{
				parent[spa] =  spb;
				size[spb] += size[spa];
				size[spa] = 0;
			}
			numberOfConnectedComponents--;
		}

		cout << "Components Connected Successfully";
	}
};

class UndirectedWeightedGraph{
	int v;
	map<int,list<pair<int,int>>> mp;
public:
	UndirectedWeightedGraph(int v){
		this->v = v;
	}
	void add_edge(int a, int b, int w){
		mp[a].push_back({b,w});
		mp[b].push_back({a,w});
	}

	int find_next_min_vertex(vector<bool> &visited, vector<int> &distance){
		int min_vertex = -1;
		for(int i=0;i<v;i++){
			if((!visited[i]) && (min_vertex == -1 || distance[i] < distance[min_vertex])){
				min_vertex = i;
			}
		}

		return min_vertex;
	}

	void prims_algo(){
		vector<bool> visited(v,false);
		vector<int> distance(v,INT_MAX);
		vector<int> parent(v,-1);

		for(int i=0;i<v;i++){
			distance[i] = INT_MAX;
		}

		distance[0] = 0;
		parent[0] = 0;

		for(int i=0;i<v;i++){
			int w = find_next_min_vertex(visited,distance);

			visited[w] = true;

			for(auto &nbr : mp[w]){
				int node = nbr.first;
				int edge_weight = nbr.second;

				if(!visited[node]){
					if(distance[node] > edge_weight)
					{
						distance[node] = edge_weight;
						parent[node] = w;
					}
				}
			}
		}

		int min_weight = 0;
		for(int i=0;i<v;i++){
			cout << i <<"->" << parent[i] << endl;
			min_weight += distance[i];
		}

		cout << "min_weight" << min_weight << endl;

	}

	void prims_algo_using_priority_queue(){
		//basically we need pq, to find out min_vertex faster
		// the vertex with the current minimum weight, and which has not been visited
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		vector<int> distance(v,INT_MAX);
		vector<int> parent(v,-1);
		vector<bool> visited(v,false);

		distance[0] = 0;
		parent[0] = 0;

		pq.push({distance[0],0});

		while(!pq.empty()){
			auto p = pq.top();
			pq.pop();

			int current_dist = p.first;
			int w = p.second;

			wer(w);
			wer(current_dist);

			if(visited[w]) continue;
 
			visited[w] = true;

			cout << endl << "here" << endl;

			for(auto &nbr : mp[w]){
				int node = nbr.first;
				int edge_weight = nbr.second;
				wer(node);
				wer(edge_weight);
				if(!visited[node]){
					if(distance[node] > edge_weight){
						wer(distance[node]);
						wer(parent[node]);
						distance[node] = edge_weight;
						parent[node] = w;
						wer(distance[node]);
						wer(parent[node]);
						pq.push({distance[node],node});
					}
				}
			}

		}

		int min_weight = 0;
		for(int i=0;i<v;i++){
			cout << i << "->" << parent[i] << endl;
			min_weight += distance[i];
		}

		wer(min_weight);
	}
};

bool custom_compare(vector<int> &v1,vector<int> &v2){
	if(v1[2] < v2[2]){
		return true;
	}else return false;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{

		// UndirectedGraph ug(5);
		// ug.add_edge(0,1);
		// ug.add_edge(0,3);
		// ug.add_edge(2,3);
		// ug.add_edge(1,2);
		// ug.add_edge(3,4);
		// ug.add_edge(4,5);

		// ug.bfs(0);
		// ug.singleShortestPath(5);
		// ug.dfs(0);

		// bool cycleExists = ug.detectCycleUsingBFS();
		// if(cycleExists) {yes;}
		// else no;

		// bool cycleExists = ug.detectCycleUsingDFS();
		// if(cycleExists) {yes;}
		// else no;

		// UndirectedGraph graphBiPartite(3);
		// graphBiPartite.add_edge(0,1);
		// graphBiPartite.add_edge(1,2);
		// graphBiPartite.add_edge(2,0);
		// bool isBiPartite = graphBiPartite.isBiPartite();
		// if(isBiPartite) {yes;}
		// else no;


		// DirectedGraph dg(6);
		// dg.add_edge(0,5);
		// dg.add_edge(0,3);
		// dg.add_edge(3,2);
		// dg.add_edge(2,1);
		// dg.add_edge(4,5);
		// dg.add_edge(4,1);

		//dg.topologicalSortUsingBFS();
		//dg.topologicalSortUsingDFS();

		// DirectedGraph dg1(4);
		// dg1.add_edge(0,1);
		// //dg1.add_edge(1,0);
		// dg1.add_edge(0,2);
		// dg1.add_edge(2,3);
		// dg1.add_edge(3,1);

		
		// bool cycleExists = dg1.detectCycleUsingDFS();
		// if(cycleExists) {yes;}
		// else no;

		// DirectedGraph scg(7);
		// scg.add_edge(1,0);
		// scg.add_edge(0,2);
		// scg.add_edge(2,1);
		// scg.add_edge(0,3);
		// scg.add_edge(3,4);
		// scg.add_edge(3,5);
		// scg.add_edge(5,6);
		// scg.add_edge(6,3);

		// int nCC = scg.findStronglyConnectedComponets();
		// cout << "Number of Connected Components are : " << nCC << endl;


		// DirectedWeightedGraph dg(6);
		// dg.add_edge(0,2,4);
		// dg.add_edge(0,1,4);
		// dg.add_edge(2,1,2);
		// dg.add_edge(2,3,3);
		// dg.add_edge(3,4,2);
		// dg.add_edge(2,4,6);
		// dg.add_edge(2,5,1);
		// dg.add_edge(5,4,3);

		// dg.dijkstrasAlgo(0);

		// DirectedWeightedGraph dg1(3);
		// dg1.add_edge(0,1,4);
		// dg1.add_edge(1,2,-4);
		// dg1.add_edge(2,0,1);
		// if(dg1.negativeWeightCycle()){
		// 	cout << "Negative Weight Cycle Exists";
		// }else{
		// 	cout << "negativeWeightCycle does not exist";
		// }

		// DirectedWeightedGraph dg2(3);
		// dg2.add_edge(0,1,1);
		// dg2.add_edge(0,2,43);
		// dg2.add_edge(1,0,1);
		// dg2.add_edge(1,2,6);

		// dg2.multiSourceShortestPath();



		// DSU dsu(4);
		// cout << "\n numberOfConnectedComponents : " << dsu.numberOfConnectedComponents << endl << endl;
		// dsu.merge(0,1);
		// cout << "\n numberOfConnectedComponents : "<< dsu.numberOfConnectedComponents << endl;
		// dsu.merge(1,2);
		// cout << "\n numberOfConnectedComponents : " << dsu.numberOfConnectedComponents << endl;
		// dsu.merge(0,2);
		// cout << "\n numberOfConnectedComponents : " << dsu.numberOfConnectedComponents << endl;


		// Minimum spanning tree using kruskal
		// vector<vector<int>> edges = {
		// 	{0,1,4},
		// 	{0,7,8},
		// 	{1,7,11},
		// 	{1,2,8},
		// 	{2,8,2},
		// 	{7,8,7},
		// 	{8,6,6},
		// 	{7,6,1},
		// 	{2,3,7},
		// 	{2,5,4},
		// 	{6,5,2},
		// 	{3,5,14},
		// 	{3,4,9},
		// 	{5,4,10}
		// };

		// Kruskal

		// DSU dsuMST(9);
		// sort(edges.begin(), edges.end(), custom_compare);
		// int min_weight = 0;
		// for(int i=0;i<edges.size();i++){
		// 	int a = edges[i][0];
		// 	int spa = dsuMST.find_superparent(a);
		// 	int b = edges[i][1];
		// 	int spb = dsuMST.find_superparent(b);

		// 	if(spa != spb){
		// 		min_weight += edges[i][2];
		// 		dsuMST.merge(a,b);
		// 		cout << endl << a << "->" << b << endl;
		// 	}
		// }

		// cout << "The min weight is : " << min_weight;


		// Prims

		// UndirectedWeightedGraph uwg(9);
		// for(int i=0;i<edges.size();i++){
		// 	uwg.add_edge(edges[i][0],edges[i][1],edges[i][2]);
		// }

		// //uwg.prims_algo();
		// uwg.prims_algo_using_priority_queue();

	}
	return 0;
}


