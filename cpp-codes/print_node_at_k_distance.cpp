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
void print_down(node * root, int k)
{
	if (root == NULL || k < 0)
	{
		return;
	}
	if (k == 0)
	{
		cout << root->data << " ";
	}
	print_down(root->left, k - 1);
	print_down(root->right, k - 1);
}
int print_node_at_k_distance(node * root , int n , int k)
{
	if (root == NULL)
	{
		return -1;
	}
	if (root->data == n)
	{
		print_down(root, k);
		return 0;
	}
	int left = print_node_at_k_distance(root->left, n, k);
	if (left != -1)
	{
		if (left + 1 == k) cout << root->data << " ";
		else print_down(root->right, k - left - 2);
		return 1 + left;
	}
	int right = print_node_at_k_distance(root->right, n, k);
	if (right != -1)
	{
		if (right + 1 == k) cout << root->data << " ";
		else print_down(root->left, k - left - 2);
		return 1 + right;
	}
	return -1;

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
	//print_level_by_level(root);
	print_node_at_k_distance(root, 7, 5);
	return 0;
}
