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
	int d;
	cin >> d;
	node * root = NULL;
	while (d != -1)
	{
		root = insertinbst(root, d);
		cin >> d;
	}
	return root;
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
bool search(node * root, int d)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->data == d)
	{
		return true;
	}
	if (d <= root->data)
	{
		return search(root->left, d);
	}
	else
		return search(root->right, d);
}
node * delete_in_bst(node * root, int d)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (d < root->data)
	{
		root->left = delete_in_bst(root->left, d);
		return root;
	}
	else if (d == root->data)
	{
		if ((root->left == NULL) && (root->right == NULL))
		{
			delete root;
			return NULL;
		}
		if (root->left != NULL && root->right == NULL)
		{
			node * temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == NULL && root->right != NULL)
		{
			node * temp = root->right;
			delete root;
			return temp;
		}
		node * replace = root->right;
		while (replace->left != NULL)
		{
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = delete_in_bst(root->right, replace->data);
		return root;
	}
	else
	{
		root->right = delete_in_bst(root->right, d );
		return root;
	}
}


bool is_BST(node * root, int minV = INT_MIN, int maxV = INT_MAX)
{
	if (root == NULL)
	{
		return true;
	}
	if ( (root->data >= minV && root->data <= maxV)  && is_BST(root->left, minV, root->data) && is_BST(root->right, root->data, maxV))
	{
		return true;
	}
	return false;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node* root = buildbst();
	inorder_print(root);
	// int d;
	// cin >> d;
	// if (search(root, d))
	// {
	// 	cout << "Present";
	// }
	// else
	// 	cout << "Not Present";
	cout << endl;
	linebyline_bfs(root);
	// root = delete_in_bst(root , 5);
	// cout << endl;
	// linebyline_bfs(root);
	cout << endl;
	if (is_BST(root))
	{
		cout << "YES";
	}
	else cout << "Not a Bst";
	return 0;
}
