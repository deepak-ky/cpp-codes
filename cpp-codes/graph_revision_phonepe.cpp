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
	unordered_map<int,list<int>> mp;

public:
	graph(int v){
		this->v = v;
	}

	void addEdge(int a,int b){
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void printGraph(){
		for(int i=0;i<v;i++){
			cout << i << "->";
			for(auto &x : mp[i]){
				cout << x << ",";
			}
			cout << endl;
		}
	}

	void bfs(int src){
		queue<int> q;
		q.push(src);
		vector<bool> visited(v,false);
		visited[src] = true;
		while(!q.empty()){
			int f = q.front();
			cout << f << " ";
			q.pop();
			for(auto &nbr : mp[f]){
				if(visited[nbr] == false){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout << endl;
	}

	void singleShortestPath(int src){
		queue<int> q;
		vector<int> distance(v,INT_MAX);
		q.push(src);
		distance[src] = 0;
		while(!q.empty()){
			int f = q.front();
			q.pop();
			for(auto &nbr : mp[f]){
				if(distance[nbr] == INT_MAX){
					distance[nbr] = distance[f] + 1;
					q.push(nbr);
				}
			}
		}

		for(int i=0;i<v;i++){
			cout << src << "->" << i << " : " << distance[i] << endl;
		}
	}

	void dfsHelper(int vertex, vector<bool> &visited){
		cout << vertex << " ";
		visited[vertex] = true;
		for(auto &nbr : mp[vertex]){
			if(!visited[nbr]) dfsHelper(nbr,visited);
		}
		return;
	}

	void dfs(int src){
		//Assuming one connected component
		vector<bool> visited(v,false);
		dfsHelper(src,visited);
	}

	bool detectCycleUsingBFS() {
		vector<bool> visited(v,false);
		vector<int> parent(v,-1);

		queue<int> q;
		q.push(0);
		visited[0] = true;
		while(!q.empty()){
			int f = q.front();
			q.pop();
			for(auto &nbr : mp[f]){
				if(visited[nbr]){
					if(parent[f] != nbr){
						return true;
					}
				}else{
					parent[nbr] = f;
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}
		return false;
	}

	bool detectCycleUsingDFSHelper(int vertex,  vector<bool> &visited, vector<int> &parent){
		visited[vertex] = true;
		for(auto &nbr : mp[vertex]){
			if(visited[nbr]){
                if(parent[vertex] != nbr){
                    return true;
                }
			}else{
				parent[nbr] = vertex;
				if(detectCycleUsingDFSHelper(nbr,visited,parent)){
				    return true;
				}
			}
		}
		return false;
	}

	bool detectCycleUsingDFS(){
		vector<bool> visited(v,false);
		vector<int> parent(v,-1);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				if(detectCycleUsingDFSHelper(i,visited,parent)){
					return true;
				}
			}
		}
		return false;
	}

	bool isBiPartiteHelper(int vertex, vector<int> &color){
		int toColor = 3 - color[vertex];
		for(auto &nbr : mp[vertex]){
			if(color[nbr] == 0){
				color[nbr] = toColor;
				bool isBiPartiteFurther = isBiPartiteHelper(nbr,color);
				if(!isBiPartiteFurther) {
					return false;
				}
			}else{
				if(color[nbr] == color[vertex]){
					return false;
				}
			}
		}
		return true;
	}

	bool isBiPartite(){
		vector<int> color(v,0);
		for(int i=0;i<v;i++){
			if(color[i] == 0){ // Not been visited
				color[i] = 1;
				if(!isBiPartiteHelper(i,color)){
					return false;
				}
			}
		}
		return true;
	}

	int shortestCycleUsingBFS(){
		int shortestCycleLength = INT_MAX;
		for(int i=0;i<v;i++){
			vector<int> parent(v,-1);
			vector<int> distance(v,INT_MAX);
			queue<int> q;
			q.push(i);
			distance[i] = 0;
			while(!q.empty()){
				int f = q.front();
				q.pop();
				for(auto &nbr: mp[f]){
					if(distance[nbr] == INT_MAX){
						parent[nbr] = f;
						distance[nbr] = distance[f] + 1;
						q.push(nbr);	
					}else{
						if(parent[f] != nbr){
							//cycle exists
							int cycleLength = distance[f] + distance[nbr] + 1;
							shortestCycleLength = min(shortestCycleLength, cycleLength);
						}
					}
				}
			}
		}
		

		if(shortestCycleLength == INT_MAX){
			return 0;
		}
		return shortestCycleLength;
	}
};

class directedGraph{
	int v;
	unordered_map<int,list<int>> mp;
public:
	directedGraph(int v){
		this->v = v;
	}

	void addEdge(int a,int b){
		mp[a].push_back(b);
	}

	void topologicalSortBFS(){
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

		while(!q.empty()){
			int f = q.front();
			q.pop();
			cout << f << " ";
			for(auto &nbr : mp[f]){
				inDegree[nbr]--;
				if(inDegree[nbr] == 0){
					q.push(nbr);
				}
			}
		}
	}

	void topologocalSortDFSHelper(int vertex,vector<bool> &visited,stack<int> &s){
		visited[vertex] = true;
		for(auto &nbr : mp[vertex]){
			if(!visited[nbr]){
				topologocalSortDFSHelper(nbr,visited,s);
			}
		}
		s.push(vertex);
		return;
	}

	void topologicalSortDFS() {
		vector<bool> visited(v,false);
		stack<int> s;
		for(int i=0;i<v;i++){
			if(visited[i] == false){
				topologocalSortDFSHelper(i,visited,s);
			}
		}

		while(!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
	}

	bool detectCycleUsingDFSHelper(int vertex,vector<bool> &visited, vector<bool> &inCurrentPath){
		visited[vertex] = true;
		inCurrentPath[vertex] = true;
		for(auto &nbr : mp[vertex]){
			if(!visited[nbr]) {
				bool cycleExists = detectCycleUsingDFSHelper(nbr,visited,inCurrentPath);
				if(cycleExists) {
					return true;
				}
			}else{
				if(inCurrentPath[nbr]) {
					return true;
				}
			}
		}

		inCurrentPath[vertex] = false;
		return false;
	}

	bool detectCycleUsingDFS() {
		vector<bool> inCurrentPath(v,false);
		//current Path basically means, the same direction
		//of arrows that I am currently following
		vector<bool> visited(v,false);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				if(detectCycleUsingDFSHelper(i,visited,inCurrentPath)){
					return true;
				}
			}
		}
		return false;
	}

};

class DSU{
	vector<int> parent;
	vector<int> size;
public:
	DSU(int v){
		parent.resize(v);
		size.resize(v);
		for(int i=0;i<v;i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	void displayDSU(){
		cout << endl;
		for(int i=0;i<parent.size();i++){
			cout << i << " : parent->" << parent[i] << " size->" << size[i] << endl;
		}
		cout << endl;
	}

	int findSuperParent(int x){
		if(x == parent[x]){
			return x;
		}
		return (parent[x] = findSuperParent(parent[x]));
	}

	void merge(int a,int b){
		int superparentA = findSuperParent(a);
		int superparentB = findSuperParent(b);
		if(superparentA != superparentB){
			if(size[superparentA] >= size[superparentB]){
				parent[superparentB] = superparentA;
				size[superparentA] += size[superparentB];
				size[superparentB] = 0;
			}else{
				parent[superparentA] = superparentB;
				size[superparentB] += size[superparentA];
				size[superparentA] = 0;
			}
		}
		return;
	}
};

class WeightedGraph{
	int v;
	unordered_map<int,list<pair<int,int>>> mp;
public:
	WeightedGraph(int v){
		this->v = v;
	}

	void addEdge(int a,int b,int w){
		mp[a].push_back({b,w});
		mp[b].push_back({a,w});
	}

	void dijkstra(int src){
		vector<int> distance(v,INT_MAX);
		set<pair<int,int>> s;
		distance[src] = 0;
		s.insert({distance[src],src});
		/*for(auto &x : s) cout << "(" << x.first << "," << x.second << ")," << " ";
		cout << endl;*/
		while(!s.empty()){
			auto it = s.begin();
			s.erase(it);
			int currentDistance = it->first;
			int vertex = it->second;
			for(auto nbr : mp[vertex]){
				int node = nbr.first;
				int edgeWeight = nbr.second;
				if(distance[node] > currentDistance + edgeWeight){
					auto it = s.find({distance[node],node});
					if(it != s.end()){
						s.erase(it);
					}
					distance[node] = currentDistance + edgeWeight;
					s.insert({distance[node],node});
				}
			}
			/*for(auto &x : s) cout << "(" << x.first << "," << x.second << ")," << " ";
			cout << endl;*/
		}

		for(int i=0;i<v;i++){
			cout << src << "->" << i << "-->" << distance[i] << endl;
		}
	}

	bool bellmanFordAlgorithm() {
		vector<int> distance(v,INT_MAX);
		distance[0] = 0;

		for(int i=0;i<v-1;i++){
			for(int j=0;j<v;j++){
				for(auto nbr : mp[j]){
					int node = nbr.first;
					int edgeWeight = nbr.second;
					if(distance[node] > distance[j] + edgeWeight){
						distance[node] = distance[j] + edgeWeight;
					}
				}
			}

			for(int j=0;j<v;j++){
				cout << "0" << "->" << j << "-->" << distance[j] << endl;
			}
			cout << endl;
		}


		for(int i=0;i<v-1;i++){
			for(int j=0;j<v;j++){
				for(auto nbr : mp[j]){
					int node = nbr.first;
					int edgeWeight = nbr.second;
					if(distance[node] > distance[j] + edgeWeight){
						return true;
					}
				}
			}
		}


		return false;
	}


	void floydWarshall(){
		vector<vector<int>> distance(v,vector<int>(v,INT_MAX));

		for(auto &x : mp){
			distance[x.first][x.first] = 0;
			for(auto &y : x.second){
				distance[x.first][y.first] = y.second;
				distance[y.first][x.first] = y.second;
			}
		}

		for(int via=0;via<v;via++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if(distance[i][via] != INT_MAX && distance[via][j] != INT_MAX && (distance[i][via] + distance[via][j] < distance[i][j])){
						distance[i][j] = distance[i][via] + distance[via][j];
					}
				}
			}
		}

		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout /*<<i<<"->"<<j<<" : "*/<<distance[i][j] << " ";
			}
			cout << endl;
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
		/*graph g(6);

		g.addEdge(0,1);
		g.addEdge(0,3);
		g.addEdge(1,2);
		g.addEdge(3,2);
		g.addEdge(3,4);
		g.addEdge(4,5);*/

		/*g.printGraph();*/

		/*cout << "BFS: "; g.bfs(3);
		cout << endl;*/

		/*cout << "single Shotrtest Path (0) : " << endl; g.singleShortestPath(0);
		cout << endl;*/

		/*cout << "DFS: "; g.dfs(4);
		cout << endl;*/

		/*if(g.detectCycleUsingBFS()){
			cout << "cycle exists";
		} else {
			cout << "cycle does not exist";
		}*/

		/*if(g.detectCycleUsingDFS()){
			cout << "cycle exists";
		} else {
			cout << "cycle does not exist";
		}*/

		/*if(g.isBiPartite()){
			cout << "graph is bi-partite";
		} else {
			cout << "graph is not bi-partite";
		}*/

		//cout << "---------------------------------------------------";

		/*graph g(5);

		g.addEdge(0,1);
		g.addEdge(0,2);
		g.addEdge(1,4);
		g.addEdge(1,3);
		g.addEdge(2,4);
		g.addEdge(3,4);*/

		/*cout << "Shortest Cycle in Graph: " << g.shortestCycleUsingBFS() << endl;*/

		//cout << "---------------------------------------------------";

		/*directedGraph dg(6);

		dg.addEdge(0,3);
		dg.addEdge(0,5);
		dg.addEdge(4,5);
		dg.addEdge(4,1); // reverse this for cycle
		dg.addEdge(3,2);
		dg.addEdge(2,1);*/
		//dg.addEdge(5,2); // for cycle detection

		/*cout << "Topological Sort BFS: "; dg.topologicalSortBFS(); cout << endl;
		cout << "Topological Sort DFS: "; dg.topologicalSortDFS();*/

		/*if(dg.detectCycleUsingDFS()){
			cout << "cycle exists";
		}else{
			cout << "cycle does not exist";
		}*/

		//cout << "---------------------------------------------------";

		/*DSU dsu(5);

		pair<int,int> edgeList[4] = {{0,1},{2,3},{3,0},{1,2}};
		for(auto &x : edgeList){
			
			int spA = dsu.findSuperParent(x.first);
			int spB = dsu.findSuperParent(x.second);
			if(spA != spB){
				dsu.merge(spA,spB);
			}else{
				cout << "Cycle exists because of " << x.first << " " << x.second << endl;
			}
			dsu.displayDSU();
		}*/

		//cout << "---------------------------------------------------";

		//WeightedGraph wg(4);
		/*wg.addEdge(0,1,1);
		wg.addEdge(0,2,4);
		wg.addEdge(0,3,7);
		wg.addEdge(1,2,1);
		wg.addEdge(2,3,2);*/

		/*wg.dijkstra(0);*/

		/*WeightedGraph wg(6);
		wg.addEdge(0,2,1);
		wg.addEdge(0,1,7);
		wg.addEdge(1,2,-5); // change to 1 for removing the cycle
		wg.addEdge(1,5,1);
		wg.addEdge(1,4,100);
		wg.addEdge(4,5,1);
		wg.addEdge(4,3,1);

		if(wg.bellmanFordAlgorithm()){
			cout << "negative cycle exists";
		}else{
			cout << "negative cycle does not exist";
		}*/

		WeightedGraph wg(4);
		wg.addEdge(0,1,3);
		wg.addEdge(1,3,1);
		wg.addEdge(1,2,1);
		wg.addEdge(0,2,5);
		wg.addEdge(2,3,2);

		wg.floydWarshall();
	
	}
	return 0;
}