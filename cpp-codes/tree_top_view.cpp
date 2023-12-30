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
node *buildtree(vector<int> v, int  idx, int  n)
{

	if (idx >= n ||  v[idx] == -1)
	{
		return NULL;
	}
	node * root = new node(v[idx]);
	root -> left = buildtree(v, ((idx) * 2 + 1), n);
	root -> right = buildtree(v, ((idx) * 2 + 2), n);
	return root;
}

node* build()
{	queue<node*> q;
	int c = 0;
	int d;
	cin >> d;
	node* root = new node(d);
	node* cur = root;
	q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		cin >> d;
		if (d != -1)
		{
			if (c == 0)
			{	c++;
				cur->left = new node(d);
				q.push(cur->left);
			}

			else if (c == 1)
			{
				c = 0;
				cur->right = new node(d);
				q.push(cur->right);
				q.pop();
			}

		}

		else if (d == -1)
		{
			if (c == 0)
			{
				c++;
				cur->left = NULL;
			}
			else if (c == 1)
			{
				c = 0;
				cur->right = NULL;
				q.pop();

			}

		}
	}
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
void insert_top_element_in_map(node * root, int h, int hd, map<int, pair<int, int> > &mp)
{
	if (root == NULL) return;
	if (mp.find(hd) == mp.end())
	{
		pair<int, int> w;
		w.first = root->data;
		w.second = h;
		mp[hd] = w;
	}
	else
	{
		if (h < mp[hd].second)
		{
			mp[hd].first = root->data;
			mp[hd].second = h;
		}
	}
	insert_top_element_in_map(root->left, h + 1, hd - 1, mp);
	insert_top_element_in_map(root->right, h + 1, hd + 1, mp);
}
void print_top_view(node * root)
{
	map<int, pair<int, int> > mp;
	insert_top_element_in_map(root, 0, 0, mp);
	for (auto x : mp)
	{
		pair < int, int > p = x.second;
		cout << p.first << " ";
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
	node * root = build();
	print_top_view(root);
	return 0;
}
