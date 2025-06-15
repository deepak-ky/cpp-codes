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

void allTraversalsAtOnceIteratively(node *root){
	/*
		In all the three traversals, we do left and right, the difference is just that when do we print the root

		Print root->data for :	 	PreOrder        InOrder         PostOrder
										^	left   		^  	 right  	^

		You can understand from the above diagram that, in all the three traversals
		we will be traversing both left and right.In the same manner, first left and then secondly right.

		It's just that 
			1. We will print the root before visiting left for preOrder printing.
			2. We will print the root after visiting left and before visiting the right for InOrder printing.
			3. We will print the root after visiting both left and right for postOrder printing.
	*/

	map<node*,int> state;
	stack<node*> s;
	s.push(root);

	vector<int> preOrder;
	vector<int> inOrder;
	vector<int> postOrder;

	// state - 0 , (new node in stack) 				 						Print PreOrder, Traverse Left, Mark yourself as 1
	// state - 1 , (left of this node, has already been visited) 			Print InOrder, Traverse Right, Mark yourself as 2
	// state - 2 , (left and right of this node have already been visited)	Print PostOrder, Pop

	while(!s.empty()){
		node * t = s.top();
		if(t == NULL) { 
			s.pop(); 
			continue; 
		}else if(state[t] == 0){
			preOrder.push_back(t->data);
			s.push(t->left);
			state[t]++;
		}else if(state[t] == 1){
			inOrder.push_back(t->data);
			s.push(t->right);
			state[t]++;
		}else if(state[t] == 2){
			postOrder.push_back(t->data);
			s.pop();
		}
	}

	cout << "PreOrder : "; for(auto &x : preOrder) cout << x << ","; cout << endl;
	cout << "InOrder : "; for(auto &x : inOrder) cout << x << ","; cout << endl;
	cout << "PostOrder : "; for(auto &x : postOrder) cout << x << ","; cout << endl;
}

void allTraversalsAtOnceRecursively(node *root,vector<int> &preOrder, vector<int> &inOrder, vector<int> &postOrder){
	if(root == NULL){
		return;
	}

	preOrder.push_back(root->data);
	allTraversalsAtOnceRecursively(root->left,preOrder,inOrder,postOrder);
	inOrder.push_back(root->data);
	allTraversalsAtOnceRecursively(root->right,preOrder,inOrder,postOrder);
	postOrder.push_back(root->data);
	return;
}



int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node *root = buildTree();
		printLevelByLevelBFS(root);
		cout << endl;
		allTraversalsAtOnceIteratively(root);

		vector<int> preOrder, inOrder, postOrder;
		allTraversalsAtOnceRecursively(root,preOrder,inOrder,postOrder);
		cout << endl; cout << endl;
		cout << "Recursively : " << endl;
		cout << "PreOrder : "; for(auto &x : preOrder) cout << x << ","; cout << endl;
		cout << "InOrder : "; for(auto &x : inOrder) cout << x << ","; cout << endl;
		cout << "PostOrder : "; for(auto &x : postOrder) cout << x << ","; cout << endl;
	}
	return 0;
}
