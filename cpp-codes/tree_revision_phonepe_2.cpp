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
	node *left;
	node *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
// returns the memory address of a node 
// returning node* helps in initializing root->left and root->right
node* buildTree(){
	int d;
	cin >> d;
	if (d == -1){
		return NULL;
	}

	node *root = new node(d);

	// building using . operator
	/*(*root).left = buildTree();
	(*root).right = buildTree();*/

	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void printBFS(node * root) {
	queue<node*> q;
	node * endlNode = new node(-1);
	//instead of endlNode NULL can also be used
	q.push(root);
	q.push(endlNode);
	/*	you would only encounter endlNode when previous level has been
		printed completely and all the next level nodes have been added in
		queue. If no next level nodes, then don't push another endlNode*/

	while(!q.empty()){
		node* f = q.front();
		q.pop();

		if (f != endlNode){
			cout << f->data << " ";
			if(f->left) q.push(f->left);
			if(f->right) q.push(f->right);
		}else{
			cout << endl;
			if(!q.empty()) q.push(endlNode);
		}
	}
}

void leftViewHelper(node *root, vector<int> &v, int level){
	if(root == NULL){
		return;
	}
	if(level == v.size()) v.push_back(root->data);
	leftViewHelper(root->left,v,level+1);
	leftViewHelper(root->right,v,level+1);
	return;
}
vector<int> leftView(node *root){
	vector<int> v;
	leftViewHelper(root,v,0);
	return v;
}


void bottomViewHelper(node *root, map<int,pair<int,int>> &mp, int hd, int level){
	if(root == NULL){
		return;
	}

	if(mp.find(hd) == mp.end()){
		pair<int,int> p;
		p.first = level;
		p.second = root->data;
		mp[hd] = p;
	}else{
		pair<int,int> p = mp[hd];
		if(level >= p.first){
			mp[hd].first = level;
			mp[hd].second = root->data;
		}
	}


	bottomViewHelper(root->left,mp,hd-1,level+1);
	bottomViewHelper(root->right,mp,hd+1,level+1);
	return;
}

vector<int> bottomView(node *root){
	vector<int> v;
	map<int,pair<int,int>> mp;
	int hdd = 0;
	int level = 0;
	bottomViewHelper(root,mp,hdd,level);
	for(auto &x : mp){
		v.push_back(x.second.second);
	}
	return v;
}

vector<int> bottomView2(node *root){
	//can do a level order traversal, and keep replacing
	//greater level elements will come later
	//same level, hd same, will also come later
}

vector<int> topView(node *root){
	// simple top to bottom traversal with hash map also works, no need to check for level in this case

	vector<int> ans;
	queue<pair<node*,int>> q;
	q.push({root,0});
	map<int,int> mp;
	while(!q.empty()){
		pair<node*,int> fq = q.front();
		q.pop();

		int hd = fq.second;
		if(mp.find(hd) == mp.end()){
			mp[hd] = fq.first->data;
		}

		if(fq.first->left) q.push({fq.first->left, hd-1});
		if(fq.first->right) q.push({fq.first->right, hd+1});
	}

	for(auto &x : mp){
		ans.push_back(x.second);
	}
	return ans;
}

void iterativePreTraversal(node *root){
	map<node*,int> mp;
	//mp[node*] -> 0,1,2,3 | whatever value you find, you have to do that with it
	// 0 -> print
	// 1 -> push left
	// 2 -> push right
	// 3 -> pop
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node* t = s.top();
		if(t == NULL) {
			s.pop();
			continue;
		}
		if(mp[t] == 0) cout << t->data << " ";
		else if(mp[t] == 1) s.push(t->left);
		else if(mp[t] == 2) s.push(t->right);
		else if(mp[t] == 3) s.pop();
		mp[t]++; //to decide, what to do next
	}
}

void iterativeInTraversal(node *root){
	map<node*,int> mp;
	//mp[node*] -> 0,1,2,3 | whatever value you find, you have to do that with it
	// 0 -> push left
	// 1 -> print
	// 2 -> push right
	// 3 -> pop
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node* t = s.top();
		if(t == NULL) {
			s.pop();
			continue;
		}
		if(mp[t] == 0)  s.push(t->left); 
		else if(mp[t] == 1) cout << t->data << " ";
		else if(mp[t] == 2) s.push(t->right);
		else if(mp[t] == 3) s.pop();
		mp[t]++; //to decide, what to do next
	}
}

