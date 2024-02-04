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

void insertInBST(node *&parent,node *&currentNode,bool onLeft, int d){
	if(parent == NULL){
		parent = new node(d);
		return;
	}

	if(currentNode == NULL){
		if(onLeft){
			parent->left = new node(d);
			return;
		}else{
			parent->right = new node(d);
			return;
		}
	}

	if(d <= currentNode->data){
		insertInBST(currentNode, currentNode->left,true,d);
	}else{
		insertInBST(currentNode, currentNode->right,false,d);
	}

	return;
}

void printBFS(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node *f = q.front();
		q.pop();

		if(f){
			cout << f->data << " ";
			if(f->left) q.push(f->left);
			if(f->right) q.push(f->right);
		}else{
			cout << endl;
			if(!q.empty()) q.push(NULL);
		}
	}

	return;
}


void printRoot(node *&root1){
	cout << endl;
	root1 = new node(105);
	cout << "Root Value in function: " <<root1 << endl;
	cout << "Root Address in function: " <<&root1 << endl;
	if(root1) cout << "Root Data in function: " <<root1->data << endl;
	cout << endl;
}

node* insertInBST2(node *root, int d){
	if(root == NULL){
		return new node(d);
	}

	if(d < root->data){
		root->left = insertInBST2(root->left,d);
	}else if(d > root->data){
		root->right = insertInBST2(root->right,d);
	}

	return root;
}

node* serachInBST(node *root,int val){
	if(root == NULL){
		return NULL;
	}

	if(root->data == val){
		return root;
	}

	if(val <= root->data){
		return serachInBST(root->left,val);
	}else{
		return serachInBST(root->right,val);
	}

	return NULL;
}

