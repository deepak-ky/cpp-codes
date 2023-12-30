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
	node * left;
	node * right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}

};
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
class info
{
public:
	int size_of_tree;
	int max;
	int min;
	int ans;
	bool isBST;
};
info largest_bst(node * root)
{
	if (root == NULL)
	{
		return {0, INT_MIN, INT_MAX, 0, true};
	}
	if ((root->left == NULL) && (root->right == NULL))
	{
		return {1, root->data, root->data, 1, true};
	}
	info left = largest_bst(root->left);
	info right = largest_bst(root->right);
	info result;
	result.size_of_tree = 1 + left.size_of_tree + right.size_of_tree;
	if ( (left.isBST) && (right.isBST) && (left.max < root->data) && (right.min > root->data))
	{
		result.max = max(right.max, max(left.max, root->data));
		result.min = min(left.min, max(right.min, root->data));

		result.ans = result.size_of_tree;
		result.isBST = true;
		return result;
	}
	result.ans = max(left.ans, right.ans);
	result.isBST = false;
	return result;

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
	int in[n1];
	asdf(in, n1);


	node * root = createtreefromtravesal(in, pre, 0, n1 - 1);

	info w = largest_bst(root);
	cout << w.ans << " ";
	return 0;
}