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

class node {
	public:
		int data;
		node* left;
		node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void print(node* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

void printPreOrder(node* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(node* root) {
	if(root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

void printPostOrder(node* root) {
	if(root == NULL) {
		return;
	}

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}

int height(node* root) {
	if(root == NULL) {
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh) + 1;
}

void printKthLevel(node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 0) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
}

void levelOrderPrint(node* root) {
	if(root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* curr = q.front();
		q.pop();
		if(curr == NULL) {
			cout << endl;
			if(!q.empty()) q.push(NULL);
			continue;
		}

		cout << curr->data << " ";
		if(curr->left != NULL) q.push(curr->left);
		if(curr->right != NULL) q.push(curr->right);
	}
}

int countNode(node* root) {
	if(root == NULL) {
		return 0;
	}

	int lc = countNode(root->left);
	int rc = countNode(root->right);
	return 1 + lc + rc;
}

int sumNode(node* root) {
	if(root == NULL) {
		return 0;
	}

	int lsum = sumNode(root->left);
	int rsum = sumNode(root->right);
	return root->data + lsum + rsum;
}

// 1st part : signifies diameter, 
// 2nd part : signifies height
pair<int,int> findMaxDiameter(node* root) {
	if(root == NULL) {
		return {0, 0};
	}

	pair<int,int> p1 = findMaxDiameter(root->left);
	pair<int,int> p2 = findMaxDiameter(root->right);

	int opt1 = p1.first;
	int opt2 = p2.first;
	int opt3 = p1.second + p2.second;

	return { max(opt1,max(opt2,opt3)), 1 + max(p1.second, p2.second)};
}

int sumReplacement(node* root) {
	if(root == NULL) {
		return 0;
	}

	if(root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int temp = root->data;
	int leftSum = sumReplacement(root->left);
	int rightSum = sumReplacement(root->right);
	root->data = leftSum + rightSum;

	return temp + root->data;
}

class HBPair {
public:
	int height;
	bool balanced;

	HBPair(int height, bool balanced) {
		this->height = height;
		this->balanced = balanced;
	}
};

HBPair heightBalanced(node* root) {
	if(root == NULL) {
		return HBPair(0, true);
	}

	HBPair left = heightBalanced(root->left);
	HBPair right = heightBalanced(root->right);

	int diff = abs(left.height - right.height);

	return HBPair(1 + max(left.height, right.height), (left.balanced && right.balanced && (diff <= 1)));
}

node* createBalancedTree(int arr[], int s, int e) {

	if(s > e) {
		return NULL;
	}

	if ( s == e ) {
		return new node(arr[s]);
	}

	int mid = (s + e) / 2;
	node* n = new node(arr[mid]);
	n->left = createBalancedTree(arr, s, mid-1);
	n->right = createBalancedTree(arr, mid+1, e);
}

int globalIdx;

node* createTree(int *pre, int *in, int s, int e) {

	if (s > e) {
		return NULL;
	}

	int idxToSplit;
	for(int i=s;i<=e;i++) {
		if(in[i] == pre[globalIdx]) {
			idxToSplit = i;
			break;
		}
	}

	globalIdx++;

	node* n = new node(in[idxToSplit]);
	n->left = createTree(pre, in, s, idxToSplit-1);
	n->right = createTree(pre, in, idxToSplit+1, e);

	return n;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node* head = buildTree();
		print(head);
		cout << endl;
 
		cout << "PRE_ORDER : "; printPreOrder(head); cout << endl;
		cout << "IN_ORDER : "; printInOrder(head); cout << endl;
		cout << "POST_ORDER : "; printPostOrder(head); cout << endl;

		cout << "HEIGHT : " << height(head); cout << endl;

		cout << "LEVEL ORDER PRINT-1 : " << endl;
		for(int i=0;i<height(head);i++) {
			printKthLevel(head,i);
			cout << endl;
		}

		cout << "LEVEL_ORDER_PRINT-2 : " << endl;
		levelOrderPrint(head);

		cout << "Count of nodes : " << countNode(head) << endl;

		cout << "sum of nodes : " << sumNode(head) << endl;

		cout << "---" << endl;
		pair<int,int> maxDiameter = findMaxDiameter(head);
		cout << "maxDiameter : " << maxDiameter.first << endl;
		cout << "height : " << maxDiameter.second << endl;

		cout << "--- binary tree sum replacement --- " << endl;
		//sumReplacement(head);
		levelOrderPrint(head);

		cout << "--- height balanced tree -----" << endl;
		HBPair hbpair = heightBalanced(head);
		cout << hbpair.height << endl;
		cout << hbpair.balanced << endl;

		cout << "---- create balanced tree from an array ---- " << endl;
		int a[] = {1,2,3,4};
		int n = 4;
		levelOrderPrint(createBalancedTree(a,0,n-1));
		printInOrder(createBalancedTree(a,0,n-1));

		cout << endl << "------ build tree from pre order and post order -------- " << endl;
		int pre[] = {1,2,3,4,8,5,6,7};
		int in[] = {3,2,8,4,1,6,7,5};
		globalIdx = 0;
		levelOrderPrint(createTree(pre, in, 0, 7));


	} 
	return 0;
}
