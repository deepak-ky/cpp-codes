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
node * build_generic_tree()
{
	int d;
	cin >> d;
	int num_of_children;
	cin >> num_of_children;
	node * root = new node(d);
	if (num_of_children == 2)
	{
		root->left = build_generic_tree();
		root->right = build_generic_tree();
		return root;

	}
	else if (num_of_children == 1)
	{
		root->left = build_generic_tree();
		return root;

	}
	else
		return root;

}
int sum = 0;
void find_sum_of_elements_at_k(node * root , int k)
{
	if (root == NULL)
	{
		return;
	}
	if (k == 0)
	{
		sum = sum + root->data;
		return;
	}
	find_sum_of_elements_at_k(root->left, k - 1);
	find_sum_of_elements_at_k(root->right, k - 1);
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



	node * root1 = build_generic_tree();
	int k;
	cin >> k;
	find_sum_of_elements_at_k(root1, k);
	cout << sum;

	return 0;
}
