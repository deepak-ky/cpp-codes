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

class directedGraph{
	int verticesCount;
	vector<char> vertices;
	unordered_map<char,list<char>> mp; // neighbour list
	unordered_map<char,map<char,bool>> isNeighbour;
public:
	directedGraph(int k){
		verticesCount = k;
		char ch = 'a';
		for(int i=0;i<k;i++){
			vertices.push_back(ch);
			ch++;
		}
	}
	void addEdge(char a, char b){
		if((a >= vertices[0] && a <= vertices[verticesCount-1]) &&
		   (b >= vertices[0] && b <= vertices[verticesCount-1]) &&
		   a != b && isNeighbour[a][b] == false && isNeighbour[b][a] == false){
			isNeighbour[a][b] = true;
			mp[a].push_back(b);
		}
		return;
	}

	void topologicalSortDFSHelper(char vertex, map<char,bool> &visited, stack<char> &s){
		visited[vertex] = true;
		for(auto &nbr : mp[vertex]){
			if(!visited[nbr]){
				topologicalSortDFSHelper(nbr,visited,s);
			}
		}
		s.push(vertex);
		return;
	}

	string topologicalSortDFS(){
		map<char,bool> visited;
		stack<char> s;

		for(auto &x : vertices){
			if(!visited[x]){
				topologicalSortDFSHelper(x,visited,s);
			}
		}

		string lexicalOrder = "";
		while(!s.empty()){
			lexicalOrder += s.top();
			s.pop();
		}

		return lexicalOrder;
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{

		vector<string> dictionary = {"baa","abcd","abca","cab","cad"};

		directedGraph dg(4);

		for(int i=0;i<dictionary.size()-1;i++){
			string word1 = dictionary[i];
			string word2 = dictionary[i+1];
			int j = 0;
			int k = 0;
			while(j < word1.length() && k < word2.length()){
				if(word1[j] != word2[k]){
					dg.addEdge(word1[j],word2[k]);
					break;
				}else{
					j++;
					k++;
				}
			}
		}

		cout << dg.topologicalSortDFS();
	}
	return 0;
}
