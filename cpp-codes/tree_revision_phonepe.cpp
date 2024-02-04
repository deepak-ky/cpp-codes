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

void printTree(node *root){
	if(root == NULL){
		return;
	}

	// printing using . operator
/*	cout << (*root).data <<" "<< endl;
	printTree((*root).left);
	printTree((*root).right);*/

	cout << root->data <<" "<< endl;
	printTree(root->left);
	printTree(root->right);
}

void printPreOrderTree(node *root){
	if(root == NULL){
		return;
	}

	cout << root->data << " ";
	printPreOrderTree(root->left);
	printPreOrderTree(root->right);
}

void printInOrderTree(node *root){
	if(root == NULL){
		return;
	}

	printInOrderTree(root->left);
	cout << root->data << " ";
	printInOrderTree(root->right);
}

void printPostOrderTree(node *root){
	if(root == NULL){
		return;
	}

	printPostOrderTree(root->left);
	printPostOrderTree(root->right);
	cout << root->data << " ";
}

int findTreeHeight(node * root) {
	if(root == NULL){
		return 0;
	}
	int h1 = findTreeHeight(root->left);
	int h2 = findTreeHeight(root->right);
	return max(h1,h2) + 1;
}

void printKthLevel(node *root, int level) {
	if(root == NULL){
		return;
	}

	if(level - 1 == 0){
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, level-1);
	printKthLevel(root->right, level-1);
	return;
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

// Using NULL instead of endlNode
/*void printBFS(node * root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		q.pop();

		if (f){
			cout << f->data << " ";
			if(f->left) q.push(f->left);
			if(f->right) q.push(f->right);
		}else{
			cout << endl;
			if(!q.empty()) q.push(NULL);
		}
	}
}
*/
/*void printBFS(node * root) {
	queue<node> q;
	node endlNode(-1);
	q.push(*root);
	q.push(endlNode);

	while(!q.empty()){
		node f = q.front();
		q.pop();

		if (f.data != endlNode.data){
			cout << f.data << " ";
			if(f.left) q.push(*(f.left));
			if(f.right) q.push(*(f.right));
		}else{
			cout << endl;
			if(!q.empty()) q.push(endlNode);
		}
		
	}
}*/

int countNodes(node *root) {
	if(!root) {
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(node *root) {
	if(!root) {
		return 0;
	}
	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int findDiameter(node *root){
	if(root == NULL){
		return 0;
	}
	int h1 = findTreeHeight(root->left);
	int h2 = findTreeHeight(root->right);
	int diameter = h1+h2;
	int diameterLeft = findDiameter(root->left);
	int diameterRight = findDiameter(root->right);

	return max(diameter,max(diameterLeft,diameterRight));
}

pair<int,int> findDiameterOptimizedApproach(node *root) {
	if(root == NULL){
		return {0,0};
	}

	pair<int,int> p1 = findDiameterOptimizedApproach(root->left);
	pair<int,int> p2 = findDiameterOptimizedApproach(root->right);

	int diameter1 = p1.first + p2.first; // diameter passing throught root
	int diameter2 = p1.second;	// diamter of left
	int diameter3 = p2.second; // diameter of right

	int maxDiameter = max(diameter1, max(diameter2,diameter3));
	return {max(p1.first,p2.first)+1, maxDiameter};
}

int replaceNodeToSumOfChildren(node *root){
	if(!root) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}

	int leftSum = replaceNodeToSumOfChildren(root->left);
	int rightSum = replaceNodeToSumOfChildren(root->right);
	int d = root->data;
	root->data = leftSum + rightSum;
	return d + leftSum + rightSum;
}

class TreeInfo{
public:
	int height;
	bool isHeightBalanced;
};

TreeInfo IsHeightBalanced(node *root){
	TreeInfo treeInfo;
	if(!root){
		treeInfo.height = 0;
		treeInfo.isHeightBalanced = true;
		return treeInfo;
	}

	TreeInfo leftSubtreeInfo = IsHeightBalanced(root->left);
	TreeInfo rightSubtreeInfo = IsHeightBalanced(root->right);

	treeInfo.height = max(leftSubtreeInfo.height,rightSubtreeInfo.height) + 1;
	treeInfo.isHeightBalanced = (abs(leftSubtreeInfo.height - rightSubtreeInfo.height) <= 1) && leftSubtreeInfo.isHeightBalanced && rightSubtreeInfo.isHeightBalanced;

	return treeInfo;
}

node* BuildBinaryTreeFromArray(int *a, int s, int e){
	if(s > e) {
		return NULL;
	}

	int m = (s + (e-s)/2);
	node *root = new node(a[m]);
	root->left = BuildBinaryTreeFromArray(a,s,m-1);
	root->right = BuildBinaryTreeFromArray(a,m+1,e);
	return root;
}

node* BuildCompleteBinaryTreeFromArray(int *a, int idx, int n){
	if(idx >= n) return NULL;
	node *root = new node(a[idx]);
	root->left = BuildCompleteBinaryTreeFromArray(a,2*idx+1,n);
	root->right = BuildCompleteBinaryTreeFromArray(a,2*idx+2,n);
	return root;
}

node* BuildCompleteBinaryTreeFromArrayQueue(int *a, int n){
	queue<node*> q;
	int idx = 0;
	node*root = new node(a[0]);
	q.push(root);
	idx++;
	while(idx < n){
		node* f = q.front();
		q.pop();
		if(idx < n){
			f->left = new node(a[idx]);
			q.push(f->left);
			idx++;
		}
		if(idx < n){
			f->right = new node(a[idx]);
			q.push(f->right);
			idx++;
		}
	}
	return root;
}

node* createTreePreAndIn(int preOrder[],int inOrder[],int &rootIdx, int s,int e){
	if(s > e){
		return NULL;
	}

	node*root = new node(preOrder[rootIdx]);
	int idx = -1;
	for(int j=s;j<=e;j++){
		if(inOrder[j] == preOrder[rootIdx]){
			idx = j;
			break;
		}
	}
	rootIdx++;

	/*
	-mujhe pata hain ki mein preorder traversal kar raha hoon
	-toh root ko touch karne ke baad sabse pahle mein apne left ko touch karunga
	-from the inorder array, I know all the elements that can be present on the root's left
	-and because the length of the subset is non zero, so left of the root exists, jisko abhi woh touch karne jaa raha
	-root apne left ko touch karega, and tera left exists bhi karta hain, kyunki subset mein kuch
	-elements hain, toh kar touch, mein nikal lunga subset mein se left root kya hain*/

	//jist is this-> root jisko next touch karne wala hain us subset pahle hee hoon mein
	//jab 5 ko touch karne jaayega, toh mein pahle hee 6,7,5 wale subset mein hoon

	// s to j-1 of the inOrder array will contribute to my left subtree
	// j+1 to e of the inOrder array will contribute to my right subtree
	root->left = createTreePreAndIn(preOrder,inOrder,rootIdx,s,idx-1);
	root->right = createTreePreAndIn(preOrder,inOrder,rootIdx,idx+1,e);
	return root;
}

node* createTreePostAndIn(int postOrder[],int inOrder[],int &rootIdx, int s,int e){
	if(s > e){
		return NULL;
	}

	node*root = new node(postOrder[rootIdx]);
	int idx = -1;
	for(int j=s;j<=e;j++){
		if(inOrder[j] == postOrder[rootIdx]){
			idx = j;
			break;
		}
	}
	rootIdx--;

	root->right = createTreePostAndIn(postOrder,inOrder,rootIdx,idx+1,e);
	root->left = createTreePostAndIn(postOrder,inOrder,rootIdx,s,idx-1);
	return root;
}




int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		// Pointer Basics
		/*node root(4);
		cout << root.data << endl;

		node* root1 = new node(3);
		cout << root1 << endl;
		cout << (*root1).data << endl;
		cout << root1->data << endl;*/

		//Building a binary tree
		// Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
		// Input : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
		//node * root = buildTree();
		//printTree(root);

		/*cout << "PreOrder Print: "; printPreOrderTree(root);
		cout << endl;
		cout << "InOrder Print: "; printInOrderTree(root);
		cout << endl;
		cout << "PostOrder Print: "; printPostOrderTree(root);*/

/*		int h = findTreeHeight(root);
		cout << h << endl;

		for(int i=1;i<=h;i++){
			printKthLevel(root,i);
			cout << endl;
		}*/

		//printBFS(root);

		//cout << countNodes(root);	

		//cout << sumNodes(root);	

		//cout << findDiameter(root);

		// pair<int,int> p1 = findDiameterOptimizedApproach(root);
		// cout << "height: " << p1.first << endl;
		// cout << "diameter: " << p1.second << endl;

		// printBFS(root);
		// cout << endl;
		// int sumOfAllNodes = replaceNodeToSumOfChildren(root);
		// cout << "sumOfAllNodes: " << sumOfAllNodes << endl;
		// printBFS(root);

		/*TreeInfo treeInfo = IsHeightBalanced(root);
		cout << "height: " << treeInfo.height << endl;
		if(treeInfo.isHeightBalanced){
			cout << "Height Balanced";
		}else{
			cout << "Not Height Balanced";
		}*/

		/*int a[10] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
		node *root = BuildBinaryTreeFromArray(a,0,9);
		printBFS(root);

		root = BuildCompleteBinaryTreeFromArray(a,0,10);  
		printBFS(root);

		root = BuildCompleteBinaryTreeFromArrayQueue(a,10);
		printBFS(root);*/

		/*int preOrder[8] = {1,2,3,4,8,5,6,7};
		int inOrder[8] = {3,2,8,4,1,6,7,5};
		int rootIdx = 0;
		node * root = createTreePreAndIn(preOrder, inOrder,rootIdx, 0, 7);
		printBFS(root);*/

		int postOrder[8] = {8,4,5,2,6,7,3,1};
		int inOrder[8] = {4,8,2,5,1,6,3,7};
		int rootIdx = 7;
		node * root = createTreePostAndIn(postOrder, inOrder,rootIdx, 0, 7);
		printBFS(root);

	}
	return 0;
}
