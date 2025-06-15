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

void printLeftViewOfBinaryTree(node *root, map<int,int> &levelLeftView, int currLevel){
	/*
		The approach is based on the fact that, my left most node at any particular level
		would be traversed the earliest, 
		so if it is traversed the earliest, and node has been set for that level
		why do I need to change anything
	*/
	if(root == NULL){
		return;
	}

	if(levelLeftView.find(currLevel) == levelLeftView.end()){
		levelLeftView[currLevel] = root->data;
	}

	printLeftViewOfBinaryTree(root->left,levelLeftView,currLevel+1);
	printLeftViewOfBinaryTree(root->right,levelLeftView,currLevel+1);
	return;
}

void printRightViewOfBinaryTree(node *root, map<int,int> &levelRightView, int currLevel){
	if(root == NULL){
		return;
	}

	if(levelRightView.find(currLevel) == levelRightView.end()){
		levelRightView[currLevel] = root->data;
	}

	printRightViewOfBinaryTree(root->right,levelRightView,currLevel+1);
	printRightViewOfBinaryTree(root->left,levelRightView,currLevel+1);
	return;
}

void printBottomViewOfBinaryTree(node *root, map<int,pair<int,int>> &hDBottomView, int horizontalDistance, int currLevel){
	// Approach - 2, do BFS using queue, traverse each level one by one, will be at the highest level at the last
	if(root == NULL){
		return;
	}

	if(hDBottomView.find(horizontalDistance) == hDBottomView.end()){
		hDBottomView[horizontalDistance] = {root->data,currLevel};
	}else{
		if(currLevel >= hDBottomView[horizontalDistance].second){
			hDBottomView[horizontalDistance] = {root->data,currLevel};
		}
	}

	printBottomViewOfBinaryTree(root->left,hDBottomView,horizontalDistance-1,currLevel+1);
	printBottomViewOfBinaryTree(root->right,hDBottomView,horizontalDistance+1,currLevel+1);
	return;
}

vector<int> printBottomViewOfBinaryTreeUsingQueue(node *root){
	if(root == NULL){
		return {};
	}

	map<int,int> bottomLevelView;
	queue<pair<node*,int>> q;

	/*
		no need to take care of level in this approach, because we know that, higher level 
		takes precedence and we would be accessing higher levels late only in this approach

		higher levels will be visited late
		nodes at the same horizontal distance and same level, in that also nodes which are towards right will be visited late
	*/

	q.push({root,0});
	while(!q.empty()){
		pair<node*,int> p = q.front();
		q.pop();
		node* n = p.first;
		int hd = p.second;

		bottomLevelView[hd] = n->data;
		if(n->left) q.push({n->left,hd-1}); 
		if(n->right) q.push({n->right,hd+1}); 
	}

	vector<int> ans;
	for(auto &x : bottomLevelView) {
		ans.push_back(x.second);
	}

	return ans;
}


void printTopViewOfBinaryTree(node *root, map<int,pair<int,int>> &hdTopView, int horizontalDistance, int currLevel){
	if(root == NULL){
		return;
	}

	if(hdTopView.find(horizontalDistance) == hdTopView.end()){
		hdTopView[horizontalDistance] = {root->data,currLevel};
	}else{
		if(currLevel < hdTopView[horizontalDistance].second){
			hdTopView[horizontalDistance] = {root->data,currLevel};
		}
	}


	printTopViewOfBinaryTree(root->left,hdTopView,horizontalDistance-1,currLevel+1);
	printTopViewOfBinaryTree(root->right,hdTopView,horizontalDistance+1,currLevel+1);
	return;
}

vector<int> printTopViewOfBinaryTreeUsingQueue(node *root){
	if(root == NULL){
		return {};
	}

	map<int,int> topLevelView;
	queue<pair<node*,int>> q;

	q.push({root,0});
	while(!q.empty()){
		pair<node*,int> p = q.front();
		q.pop();
		node* n = p.first;
		int hd = p.second;
		if(topLevelView.find(hd) == topLevelView.end()){
			topLevelView[hd] = n->data;
		}

		if(n->left) q.push({n->left,hd-1}); 
		if(n->right) q.push({n->right,hd+1}); 
	}

	vector<int> ans;
	for(auto &x : topLevelView) {
		ans.push_back(x.second);
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
		cout << endl;

		cout << "Left View: " << endl;
		map<int,int> levelLeftView;
		printLeftViewOfBinaryTree(root,levelLeftView,0);
		for(auto &x : levelLeftView){
			cout << x.first << "->" << x.second << endl;
		}


		cout << "Right View: " << endl;
		map<int,int> levelRightView;
		printRightViewOfBinaryTree(root,levelRightView,0);
		for(auto &x : levelRightView){
			cout << x.first << "->" << x.second << endl;
		}


		cout << "Bottom View: " << endl;
		map<int,pair<int,int>> hDBottomView;
		printBottomViewOfBinaryTree(root,hDBottomView,0,0);
		for(auto &x : hDBottomView){
			cout << x.first << "->" << x.second.first << endl;
		}

		cout << "Bottom View Using Queue: " << endl;
		vector<int> bottomView = printBottomViewOfBinaryTreeUsingQueue(root);
		for(auto &x : bottomView){
			cout << x << " ";
		}

		cout << endl;
		cout << "Top View: " << endl;
		map<int,pair<int,int>> hdTopView;
		printTopViewOfBinaryTree(root,hdTopView,0,0);
		for(auto &x : hdTopView){
			cout << x.first << "->" << x.second.first << endl;
		}

		cout << endl;
		cout << "Top View Using Queue: " << endl;
		vector<int> topView = printTopViewOfBinaryTreeUsingQueue(root);
		for(auto &x : topView){
			cout << x << " ";
		}



	}
	return 0;
}