void inorder(node *root){
	if(root == NULL){
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
	return;
}


node* deleteInBST(node *root,int val){
	if(root == NULL){
		return root;
	}

	if(root->data != val){
		if(val < root->data){
			// delete in my left and assign back that new/old head back to me
			root->left = deleteInBST(root->left,val);
		}else{
			root->right = deleteInBST(root->right,val);
		}
	}else{
		if(root->left == NULL && root->right == NULL){ //no children
			delete root;
			return NULL;
		}else if(root->left != NULL && root->right == NULL){ //only left child present
			node *n = root->left;
			delete root;
			return n;
		}else if(root->left == NULL && root->right != NULL){ //only right child present
			node *n = root->right;
			delete root;
			return n;
		}else{ // both of my children exist
			// I need to find a replacement- immediate predecssor or successor   
			node *temp = root->left;
			if(temp->right == NULL){
				temp->right = root->right;
				delete root;
				return temp;
			}else{
				node *temp1 = temp;
				while(temp->right != NULL){
					temp1 = temp;
					temp = temp->right;
				}	

				temp->right = root->right;
				if(temp->left) {
                        temp1->right = temp->left;
                }else{
                        temp1->right = NULL;
                }
				temp->left = root->left;
				delete root;
				return temp;
			}
			
		}
	}

	return root;
}


node* deleteInBST2(node *root,int val){
	if(root == NULL){
		return root;
	}

	if(root->data != val){
		if(val < root->data){
			// delete in my left and assign back that new/old head back to me
			root->left = deleteInBST(root->left,val);
		}else{
			root->right = deleteInBST(root->right,val);
		}
	}else{
		if(root->left == NULL && root->right == NULL){ //no children
			delete root;
			return NULL;
		}else if(root->left != NULL && root->right == NULL){ //only left child present
			node *n = root->left;
			delete root;
			return n;
		}else if(root->left == NULL && root->right != NULL){ //only right child present
			node *n = root->right;
			delete root;
			return n;
		}else{ // both of my children exist
			// I need to find a replacement- immediate predecssor or successor   
			node *temp = root->left;
			while(temp->right != NULL){
				temp = temp->right;
			}
			root->data = temp->data;
			root->left = deleteInBST(root->left, temp->data);
		}
	}

	return root;
}

bool isValidBSTHelper(node *root, int min,int max){
	if(root == NULL){
		return true;
	}

	if(root->data < min || root->data > max){
		return false;
	}

	bool b1 = isValidBSTHelper(root->left,min,root->data);
	bool b2 = isValidBSTHelper(root->right,root->data,max);

	return b1 && b2;
}

bool isValidBST(node *root){
	return isValidBSTHelper(root,INT_MIN,INT_MAX);
}

void flattenTree(node *root){
	if(root == NULL){
		return;
	}

	if(root->left != NULL && root->right != NULL){
		flattenTree(root->left);
		flattenTree(root->right);

		node *temp = root->left;
		while(temp->right != NULL){
			temp = temp->right;
		}

		temp->right = root->right;
		root->right = root->left;
		root->left = NULL;
		return;
	}else if(root->left == NULL && root->right != NULL) {
		flattenTree(root->right);
		return;
	}else if(root->left != NULL && root->right == NULL) {
		flattenTree(root->left);
		root->right = root->left;
		root->left = NULL;
		return;
	}

	return;
}


node* flattenTreeToDLL(node *root){
	if(root == NULL){
		return NULL;
	}

	if(root->left != NULL && root->right != NULL){
		root->left = flattenTreeToDLL(root->left); // root's left pointer would be attached to the new left
		root->right = flattenTreeToDLL(root->right); // root's right pointer would be attached to the new right

		node *temp = root->left;
		while(temp->right != NULL){
			temp = temp->right;
		}

		node *newHead = root->left;
		root->right->left = root;
		temp->right = root;
		root->left = temp;
		return newHead;
	}else if(root->left != NULL && root->right == NULL){
		root->left = flattenTreeToDLL(root->left);

		node *temp = root->left;
		while(temp->right != NULL){
			temp = temp->right;
		}

		node *newHead = root->left;
		temp->right = root;
		root->left = temp;
		return newHead;
	}else if(root->left == NULL && root->right != NULL){
		root->right = flattenTreeToDLL(root->right);
		root->right->left = root;
		return root;
	}

	return root;
}

void morrisInOrder(node *root){
	// Watch Striver Video it is pretty good
	node* currNode = root;
	vector<int> ans;

	while(currNode != NULL) {
		if(currNode->left){
			// I cannot come back ever agin, I need to make a thread
			node * pre = currNode->left;
			while(pre->right != NULL && pre->right != currNode){
				pre = pre->right;
			}

			if(pre->right){
				pre->right = NULL;
				ans.push_back(currNode->data);
				currNode = currNode->right;
			}else{
				pre->right = currNode;
				currNode = currNode->left;
			}
		}else{
			ans.push_back(currNode->data);
			currNode = currNode->right;
		}
	}

	for(auto &x : ans) {
		cout << x << " ";
	}
}


void morrisPreOrder(node *root){
	// Watch Striver Video it is pretty good
	node* currNode = root;
	vector<int> ans;

	while(currNode != NULL) {
		if(currNode->left){
			// I cannot come back ever agin, I need to make a thread
			node * pre = currNode->left;
			while(pre->right != NULL && pre->right != currNode){
				pre = pre->right;
			}

			if(pre->right){
				pre->right = NULL;
				currNode = currNode->right;
			}else{
				pre->right = currNode;
				ans.push_back(currNode->data);
				currNode = currNode->left;
			}
		}else{
			ans.push_back(currNode->data);
			currNode = currNode->right;
		}
	}

	for(auto &x : ans) {
		cout << x << " ";
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node *root = NULL;
		node *root1 = NULL;
		int d = 0;

		// Input 5 3 7 1 6 8 -1 
		while(true){
			cin >> d;
			if(d == -1) break;
			insertInBST(root,root,true,d);
			//root1 = insertInBST2(root1,d);
		}

		/*printBFS(root);
		printBFS(root1);*/

		/*inorder(root);
		cout << endl;
		inorder(root1);*/

		/*cout <<"Root value in main: " << root << endl;
		cout <<"Root address in main: " << &root << endl;
 		if(root) cout <<"Root data in main: " <<  root->data << endl;
		printRoot(root);
		if(root) cout <<"Root data in main: "<< root->data << endl;
		*/


		/*node *n = serachInBST(root,1);
		if(n){
			cout << "node exists";
		}else{
			cout << "node does not exist";
		}*/


		/*Input 5 1 10 8 11 7 9 -1 
		printBFS(root);	
		root = deleteInBST(root,5);
		printBFS(root);

		root = deleteInBST2(root,10);
		printBFS(root);*/


		// Input 5 3 7 1 6 8 -1
		/*root->right->left->data = 4;
		root->right->right->data = 6;
		printBFS(root);
		if(isValidBST(root)){
			cout << "BST";
		}else{
			cout << "NOT BST";
		}*/


		/*printBFS(root);
		flattenTree(root);
		printBFS(root);*/

		/*printBFS(root);
		root = flattenTreeToDLL(root);
		while(root != NULL){
			cout << root->data << " ";
			root = root->right;
		}*/

		morrisInOrder(root);
		cout << endl;
		morrisPreOrder(root);
	}
	return 0;
}

