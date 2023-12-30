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

vector<int> vec_right;
int max_level = -1;
void right_view(node * root, int level)
{
	if (root == NULL)
	{
		return;
	}
	if (level > max_level)
	{
		max_level = level;
		vec_right.push_back(root->data);
	}
	right_view(root->right, level + 1);
	right_view(root->left, level + 1);
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
	right_view(root, 0);
	for (auto x : vec_right)
	{
		cout << x << " ";
	}
	return 0;
}
