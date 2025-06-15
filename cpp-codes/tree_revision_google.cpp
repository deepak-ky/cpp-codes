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

void printInOrder(node *root){
	if(root == NULL){
		return;
	}

	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

int findTreeHeight(node * root) {
	if(root == NULL){
		return 0;
	}
	int h1 = findTreeHeight(root->left);
	int h2 = findTreeHeight(root->right);
	return max(h1,h2) + 1;
}

int findHeight(node *root){
	if(root == NULL){
		return 0;
	}

	return 1 + max(findHeight(root->left),findHeight(root->right));
}

node* buildBinaryTreeFromVector(vector<int> v,int l,int h){
	if(l > h) return NULL;

	int m = l + ((h-l)/2);
	node * root = new node(v[m]);

	root->left = buildBinaryTreeFromVector(v,l,m-1);
	root->right = buildBinaryTreeFromVector(v,m+1,h);
	return root;
}

node* createBinaryTreeFromPreAndInOrder(vector<int> pre,vector<int> in,int &preIdx,int s,int e){
	if(s>e) {
		return NULL;
	}

	int rootData = pre[preIdx];
	node * root = new node(rootData);
	int index = -1;
	for(int j=s;j<=e;j++){
		if(in[j] == rootData){
			index = j;
			break;
		}
	}
	preIdx++;

	root->left = createBinaryTreeFromPreAndInOrder(pre,in,preIdx,s,index-1);
	root->right = createBinaryTreeFromPreAndInOrder(pre,in,preIdx,index+1,e);
	return root;
}

void iterativePostOrderTraversal(node *root){
	map<node*,int> state;
	stack<node*> s;
	s.push(root);
	state[root] = 0;
	while(!s.empty()){
		node * t = s.top();
		if(t == NULL){
			s.pop();
			continue;
		}else if(state[t] == 0){
			s.push(t->left);
		}else if(state[t] == 1){
			s.push(t->right);
		}else if(state[t] == 2){
			cout << t->data << " ";
		}else if(state[t] == 3){
			s.pop();
		}
		state[t]++;
	}

	// for(auto &x : state){
	// 	cout << x.first->data << " : " << x.second << endl;
	// }
}

void iterativePreOrderTraversal(node *root){
	map<node*,int> state;
	stack<node*> s;
	s.push(root);
	state[root] = 0;
	while(!s.empty()){
		node * t = s.top();
		if(t == NULL){
			s.pop();
			continue;
		}else if(state[t] == 0){
			cout << t->data << " ";
			state[t]++;
		}else if(state[t] == 1){
			s.push(t->left);
			state[t]++;
		}else if(state[t] == 2){
			s.push(t->right);
			state[t]++;
		}else if(state[t] == 3){
			s.pop();
		}
	}
}

void iterativeInOrderTraversal(node *root){
	map<node*,int> state;
	stack<node*> s;
	s.push(root);
	state[root] = 0;
	while(!s.empty()){
		node * t = s.top();
		if(t == NULL){
			s.pop();
			continue;
		}else if(state[t] == 0){
			s.push(t->left);
			state[t]++;
		}else if(state[t] == 1){
			cout << t->data << " ";
			state[t]++;
		}else if(state[t] == 2){
			s.push(t->right);
			state[t]++;
		}else if(state[t] == 3){
			s.pop();
		}
	}
}

void allTraversalsAtOnce(node *ro){

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
		printInOrder(root);
		// cout << endl;
		// cout << findTreeHeight(root);
		// cout << endl;
		// cout << findHeight(root);

		/*vector<int> v = {0,1,2,3};
		node* root = buildBinaryTreeFromVector(v,0,3);

		printLevelByLevelBFS(root);

		cout << "root->data : " << root->data << endl;
		
		cout << "root->right->data : " << root->right->data << endl;
		
		if(root->right->left)
		{cout << "root->right->left->data : " << root->right->left->data << endl;}
		else cout << "root->right->left does not exist" << endl;
		
		cout << "root->right->right->data : " << root->right->right->data << endl;

		if(root->right->right->left)
		{cout << "root->right->right->left->data : " << root->right->right->left->data << endl;}
		else cout << "root->right->right->left does not exist" << endl;

		
		if(root->right->right->right)
		{cout << "root->right->right->right->data : " << root->right->right->right->data << endl;}
		else cout << "root->right->right->right does not exist" << endl;
*/

		/*vector<int> preOrder = {1,2,3,4,8,5,6,7};
		vector<int> inOrder =  {3,2,8,4,1,6,7,5};
		int rootIndex = 0;
		node * root = createBinaryTreeFromPreAndInOrder(preOrder,inOrder,rootIndex,0,7);

		printLevelByLevelBFS(root);*/
		cout << endl;
		iterativePostOrderTraversal(root);
		cout << endl;
		iterativePreOrderTraversal(root);
		cout << endl;
		iterativeInOrderTraversal(root);



	}
	return 0;
}
