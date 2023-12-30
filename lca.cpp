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
node * build_bst()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = build_bst();
	root->right = build_bst();
	return root;
}
void print_level_by_level(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		q.pop();
		if (f)
		{
			cout << f->data << " ";
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else if (f == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
	}
}
node* l_c_a(node *root , int n1 , int n2)
{
	//base case
	if (root == NULL) return NULL;
	if (root->data == n1)   return root;
	if (root->data == n2)   return root;
	//rec case
	node* left = l_c_a(root->left , n1 , n2);
	node* right = l_c_a(root->right, n1 , n2);


	if (left != NULL && right != NULL)
	{
		return root;
	}
	if (left == NULL && right == NULL)
	{
		return NULL;
	}
	if (left != NULL && right == NULL)
	{
		return left;
	}
	if (left == NULL && right != NULL)
	{
		return right;
	}

}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node * root = NULL;
	root = build_bst();
	print_level_by_level(root);
	node * m = l_c_a(root, , 7, 8);
	cout << m->data << endl;
	return 0;
}
