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
string t = "true";
node* buildbst()
{
	int d;
	cin >> d;
	node * root = new node(d);
	string val1, val2;
	cin >> val1;
	if (val1 == t)
	{

		root->left = buildbst();
	}

	cin >> val2;

	if (val2 == t)
	{
		root->right = buildbst();
	}


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

void printkthlevel_left_to_right(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (k == 1)
	{
		cout << root->data << " ";
	}
	printkthlevel_left_to_right(root->left, k - 1);
	printkthlevel_left_to_right(root->right, k - 1);
}
void printkthlevel_right_to_left(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (k == 1)
	{
		cout << root->data << " ";
	}
	printkthlevel_right_to_left(root->right, k - 1);
	printkthlevel_right_to_left(root->left, k - 1);
}

int  height(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return ((max(ls, rs)) + 1);
}
void zigzag_print(node * root )
{
	int h = height(root);
	int flag = 0;
	for (int i = 1; i <= h; i++)
	{
		if (flag == 0)
		{
			printkthlevel_left_to_right(root, i);
			flag = 1;
		}
		else if (flag == 1)
		{
			printkthlevel_right_to_left(root, i);
			flag = 0;
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
	node * root = buildbst();
	zigzag_print(root);
	return 0;
}
