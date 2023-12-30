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
void inorder_print(node * root, vector<int> &inorder)
{
	if (root == NULL)
	{
		return;
	}
	inorder_print(root->left, inorder);
	//cout << root->data << " ";
	inorder.push_back(root->data);
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
	//if they give me a input ki yeh size hain toh utne ka ek array bana loh
	/*int n;
	cin >> n;*/
	vector<int> inorder;
	node * root = buildbst();
	//line_by_line(root);
	//cout << endl;
	// we need to find ki iska inorder traversal kya hain aur usko store karna padega
	inorder_print(root, inorder);
	//auto it = find(inorder.begin(), inorder.end(), 4);
	//cout << it - inorder.begin() << endl;

	//swap(inorder[0], inorder[it - inorder.begin()]);
	int first, middle, last;
	first = middle = last = -1;
	vector<int>:: iterator it;
	vector<int>:: iterator it1;
	for (it = inorder.begin() + 1, it1 = inorder.begin(); it != inorder.end(); it++, it1++)
	{
		if ((*it) < * (it1))
		{
			if (first == -1  && middle == -1)
			{
				//cout << *it << " smaller than : " << *it1 << endl;
				first = *it1;
				middle = *it;
			}
			else
			{
				last = *it;
			}
		}

	}
	if (last == -1)
	{
		cout << first << " " << middle;
	}
	else
	{
		cout << first << " " << last;
	}
	return 0;
}