void iterativePostTraversal(node *root){
	map<node*,int> mp;
	//mp[node*] -> 0,1,2,3 | whatever value you find, you have to do that with it
	// 0 -> push left
	// 1 -> push right
	// 2 -> print
	// 3 -> pop
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node* t = s.top();
		if(t == NULL) {
			s.pop();
			continue;
		}
		if(mp[t] == 0)  s.push(t->left); 
		else if(mp[t] == 1) s.push(t->right);
		else if(mp[t] == 2) cout << t->data << " ";
		else if(mp[t] == 3) s.pop();
		mp[t]++; //to decide, what to do next
	}
}

void allTraversalAtOnce(node *root){
	vector<int> pre;
	vector<int> in;
	vector<int> post;
	//0 -> pre print and push left
	//1 -> in print and push right
	//2 -> post print and pop
	stack<node*> s;
	map<node*,int> mp;
	s.push(root);

	

	while(!s.empty()){
		node*t = s.top();
		if(t == NULL){
			s.pop();
			continue;
		}
		if(mp[t] == 0){
			pre.push_back(t->data);
			s.push(t->left);
		}else if(mp[t] == 1){
			in.push_back(t->data);
			s.push(t->right);
		}else if(mp[t] == 2){
			post.push_back(t->data);
			s.pop();
		}
		mp[t]++;
	}

	for(auto &x : pre) cout << x << " "; 
		cout << endl;
	for(auto &x : in) cout << x << " "; 
		cout << endl;
	for(auto &x : post) cout << x << " "; 
		cout << endl;
}

bool printRootToNodePath(node *root, int x, vector<int> &currentPath){
	if(root == NULL) {
		return false;
	}

	currentPath.push_back(root->data);

	if(root->data == x) {
		return true;
	}

	bool b1 = printRootToNodePath(root->left,x,currentPath);
	bool b2 = printRootToNodePath(root->right,x,currentPath);

	if (b1 || b2) {
		return true;
	}

	currentPath.pop_back();
	return false;
}

