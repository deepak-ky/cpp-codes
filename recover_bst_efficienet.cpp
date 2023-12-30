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
		left = NULL;
		right = NULL;
	}
};
node* buildbst()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = buildbst();
	root->right = buildbst();
	return root;
}
void line_by_line(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		if ( f == NULL)
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
			cout << f->data;
			q.pop();
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
	}
}
int idx = 0;
void inorder_print(node * root, int* inorder)
{
	if (root == NULL)
	{
		return;
	}
	inorder_print(root->left, inorder);
	//cout << root->data << " ";
	inorder[idx] = root->data;
	idx++;
	inorder_print(root->right, inorder);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	int inorder[100005];

	node * root = buildbst();
	//line_by_line(root);
	//cout << endl;

	inorder_print(root, inorder);
	//out(inorder, n);
	int first, middle, last;
	first = middle = last = -1;

	for (int i = 1; i < idx; i++)
	{
		if (inorder[i] < inorder[i - 1])
		{
			if (first == -1 && middle == -1)
			{
				first = inorder[i - 1];
				middle = inorder[i];
			}
			else
			{
				last = inorder[i];
			}
		}
	}
	//cout << endl;
	if (last == -1)
	{
		cout << middle << " " << first;
	}
	else
	{
		cout << last << " " << first;
	}
	return 0;
}
