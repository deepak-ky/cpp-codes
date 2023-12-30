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
		int n;
		cin >> n;
		int a[n];
		asdf(a, n);
		sort(a, a + n);

		node * root1 = buildtreefromarray(a, 0, n - 1);
		preorder(root1);
		cout << endl;
	}
	return 0;
}