pair<int,int> FindMaximumPathFromAnyNodeToAnyNode(node *root){
	pair<int,int> p;
	//p.first denotes maximumSumPathInSubtree
	//p.second denotes maximumLinearSumFromSubtreeRootToLeafNode
	if(root == NULL){
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int,int> left = FindMaximumPathFromAnyNodeToAnyNode(root->left);
	pair<int,int> right = FindMaximumPathFromAnyNodeToAnyNode(root->right);

	int maximumPath = INT_MIN;
	if(root->left) maximumPath = max(maximumPath,left.first);
	if(root->right) maximumPath = max(maximumPath,right.first);
	maximumPath = max(maximumPath,left.second + root->data + right.second);
	maximumPath = max(maximumPath,left.second + root->data);
	maximumPath = max(maximumPath,right.second + root->data);
	maximumPath = max(maximumPath,root->data);

	int maxLinearPath = INT_MIN;
	maxLinearPath = max(maxLinearPath,max(left.second,right.second) + root->data);
	maxLinearPath = max(maxLinearPath,root->data);

	p.first = maximumPath;
	p.second = maxLinearPath;
	cout << root->data << endl;
	cout << "Maximum Path: " << p.first << " ";
	cout << endl << "Maximum Linear Sum: " << p.second << " ";
	cout << endl;
	return p;
}

int FindMaximumPathFromAnyNodeToAnyNode2(node *root, int &globalMax){
	if(root == NULL){
		return 0;
	}

	int left = FindMaximumPathFromAnyNodeToAnyNode2(root->left,globalMax);
	int right = FindMaximumPathFromAnyNodeToAnyNode2(root->right,globalMax);

	globalMax = max(globalMax,left + root->data + right);
	globalMax = max(globalMax,left + root->data);
	globalMax = max(globalMax,right + root->data);
	globalMax = max(globalMax,root->data);

	int maxLinearPath = INT_MIN;
	maxLinearPath = max(maxLinearPath,max(left,right) + root->data);
	maxLinearPath = max(maxLinearPath,root->data);

	return maxLinearPath;
}

void printNodesAtDistanceKDown(node *root, int k, vector<int> &ans){
	if(root == NULL){
		return;
	}

	if(k < 0){
		return;
	}

	if(k == 0){
		ans.push_back(root->data);
		return;
	}

	printNodesAtDistanceKDown(root->left,k-1,ans);
	printNodesAtDistanceKDown(root->right,k-1,ans);
	return;
}

int nodesAtDistanceK(node *root, node *target, int k, vector<int> &ans){
	if(root == NULL){
		return -1;
	}

	if(root == target){
		printNodesAtDistanceKDown(root,k,ans);
		return 1; // returning back to my immediate parent, and saying I am at a 
		// distance 1 from you
	}

	int leftDist = nodesAtDistanceK(root->left,target,k,ans);
	if(leftDist != -1){ // target lies on my left
		if(k == leftDist){
			ans.push_back(root->data);
		}
		printNodesAtDistanceKDown(root->right,k-leftDist-1,ans);
		return leftDist+1;
	}

	int rightDist = nodesAtDistanceK(root->right,target,k,ans);
	if(rightDist != -1){ // target lies on my right
		if(k == rightDist){
			ans.push_back(root->data);
		}
		printNodesAtDistanceKDown(root->left,k-rightDist-1,ans);
		return rightDist+1;
	}

	return -1;
}

vector<int> distanceK(node *root, node *target, int k){
	vector<int> ans;
	int dist = nodesAtDistanceK(root,target,k,ans);
	return ans;
}


bool findLCA(node *root, node *p, node *q, node *&lca){
	if(root == NULL){
		return false;
	}

	if(root != p && root != q){
		// cout << "not equal : " << root->data << endl;
		bool b1 = findLCA(root->left,p,q,lca);
		bool b2 = findLCA(root->right,p,q,lca);
		// if(b1) cout << root->data << "left yes" << endl;
		// if(b2) cout << root->data << "right yes" << endl;
		if(b1 && b2) {
			// cout << "SETTING LCA";
			lca = root;
			// cout << lca->data << endl;
			// cout << "LCA set";
		}
		return b1 || b2;
	}else if(root == p || root == q){
		// cout << "equal : " << root->data << endl;
		bool b1 = findLCA(root->left,p,q,lca);
		bool b2 = findLCA(root->right,p,q,lca);
		// if(b1) cout << root->data << "left yes" << endl;
		// if(b2) cout << root->data << "right yes" << endl;
		if(b1 || b2) {
			// cout << "SETTING LCA";
			lca = root;
		}
		return true;
	}

	return false;
}

node* lowestCommonAncestor(node *root, node *p, node *q) {
	node *lca = NULL;
	bool f = findLCA(root,p,q,lca);
	return lca;
}	

node* lowestCommonAncestor2(node *root, node *p, node *q) {
	if(root == NULL) {
		return NULL;
	}

	if(root == p || root == q){
		return root; // either I will be the lca, or in the other case I will contribute to the lca
	}

	node *left = lowestCommonAncestor2(root->left,p,q);
	node *right = lowestCommonAncestor2(root->right,p,q);

	if(!left && !right){
		return NULL;
	}else if(!left && right){
		return right;
	}else if(left && !right){
		return left;
	}
	return root;
}	


int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node* root = buildTree();
		//printBFS(root);

		/*vector<int> lv = leftView(root);
		for(auto &x : lv){
			cout << x << endl;
		}
		cout << endl;*/

		/*vector<int> bv = bottomView(root);
		for(auto &x : bv){
			cout << x << endl;
		}
		cout << endl;*/

		/*vector<int> tv = topView(root);
		for(auto &x : tv){
			cout << x << endl;
		}
		cout << endl;*/

		/*iterativePreTraversal(root);
		cout << endl;
		iterativeInTraversal(root);
		cout << endl;
		iterativePostTraversal(root);
		cout << endl;

		allTraversalAtOnce(root);*/

		/*vector<int> path;
		if(printRootToNodePath(root,3,path)) {
			for(auto &x : path){
				cout << x << " ";
			}
			cout << endl;
		}else{
			for(auto &x : path){
				cout << x << " ";
			}
			cout << endl;
			cout << "Element does not exist";
		}*/

		/*pair<int,int> p = FindMaximumPathFromAnyNodeToAnyNode(root);
		cout << "Maximum Path: " << p.first << " ";
		cout << endl << "Maximum Linear Sum: " << p.second << " ";


		int globalMax = INT_MIN;
		int maxLinearPath = FindMaximumPathFromAnyNodeToAnyNode2(root,globalMax);
		cout << "globalMax: " << globalMax << " ";
		cout << endl << "maxLinearPath: " << maxLinearPath << " ";*/

		//printBFS(root);

		/*node * target = root->right->left;
		vector<int> distanceKNodes = distanceK(root,target,3);
		for(auto &x : distanceKNodes){
			cout << x << " ";
		}*/

		printBFS(root);
		node *p = root->left->left;
		//printBFS(p);
		node *q = root->left;
		//printBFS(q);
		node *lca = lowestCommonAncestor(root,p,q);
		cout << endl;
		cout << lca->data;

		node *lca2 = lowestCommonAncestor2(root,p,q);
		cout << endl;
		cout << lca2->data;

	}
	return 0;
}
