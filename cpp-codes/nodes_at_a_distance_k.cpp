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
vector<int> nodes_at_distance;
void print_node_down(node*root, int k)
{
	if (root == NULL || k < 0)
		return;
	if (k == 0)
	{
		nodes_at_distance.push_back(root->data);
		return;
	}
	print_node_down(root->left, k - 1);
	print_node_down(root->right, k - 1);
}
int print_node_at_distance(node*root, int k, int target)
{

	if (root == NULL)
	{

		return -1;
	}
	else if (root->data == target)
	{
		print_node_down(root, k);
		return 1;
	}

	int l = print_node_at_distance(root->left, k, target);

	if (l != -1)
	{
		if (l == k)
		{
			nodes_at_distance.push_back(root->data);
		}
		else
			print_node_down(root->right, k - l - 1);

		return l + 1;
	}
	int r = print_node_at_distance(root->right, k, target);

	if (r != -1)
	{
		if (r == k)
		{
			nodes_at_distance.push_back(root->data);
		}
		else
			print_node_down(root->left, k - r - 1);

		return r + 1;
	}

	return -1;


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
	test
	{
		nodes_at_distance.clear();
		int target, k;
		cin >> target >> k;
		print_node_at_distance(root, k, target);
		sort(nodes_at_distance.begin(), nodes_at_distance.end());
		for (auto x : nodes_at_distance)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;

}
