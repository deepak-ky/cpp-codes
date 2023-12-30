#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
class node
{
public:

	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		right = NULL;
		left = NULL;
	}

};
node* buildtree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void preorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder_print(root->left);
	preorder_print(root->right);
}
void inorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_print(root->left);
	cout << root->data << " ";

	inorder_print(root->right);
}
void postorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	postorder_print(root->left);
	postorder_print(root->right);
	cout << root->data << " ";

}
void printkthlevel(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (k == 1)
	{
		cout << root->data << " ";
		return;
	}
	printkthlevel(root->left, k - 1);
	printkthlevel(root->right, k - 1);
}
int  height(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return ((max(ls, rs)) + 1);
}
void printalllevel(node * root )
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printkthlevel(root, i);
		cout << endl;
	}
}
void printbfs(node * root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node * f = q.front();
		cout << f->data << ",";
		q.pop();
		if (f->left) {q.push(f->left);}
		if (f->right) {q.push(f->right);}


	}
	return;
}
void linebyline_bfs(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		if (f == NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data << ",";
			q.pop();
			if (f->left) {q.push(f->left);}
			if (f->right) {q.push(f->right);}
		}
	}
}
int count(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + count(root->left) + count(root->right);

}
int sum_of_nodes(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	return (root->data) + sum_of_nodes(root->left) + sum_of_nodes(root->right);

}
int diameter_of_tree(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter_of_tree(root->left);
	int op3 = diameter_of_tree(root->right);
	return max(op1 , max(op3, op2));

}
class Pair
{
public:
	int h;
	int dia;
};
Pair fast_diameter(node * root)
{
	Pair p;
	if (root == NULL)
	{
		p.h = p.dia = 0;
		return p;
	}
	Pair left = fast_diameter(root->left);
	Pair right = fast_diameter(root->right);
	p.h = max((left.h) , (right.h)) + 1;
	p.dia = max((left.h + right.h), max(left.dia, right.dia));
	return p;
}
int replace_sum(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->left == NULL) && (root->right == NULL))
	{
		return root->data;
	}
	int leftsum = replace_sum(root->left);
	int rightsum = replace_sum(root -> right);
	int temp = root->data;
	root->data = leftsum + rightsum;
	return (temp + root->data);
}
class hbpair
{
public:
	int hgt;
	bool isbalanced;
};
hbpair ishieghtbalanced(node * root)
{
	hbpair p;
	if (root == NULL)
	{
		p.hgt = 0;
		p.isbalanced = true;
		return p;
	}
	hbpair left = ishieghtbalanced(root->left);
	hbpair right = ishieghtbalanced(root->right);
	p.hgt =  max(left.hgt, right.hgt) + 1;
	if ((abs(left.hgt - right.hgt) <= 1) && left.isbalanced && right.isbalanced)
	{
		p.isbalanced = true;
	}

	else
	{
		p.isbalanced = false;
	}
	return p;
}
node * buildtreefromarray(int a[], int s, int e)
{
	if (s > e)
	{
		return NULL;
	}
	int mid = (s + e) / 2;
	node * root = new node(a[mid]);
	root->left = buildtreefromarray(a, s, mid - 1);
	root->right = buildtreefromarray(a, mid + 1, e);
	return root;
}
node *createtreefromtravesal(int *in, int *pre, int s, int e)
{
	static int i = 0;
	if (s > e)
	{
		return NULL;
	}
	node * root = new node(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = createtreefromtravesal(in, pre, s, index - 1);
	root->right = createtreefromtravesal(in, pre, index + 1, e);
	return root;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node * root = buildtree();
	// preorder_print(root);
	// cout << endl; inorder_print(root);
	// cout << endl; postorder_print(root);
	// cout << endl; cout << "height : " << height(root);
	// cout << endl; cout << "Third level is :" ; printkthlevel(root, 3);
	// cout << endl; cout << "level order print : \n"; printalllevel(root);
	cout << endl; cout << "bfs print : \n"; printbfs(root);
	cout << endl; cout << "bfs with endl print : \n"; linebyline_bfs(root);
	cout << endl; cout << "the number of nodes are : " << count(root);
	cout << endl; cout << "the sum of all the nodes are : " << sum_of_nodes(root);
	cout << endl; cout << "the diameter_of_tree is : " << diameter_of_tree(root);
	cout << endl; cout << "Calculating use fast diamete  : \n";
	Pair p = fast_diameter(root);
	cout << endl; cout << "fast_diameter heigt: " << p.h;
	cout << endl; cout << "fast_diameter diameter: " << p.dia;
	//replace_sum(root);
	//cout << endl; cout << "after replacing each node with the sum of its child nodes : \n"; linebyline_bfs(root);
	cout << endl; cout << "checking for hieght balanced tree : \n";
	hbpair h = ishieghtbalanced(root);
	if (h.isbalanced)
	{
		cout << "balanced";
	}
	else
	{
		cout << "NOT balanced";
	}
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	node * root1 = buildtreefromarray(a, 0, n - 1);
	cout << endl; cout << "new tree build from array : \n"; linebyline_bfs(root1);
	int n1;
	cin >> n1;
	int in[n1];
	int pre[n1];
	asdf(in, n1);
	asdf(pre, n1);
	node * root2 = createtreefromtravesal(in , pre,  0, n1 - 1);
	cout << endl; cout << "new tree build from inorder and preorder traversal : \n"; linebyline_bfs(root2);

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1







	return 0;
}
