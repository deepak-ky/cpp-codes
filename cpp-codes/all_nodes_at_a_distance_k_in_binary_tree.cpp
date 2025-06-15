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

class node{
public:
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int data;
	cin >> data;
	if(data == -1){
		return NULL;
	}

	node *head = new node(data);
	head->left = buildTree();
	head->right = buildTree();
	return head;
}

void printLevelByLevelBFS(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node *t = q.front();
		q.pop();

		if(t != NULL){
			cout << t->data << " ";
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
		}else{
			cout << endl;
			if(!q.empty()) q.push(NULL);
		}
	}
}

void printNodesAtKDistanceDown(node *root, int k, vector<int> &ans){
	if(root == NULL){
		return;
	}

	if(k < 0) return;

	if(k == 0){
		ans.push_back(root->data);
		return;
	}

	printNodesAtKDistanceDown(root->left,k-1,ans);
	printNodesAtKDistanceDown(root->right,k-1,ans);
	return;
}

int printNodesAtDistanceK(node *root, node *target, int k, vector<int> &ans){
	if(root == NULL){
		return -1;
	}

	if(root == target){
		printNodesAtKDistanceDown(root,k,ans);
		return 1;
	}

	int leftDistance = printNodesAtDistanceK(root->left,target,k,ans);
	if(leftDistance >= 0){
		if(leftDistance == k){
			ans.push_back(root->data);
		}else if(leftDistance < k){
			printNodesAtKDistanceDown(root->right,k-leftDistance-1,ans);
		}
		return leftDistance + 1;
	}

	int rightDistance = printNodesAtDistanceK(root->right,target,k,ans);
	if(rightDistance >= 0){
		if(rightDistance == k){
			ans.push_back(root->data);
		}else if(rightDistance < k){
			printNodesAtKDistanceDown(root->left,k-rightDistance-1,ans);
		}
		return rightDistance + 1;
	}

	return -1;
}

vector<int> distanceK(node *root, node *target, int k){
	/*
	// Approach - 1
	vector<int> ans;
	int dist = printNodesAtDistanceK(root,target,k,ans);
	return ans;

	*/

	// Approach - 2
	// Devise a parent array

	map<node*,node*> parent;
	queue<node*> q;
	q.push(root);
	parent[root] = root;
	while(!q.empty()){
		node * t = q.front();
		q.pop();
		if(t->left){
			parent[t->left] = t;
			q.push(t->left);
		}

		if(t->right){
			parent[t->right] = t;
			q.push(t->right);
		}
	}

	/*for(auto &x : parent){
		cout << x.first->data << "->" << x.second->data << endl;
	}

	return {};*/

	queue<pair<node*,int>> qt;
	map<node*,bool> visited;
	qt.push({target,0});
	visited[target] = true;

	vector<int> ans;

	while(!qt.empty()){
		pair<node*,int> f = qt.front();
		qt.pop();

		node *n = f.first;
		int currDist = f.second;


		if(currDist == k){
			ans.push_back(n->data);
		}else{
			if(n->left && !visited[n->left]){
				visited[n->left] = true;
				qt.push({n->left,currDist+1});
			}

			if(n->right && !visited[n->right]){
				visited[n->right] = true;
				qt.push({n->right,currDist+1});
			}

			if(!visited[parent[n]]){
				visited[parent[n]] = true;
				qt.push({parent[n],currDist+1});
			}
		}
	}

	return ans;

}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node * root = buildTree();
		printLevelByLevelBFS(root);
		cout << endl;cout << endl;
		// vector<int> ans;
		// printNodesAtKDistanceDown(root,0,ans);
		// for(auto &x : ans) {
		// 	cout << x << " ";
		// }

		vector<int> nodesAtDistanceK = distanceK(root,root->right,0);
		for(auto &x : nodesAtDistanceK){
			cout << x << " ";
		}
	}
	return 0;
}
