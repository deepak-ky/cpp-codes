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
	node*right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
node * createtree_from_in_and_pre(int pre[], int in[], int s, int e)
{
	static int i = 0;
	if (s > e)
	{
		return NULL;
	}
	node * root = new node(pre[i]);
	int index_in_in;
	for (int k = s; k <= e; k++)
	{
		if (in[k] == pre[i])
		{
			index_in_in = k;
			break;
		}
	} i++;
	root->left = createtree_from_in_and_pre(pre, in, s, index_in_in - 1);
	root->right = createtree_from_in_and_pre(pre, in, index_in_in + 1, e);
	return root;

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
void updated_preorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left != NULL && root->right != NULL)
	{
		cout << root->left->data << " => " << root->data << " <= " << root->right->data << endl;
		updated_preorder_print(root->left);
		updated_preorder_print(root->right);
	}
	else if (root->left != NULL && root->right == NULL)
	{
		cout << root->left->data << " => " << root->data << " <= END" << endl;
		updated_preorder_print(root->left);
	}
	else if (root->left == NULL && root->right != NULL)
	{
		cout << "END => " << root->data << " <= " << root->right->data << endl;
		updated_preorder_print(root->right);
	}
	else
	{
		cout << "END => " << root->data << " <= END" << endl;
	}
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n1;
	cin >> n1;
	int pre[n1];
	asdf(pre, n1);
	int n;
	cin >> n;
	int in[n];
	asdf(in, n);
	node * root = createtree_from_in_and_pre(pre, in, 0, n - 1);
	updated_preorder_print(root);
	return 0;
}
