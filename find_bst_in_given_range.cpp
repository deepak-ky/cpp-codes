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
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right ;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
void preorder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
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
node * insertinbst(node * root, int d)
{
	if (root == NULL)
	{
		return new node(d);
	}
	if (d <= root->data)
	{
		root->left = insertinbst(root->left, d);
	}
	else
	{
		root->right = insertinbst(root->right, d);
	}
	return root;

}
node * buildbst()
{
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	int val = 0;
	node * root = NULL;
	while (val < n)
	{
		root = insertinbst(root, a[val]);
		val++;
	}
	return root;
}
vector<int> v;
void print_in_range(node * root, int k1, int k2)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data >= k1 && root->data <= k2)
	{
		v.push_back(root->data);
	}
	print_in_range(root->left, k1, k2);
	print_in_range(root->right, k1, k2);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		node * root = buildbst();
		int k1, k2;
		cin >> k1 >> k2;
		print_in_range(root, k1, k2);
		sort(v.begin(), v.end());
		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;

	}
	return 0;
}
